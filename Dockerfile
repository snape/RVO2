# syntax=docker.io/docker/dockerfile:1

#
# Dockerfile
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

FROM ubuntu:latest
LABEL org.opencontainers.image.authors="Jur van den Berg, Stephen J. Guy, Jamie Snape, Ming C. Lin, Dinesh Manocha"
LABEL org.opencontainers.image.base.name="docker.io/library/ubuntu:latest"
LABEL org.opencontainers.image.description="Optimal Reciprocal Collision Avoidance"
LABEL org.opencontainers.image.licenses="Apache-2.0"
LABEL org.opencontainers.image.source="https://github.com/snape/RVO2/"
LABEL org.opencontainers.image.title="RVO2 Library"
LABEL org.opencontainers.image.url="https://gamma.cs.unc.edu/RVO2/"
LABEL org.opencontainers.image.vendor="University of North Carolina at Chapel Hill"
ENV LANG C.UTF-8
ENV LOGNAME root
ENV SHELL /bin/bash
ENV USER root
RUN export DEBIAN_FRONTEND=noninteractive \
  && apt-get update -qq \
  && apt-get install --no-install-recommends -o Dpkg::Use-Pty=0 -qy \
    ca-certificates \
    clang \
    clang-tidy \
    cmake \
    cmake-format \
    cppcheck \
    cpplint \
    dirmngr \
    doxygen \
    dpkg-dev \
    file \
    g++ \
    gdb \
    git \
    graphviz \
    iwyu \
    jsonlint \
    lldb \
    make \
    markdownlint \
    nano \
    netbase \
    ninja-build \
    npm \
    pkgconf \
    python3 \
    reuse \
    strace \
    valgrind \
    yamllint \
  && rm -rf /var/lib/apt/lists/* \
  && npm install -g \
    @bazel/bazelisk \
    @bazel/buildifier
