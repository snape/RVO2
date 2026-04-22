# -*- mode: meson; -*-
# vi: set ft=meson:

#
# meson.build
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

project(
    'RVO',
    'cpp',
    version: '2.0.3',
    license: 'Apache-2.0',
    license_files: ['LICENSE'],
    default_options: [
        'b_lto=false',
        'b_pie=true',
        'b_staticpic=true',
        'buildtype=release',
        'cpp_std=c++98',
        'warning_level=1',
    ],
    meson_version: '>=1.1.0',
)

cpp_compiler = meson.get_compiler('cpp')
host_os = host_machine.system()
is_msvc = cpp_compiler.get_id() == 'msvc'

# ---- Warning flags -----------------------------------------------------------

warning_flags = []
if is_msvc
    # Keep Meson's modest cross-platform warning baseline and raise only MSVC to
    # /W4. Using warning_level=3 would also change GCC/Clang behavior.
    warning_flags += cpp_compiler.get_supported_arguments('/W4')
else
    warning_flags += cpp_compiler.get_supported_arguments(
        '-Wformat-security',
        '-Werror=format-security',
    )
endif
add_project_arguments(warning_flags, language: 'cpp')

# ---- Hardening ---------------------------------------------------------------

hardening_compile_flags = []
hardening_link_flags = []
optimized_build = not get_option('debug') and get_option('optimization') != '0'

if is_msvc
    hardening_compile_flags += cpp_compiler.get_supported_arguments('/GS')

    if cpp_compiler.has_argument('/guard:cf') and cpp_compiler.has_link_argument('/DYNAMICBASE') and cpp_compiler.has_link_argument('/GUARD:CF')
        hardening_compile_flags += ['/guard:cf']
        hardening_link_flags += ['/DYNAMICBASE', '/GUARD:CF']
    endif

    hardening_link_flags += cpp_compiler.get_supported_link_arguments('/NXCOMPAT')
else
    if optimized_build
        hardening_compile_flags += cpp_compiler.get_supported_arguments('-D_FORTIFY_SOURCE=2')
    endif

    hardening_compile_flags += cpp_compiler.get_supported_arguments(
        '-fcf-protection',
        '-fno-common',
        '-fstack-clash-protection',
    )

    if cpp_compiler.has_argument('-fstack-protector-strong')
        hardening_compile_flags += ['-fstack-protector-strong']
    elif cpp_compiler.has_argument('-fstack-protector')
        hardening_compile_flags += ['-fstack-protector']
    endif

    if optimized_build
        if cpp_compiler.has_argument('-fsanitize=safe-stack') and cpp_compiler.has_link_argument('-fsanitize=safe-stack')
            hardening_compile_flags += ['-fsanitize=safe-stack']
            hardening_link_flags += ['-fsanitize=safe-stack']
        endif
    endif

    if optimized_build
        hardening_link_flags += cpp_compiler.get_supported_link_arguments(
            '-Wl,-Bsymbolic-functions',
        )
    endif

    hardening_link_flags += cpp_compiler.get_supported_link_arguments(
        '-Wl,-z,defs',
        '-Wl,-z,noexecheap',
        '-Wl,-z,noexecstack',
        '-Wl,-z,now',
        '-Wl,-z,relro',
        '-Wl,-z,separate-code',
    )
endif

add_project_arguments(hardening_compile_flags, language: 'cpp')
add_project_link_arguments(hardening_link_flags, language: 'cpp')

if not is_msvc and cpp_compiler.has_link_argument('-Wl,--as-needed')
    add_project_link_arguments('-Wl,--as-needed', language: 'cpp')
endif

# ---- Optional: OpenMP --------------------------------------------------------

openmp_opt = get_option('openmp')
openmp_dep = dependency('openmp', required: openmp_opt, disabler: true)
openmp_deps = openmp_dep.found() ? [openmp_dep] : []

# ---- Windows library policy --------------------------------------------------
#
if host_os == 'windows' and get_option('default_library') == 'shared'
    error(
        'On Windows, configure Meson with -Ddefault_library=static (or both) to match the project default.',
    )
endif

examples_opt = get_option('examples')
examples_enabled = not (examples_opt.disabled() or (examples_opt.auto() and meson.is_subproject()))

# ---- Subdirectories ----------------------------------------------------------

subdir('src')
subdir('examples')

# ---- Installation: license ---------------------------------------------------

if not meson.is_subproject()
    license_dir = get_option('licensedir')
    if license_dir != ''
        install_data(
            'LICENSE',
            install_dir: license_dir / meson.project_name(),
            install_tag: 'devel',
        )
    endif
endif

summary(
    {
        'default_library': get_option('default_library'),
        'examples': examples_enabled,
        'hardening': (hardening_compile_flags.length() + hardening_link_flags.length()) > 0,
        'install': not meson.is_subproject(),
        'openmp': openmp_dep.found(),
        'subproject': meson.is_subproject(),
        'werror': get_option('werror'),
    },
    section: 'Configuration',
)
