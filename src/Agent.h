/*
 * Agent.h
 * RVO2 Library
 *
 * SPDX-FileCopyrightText: 2008 University of North Carolina at Chapel Hill
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Please send all bug reports to <geom@cs.unc.edu>.
 *
 * The authors may be contacted via:
 *
 * Jur van den Berg, Stephen J. Guy, Jamie Snape, Ming C. Lin, Dinesh Manocha
 * Dept. of Computer Science
 * 201 S. Columbia St.
 * Frederick P. Brooks, Jr. Computer Science Bldg.
 * Chapel Hill, N.C. 27599-3175
 * United States of America
 *
 * <https://gamma.cs.unc.edu/RVO2/>
 */

#ifndef RVO_AGENT_H_
#define RVO_AGENT_H_

/**
 * \file       Agent.h
 * \brief      Contains the Agent class.
 */

#include <cstddef>
#include <utility>
#include <vector>

#include "Line.h"
#include "Vector2.h"

namespace RVO {
class Obstacle;
class RVOSimulator;

/**
 * \brief      Defines an agent in the simulation.
 */
class Agent {
 private:
  /**
   * \brief      Constructs an agent instance.
   * \param      sim             The simulator instance.
   */
  explicit Agent(RVOSimulator *sim);

  /**
   * \brief      Computes the neighbors of this agent.
   */
  void computeNeighbors();

  /**
   * \brief      Computes the new velocity of this agent.
   */
  void computeNewVelocity();

  /**
   * \brief      Inserts an agent neighbor into the set of neighbors of
   *             this agent.
   * \param      agent           A pointer to the agent to be inserted.
   * \param      rangeSq         The squared range around this agent.
   */
  void insertAgentNeighbor(const Agent *agent,
                           float &rangeSq); /* NOLINT(runtime/references) */

  /**
   * \brief      Inserts a static obstacle neighbor into the set of neighbors
   *             of this agent.
   * \param      obstacle        The number of the static obstacle to be
   *                             inserted.
   * \param      rangeSq         The squared range around this agent.
   */
  void insertObstacleNeighbor(const Obstacle *obstacle, float rangeSq);

  /**
   * \brief      Updates the two-dimensional position and two-dimensional
   *             velocity of this agent.
   */
  void update();

  std::vector<std::pair<float, const Agent *> > agentNeighbors_;
  size_t maxNeighbors_;
  float maxSpeed_;
  float neighborDist_;
  Vector2 newVelocity_;
  std::vector<std::pair<float, const Obstacle *> > obstacleNeighbors_;
  std::vector<Line> orcaLines_;
  Vector2 position_;
  Vector2 prefVelocity_;
  float radius_;
  RVOSimulator *sim_;
  float timeHorizon_;
  float timeHorizonObst_;
  Vector2 velocity_;

  size_t id_;

  friend class KdTree;
  friend class RVOSimulator;
};
}  // namespace RVO

#endif /* RVO_AGENT_H_ */
