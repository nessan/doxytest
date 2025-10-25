#!/usr/bin/env python3
"""
Test the comment style extraction functionality.

SPDX-FileCopyrightText:  2025 Nessan Fitzmaurice <nzznfitz+gh@icloud.com>
SPDX-License-Identifier: MIT
"""
import os
import tempfile
import textwrap
import unittest
from pathlib import Path

import sys

PROJECT_ROOT = Path(__file__).resolve().parents[1]
if str(PROJECT_ROOT) not in sys.path:
    sys.path.insert(0, str(PROJECT_ROOT))

from doxytest import extract_code_blocks


class CommentStyleExtractionTest(unittest.TestCase):
    def test_supported_comment_styles(self):
        content = textwrap.dedent(
            """\
            /// ```
            /// int triple() { return 3; }
            /// ```

            //! ```cpp
            //! int bang() { return 4; }
            //! ```

            /*!
             * ```doxy
             * auto setup_value = 42;
             * ```
             */

            /**
             * ```cpp
             * int block() { return 5; }
             * ```
             */

            /*
             * ```cpp
             * int plain_star() { return 6; }
             * ```
             */

            /// ```rs
            /// fn ignored() {}
            /// ```

            // ```cpp
            // int double_slash() { return 7; }
            // ```

            ```cpp
            int markdown() { return 8; }
            ```
            """
        )

        with tempfile.NamedTemporaryFile("w", suffix=".h", delete=False) as tmp:
            tmp.write(content)
            tmp_path = Path(tmp.name)

        try:
            blocks = extract_code_blocks(tmp_path)
        finally:
            os.unlink(tmp_path)

        kinds = [block["kind"] for block in blocks]
        self.assertEqual(
            kinds,
            ["test", "test", "setup", "test", "test", "test", "test"],
        )

        codes = [block["code"] for block in blocks]
        self.assertEqual(
            codes,
            [
                "int triple() { return 3; }",
                "int bang() { return 4; }",
                "auto setup_value = 42;",
                "int block() { return 5; }",
                "int plain_star() { return 6; }",
                "int double_slash() { return 7; }",
                "int markdown() { return 8; }",
            ],
        )


if __name__ == "__main__":
    unittest.main()
