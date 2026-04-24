# -*- mode: meson; -*-
# vi: set ft=meson:

#
# examples/meson.build
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

examples_opt = get_option('examples')
if examples_opt.disabled() or (examples_opt.auto() and meson.is_subproject())
    subdir_done()
endif

example_args = [
    '-DRVO_OUTPUT_TIME_AND_POSITIONS=0',
    '-DRVO_SEED_RANDOM_NUMBER_GENERATOR=0',
]

foreach name : ['Blocks', 'Circle', 'Roadmap']
    exe = executable(
        name,
        sources: name + '.cc',
        cpp_args: example_args,
        dependencies: dep_rvo,
        install: false,
    )

    test(
        name,
        exe,
        suite: 'examples',
        timeout: 900,
    )
endforeach
