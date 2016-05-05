#
# examples/CMakeLists.txt
# RVO2 Library
#
# Copyright 2008 University of North Carolina at Chapel Hill
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
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
# <http://gamma.cs.unc.edu/RVO2/>
#

include_directories(${RVO_SOURCE_DIR}/src)

add_executable(Blocks Blocks.cpp)
target_link_libraries(Blocks RVO)
add_test(Blocks Blocks)

add_executable(Circle Circle.cpp)
target_link_libraries(Circle RVO)
add_test(Circle Circle)

add_executable(Roadmap Roadmap.cpp)
target_link_libraries(Roadmap RVO)
add_test(Roadmap Roadmap)

install(TARGETS Blocks Circle Roadmap DESTINATION bin)
