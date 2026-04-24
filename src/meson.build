# -*- mode: meson; -*-
# vi: set ft=meson:

#
# src/meson.build
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

sources = files(
    'Agent.cc',
    'KdTree.cc',
    'Line.cc',
    'Obstacle.cc',
    'RVOSimulator.cc',
    'Vector2.cc',
)

public_headers = files(
    'Export.h',
    'Line.h',
    'RVO.h',
    'RVOSimulator.h',
    'Vector2.h',
)

inc = include_directories('.')

# ---- ABI export / visibility defines ----------------------------------------
#
# On Windows, the shared library must be compiled with -DRVO_EXPORTS so that
# RVO_EXPORT expands to __declspec(dllexport).  Static builds on any platform
# need -DRVO_STATIC_DEFINE to suppress the visibility attribute entirely.
# On non-Windows shared builds, gnu_symbol_visibility (below) handles it.

compile_args = []
dep_compile_args = []
default_library = get_option('default_library')

# Keep inline-visibility tightening on the library target only: this is part of
# the exported ABI/symbol policy for RVO itself, not a project-wide policy that
# needs to affect example executables.
compile_args += cpp_compiler.get_supported_arguments('-fvisibility-inlines-hidden')

if host_os == 'windows'
    compile_args += ['-DNOMINMAX']
    dep_compile_args += ['-DNOMINMAX']

    if default_library in ['shared', 'both']
        compile_args += ['-DRVO_EXPORTS']
        if default_library == 'both'
            dep_compile_args += ['-DRVO_STATIC_DEFINE']
        endif
    else
        compile_args += ['-DRVO_STATIC_DEFINE']
        dep_compile_args += ['-DRVO_STATIC_DEFINE']
    endif
else
    if default_library == 'static'
        compile_args += ['-DRVO_STATIC_DEFINE']
        dep_compile_args += ['-DRVO_STATIC_DEFINE']
    endif
endif

# ---- Library target ----------------------------------------------------------

lib_rvo = library(
    'RVO',
    sources: sources,
    include_directories: inc,
    cpp_args: compile_args,
    gnu_symbol_visibility: 'hidden',
    dependencies: openmp_deps,
    version: meson.project_version(),
    soversion: meson.project_version().split('.')[0],
    install: not meson.is_subproject(),
)

# ---- Dependency object for in-tree consumers (examples, tests) ---------------

dep_rvo = declare_dependency(
    link_with: lib_rvo,
    include_directories: inc,
    compile_args: dep_compile_args,
    dependencies: openmp_deps,
)

meson.override_dependency('rvo', dep_rvo)

if not meson.is_subproject()
    install_headers(
        public_headers,
        subdir: 'RVO',
    )

    pkgconfig = import('pkgconfig')
    pkgconfig.generate(
        lib_rvo,
        name: 'RVO',
        description: 'Optimal Reciprocal Collision Avoidance',
        url: 'https://gamma.cs.unc.edu/RVO2/',
        version: meson.project_version(),
        filebase: 'RVO',
        subdirs: 'RVO',
        extra_cflags: dep_compile_args,
    )
endif
