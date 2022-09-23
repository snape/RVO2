/*
 * Definitions.h
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

#ifndef RVO_DEFINITIONS_H_
#define RVO_DEFINITIONS_H_

/**
 * @file  Definitions.h
 * @brief Declares and define functions used in multiple classes.
 */

namespace RVO {
class Vector2;

/**
 * @brief     Computes the squared distance from a line segment with the
 *            specified endpoints to a specified point.
 * @param[in] a The first endpoint of the line segment.
 * @param[in] b The second endpoint of the line segment.
 * @param[in] c The point to which the squared distance is to be calculated.
 * @return    The squared distance from the line segment to the point.
 */
float distSqPointLineSegment(const Vector2 &a, const Vector2 &b,
                             const Vector2 &c);

/**
 * @brief     Computes the square of a float.
 * @param[in] scalar The float to be squared.
 * @return    The square of the float.
 */
inline float sqr(float scalar) { return scalar * scalar; }
} /* namespace RVO */

#endif /* RVO_DEFINITIONS_H_ */
