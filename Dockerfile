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

FROM ubuntu:24.04
ARG TARGETARCH
LABEL org.opencontainers.image.authors="Jur van den Berg, Stephen J. Guy, Jamie Snape, Ming C. Lin, Dinesh Manocha"
LABEL org.opencontainers.image.base.name="docker.io/library/ubuntu:latest"
LABEL org.opencontainers.image.description="Optimal Reciprocal Collision Avoidance"
LABEL org.opencontainers.image.licenses="Apache-2.0"
LABEL org.opencontainers.image.source="https://github.com/snape/RVO2/"
LABEL org.opencontainers.image.title="RVO2 Library"
LABEL org.opencontainers.image.url="https://gamma.cs.unc.edu/RVO2/"
LABEL org.opencontainers.image.vendor="University of North Carolina at Chapel Hill"
LABEL org.opencontainers.image.version="2.0.3"
ENV LANG=C.UTF-8
ENV LOGNAME=root
ENV USER=root
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
    gnupg \
    graphviz \
    iwyu \
    jsonlint \
    lcov \
    lldb \
    make \
    markdownlint \
    nano \
    netbase \
    ninja-build \
    openssh-client \
    pkgconf \
    python3 \
    python3-click \
    python3-dateutil \
    python3-docopt \
    python3-jsonschema \
    python3-pip \
    python3-pykwalify \
    python3-requests \
    python3-ruamel.yaml \
    python3-venv \
    reuse \
    strace \
    sudo \
    valgrind \
    yamllint \
  && rm -rf /var/lib/apt/lists/* \
  && wget -q https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-${TARGETARCH:-amd64}.deb \
  && dpkg -i bazelisk-${TARGETARCH:-amd64}.deb \
  && rm -rf bazelisk-${TARGETARCH:-amd64}.deb \
  && wget -qO /usr/local/bin/buildifier \
    https://github.com/bazelbuild/buildtools/releases/latest/download/buildifier-linux-${TARGETARCH:-amd64} \
  && wget -qO /usr/local/bin/buildozer \
    https://github.com/bazelbuild/buildtools/releases/latest/download/buildozer-linux-${TARGETARCH:-amd64} \
  && chmod +x \
    /usr/local/bin/buildifier \
    /usr/local/bin/buildozer \
  && python3 -m venv --system-site-packages /home/ubuntu/.venv \
  && . /home/ubuntu/.venv/bin/activate \
  && pip install --no-cache-dir -qq \
    cffconvert \
  && echo "ubuntu ALL=(root) NOPASSWD:ALL" > /etc/sudoers.d/ubuntu \
  && chmod 0440 /etc/sudoers.d/ubuntu
ENV LOGNAME=ubuntu
ENV PATH="/home/ubuntu/.venv/bin:${PATH}"
ENV SHELL=/bin/bash
ENV USER=ubuntu
ENV VIRTUAL_ENV=/home/ubuntu/.venv
USER ubuntu
WORKDIR /workspace
