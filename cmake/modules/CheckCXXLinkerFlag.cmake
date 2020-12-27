#
# CheckCXXLinkerFlag.cmake
# RVO2 Library
#
# Copyright 2008 University of North Carolina at Chapel Hill
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

#.rst:
#
# CheckCXXLinkerFlag
# ------------------
#
# Check whether the CXX compiler supports a given link flag.
#
# .. command:: check_cxx linker_flag
#
#   .. code-block:: cmake
#
#     check_cxx_linker_flag(<flag> <var>)
#
# Check that the link flag ``<flag>`` is accepted by the CXX compiler without a
# diagnostic or error message. Stores the result in an internal cache entry
# named ``<var>``.
#
# This command temporarily sets either the ``CMAKE_REQUIRED_LIBRARIES`` or`
# ``CMAKE_REQUIRED_LINK_OPTIONS`` variable depending on ``CMAKE_VERSION`` and
# calls the ``check_cxx_source_compiles`` command from the
# ``CheckCXXSourceCompiles`` module.
#
# A positive result from this check indicates only that the CXX compiler did not
# issue a diagnostic or error message when given the link flag. Whether the flag
# has any effect or even a specific one is beyond the scope of this module.
#
# .. note::
#   Since the ``try_compile`` command forwards flags from variables like
#   ``CMAKE_CXX_FLAGS``, unknown flags in such variables may cause a false
#   negative for this check.

include_guard(GLOBAL)

include(CMakeCheckCompilerFlagCommonPatterns)

# cmake-lint: disable=C0111
function(check_cxx_linker_flag _FLAG _VAR)
  if(MSVC)
    _check_cxx_linker_flag(/WX HRVO_LINKER_SUPPORTS_WX)

    if(HRVO_LINKER_SUPPORTS_WX)
      set(_FATAL_WARNINGS_FLAG /WX)
    else()
      set(_FATAL_WARNINGS_FLAG)
    endif()
  else()
    _check_cxx_linker_flag(-Wl,--fatal-warnings
      HRVO_LINKER_SUPPORTS__FATAL_WARNINGS)

    if(HRVO_LINKER_SUPPORTS__FATAL_WARNINGS)
      set(_FATAL_WARNINGS_FLAG -Wl,--fatal-warnings)
    else()
      _check_cxx_linker_flag(-Wl,-fatal_warnings
        HRVO_LINKER_SUPPORTS_FATAL_WARNINGS)

      if(HRVO_LINKER_SUPPORTS_FATAL_WARNINGS)
        set(_FATAL_WARNINGS_FLAG -Wl,-fatal_warnings)
      else()
        set(_FATAL_WARNINGS_FLAG)
      endif()
    endif()
  endif()

  _check_cxx_linker_flag("${_FLAG}" ${_VAR} "${_FATAL_WARNINGS_FLAG}")

  set(${_VAR} "${${_VAR}}" PARENT_SCOPE)
endfunction()

# cmake-lint: disable=C0111
function(_check_cxx_linker_flag _FLAG _VAR)
  if(ARGC GREATER 2)
    list(INSERT _FLAG 0 "${ARGV2}")
  endif()

  if(CMAKE_VERSION VERSION_LESS 3.14)
    # cmake-lint: disable=C0103
    set(CMAKE_REQUIRED_LIBRARIES "${_FLAG}")
  else()
    # cmake-lint: disable=C0103
    set(CMAKE_REQUIRED_LINK_OPTIONS "${_FLAG}")
  endif()

  if(NOT WIN32)
    set(_LC_VARS LANG LC_ALL LC_MESSAGES)
    foreach(_LC_VAR IN LISTS _LC_VARS)
      set(_SAVED_ENV_${_LC_VAR} "$ENV{${_LC_VAR}}")
      # cmake-lint: disable=C0103
      set(ENV{${_LC_VAR}} C)
    endforeach()
  endif()

  check_compiler_flag_common_patterns(_COMMON_PATTERNS)

  include(CheckCXXSourceCompiles)

  check_cxx_source_compiles("int main() { return 0; }" ${_VAR}
    ${_COMMON_PATTERNS})

  if(NOT WIN32)
    foreach(_LC_VAR IN LISTS _LC_VARS)
      # cmake-lint: disable=C0103
      set(ENV{${_LC_VAR}} ${_SAVED_ENV_${_LC_VAR}})
    endforeach()
  endif()

  set(${_VAR} "${${_VAR}}" PARENT_SCOPE)
endfunction()
