#
# cppcheck-to-sarif.py
# RVO2 Library
#
# SPDX-FileCopyrightText: 2008 University of North Carolina at Chapel Hill
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Please send all bug reports to <geom@cs.unc.edu>.
#
# The authors may be contacted via:
#
# Jur van den Berg, Stephen J. Guy, Jamie Snape, Ming C. Lin, Dinesh Manocha
# Dept. of Computer Science
# 201 S. Columbia St.
# Frederick P. Brooks, Jr. Computer Science Bldg.
# Chapel Hill, N.C. 27599-3175
# United States of America
#
# <https://gamma.cs.unc.edu/RVO2/>
#
"""Convert cppcheck XML output to SARIF 2.1.0."""

import json
import sys
import xml.etree.ElementTree as ET

LEVEL = {
    "error": "error",
    "warning": "warning",
    "style": "note",
    "performance": "note",
    "portability": "note",
    "information": "none",
}


def main():
    tree = ET.parse(sys.argv[1])
    rules, results = {}, []

    for error in tree.findall(".//error"):
        rid = error.get("id", "unknown")
        sev = error.get("severity", "warning")
        msg = error.get("msg", "")
        rules.setdefault(
            rid,
            {
                "id": rid,
                "shortDescription": {"text": rid},
                "defaultConfiguration": {"level": LEVEL.get(sev, "warning")},
            },
        )
        for loc in error.findall("location"):
            f = loc.get("file", "")
            if not f:
                continue
            results.append(
                {
                    "ruleId": rid,
                    "level": LEVEL.get(sev, "warning"),
                    "message": {"text": msg},
                    "locations": [
                        {
                            "physicalLocation": {
                                "artifactLocation": {
                                    "uri": f,
                                    "uriBaseId": "%SRCROOT%",
                                },
                                "region": {
                                    "startLine": max(1, int(loc.get("line") or 1)),
                                    "startColumn": max(1, int(loc.get("column") or 1)),
                                },
                            }
                        }
                    ],
                }
            )

    print(
        json.dumps(
            {
                "$schema": "https://raw.githubusercontent.com/oasis-tcs/sarif-spec/master/"
                "Schemata/sarif-schema-2.1.0.json",
                "version": "2.1.0",
                "runs": [
                    {
                        "tool": {
                            "driver": {
                                "name": "cppcheck",
                                "informationUri": "https://cppcheck.sourceforge.io",
                                "rules": list(rules.values()),
                            }
                        },
                        "results": results,
                    }
                ],
            },
            indent=2,
        )
    )


if __name__ == "__main__":
    main()
