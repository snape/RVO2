Optimal Reciprocal Collision Avoidance
======================================

<https://gamma.cs.unc.edu/RVO2/>

We present a formal approach to reciprocal collision avoidance, where multiple
independent mobile robots or agents need to avoid collisions with each other
without communication among agents while moving in a common workspace. Our
formulation, optimal reciprocal collision avoidance (ORCA), provides sufficient
conditions for collision-free motion by letting each agent take half of the
responsibility of avoiding pairwise collisions. Selecting the optimal action for
each agent is reduced to solving a low-dimensional linear program, and we prove
that the resulting motions are smooth. We test our optimal reciprocal collision
avoidance approach on several dense and complex simulation scenarios workspaces
involving thousands of agents, and compute collision-free actions for all of
them in only a few milliseconds.

RVO2 Library is an open-source C++98 implementation of our algorithm in two
dimensions. It has a simple API for third-party applications. The user specifies
static obstacles, agents, and the preferred velocities of the agents. The
simulation is performed step-by-step via a simple call to the library. The
simulation is fully accessible and manipulable during runtime. The library
exploits multiple processors if they are available using OpenMP for efficient
parallelization of the simulation.

![Build Status](https://github.com/snape/RVO2/workflows/ci/badge.svg?branch=main)
[![Build Status](https://circleci.com/gh/snape/RVO2/tree/main.svg?style=svg)](https://circleci.com/gh/snape/RVO2/?branch=main)

Copyright 2008 University of North Carolina at Chapel Hill

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

&nbsp;&nbsp;<https://www.apache.org/licenses/LICENSE-2.0>

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

Please send all bug reports to [geom@cs.unc.edu](mailto:geom@cs.unc.edu).

The authors may be contacted via:

Jur van den Berg, Stephen J. Guy, Jamie Snape, Ming C. Lin, and Dinesh Manocha  
Dept. of Computer Science  
201 S. Columbia St.  
Frederick P. Brooks, Jr. Computer Science Bldg.  
Chapel Hill, N.C. 27599-3175  
United States of America
