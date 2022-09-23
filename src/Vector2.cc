/*
 * Vector2.cpp
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

#include "Vector2.h"

#include <cmath>
#include <ostream>

namespace RVO {
const float RVO_EPSILON = 0.00001F;

Vector2::Vector2() : x_(0.0F), y_(0.0F) {}

Vector2::Vector2(float x, float y) : x_(x), y_(y) {}

Vector2 Vector2::operator-() const { return Vector2(-x_, -y_); }

float Vector2::operator*(const Vector2 &vector) const {
  return x_ * vector.x() + y_ * vector.y();
}

Vector2 Vector2::operator*(float s) const { return Vector2(x_ * s, y_ * s); }

Vector2 Vector2::operator/(float s) const {
  const float invS = 1.0F / s;

  return Vector2(x_ * invS, y_ * invS);
}

Vector2 Vector2::operator+(const Vector2 &vector) const {
  return Vector2(x_ + vector.x(), y_ + vector.y());
}

Vector2 Vector2::operator-(const Vector2 &vector) const {
  return Vector2(x_ - vector.x(), y_ - vector.y());
}

bool Vector2::operator==(const Vector2 &vector) const {
  return x_ == vector.x() && y_ == vector.y();
}

bool Vector2::operator!=(const Vector2 &vector) const {
  return x_ != vector.x() || y_ != vector.y();
}

Vector2 &Vector2::operator*=(float s) {
  x_ *= s;
  y_ *= s;

  return *this;
}

Vector2 &Vector2::operator/=(float s) {
  const float invS = 1.0F / s;
  x_ *= invS;
  y_ *= invS;

  return *this;
}

Vector2 &Vector2::operator+=(const Vector2 &vector) {
  x_ += vector.x();
  y_ += vector.y();

  return *this;
}

Vector2 &Vector2::operator-=(const Vector2 &vector) {
  x_ -= vector.x();
  y_ -= vector.y();

  return *this;
}

Vector2 operator*(float s, const Vector2 &vector) {
  return Vector2(s * vector.x(), s * vector.y());
}

std::ostream &operator<<(std::ostream &os, const Vector2 &vector) {
  os << "(" << vector.x() << "," << vector.y() << ")";

  return os;
}

float abs(const Vector2 &vector) { return std::sqrt(vector * vector); }

float absSq(const Vector2 &vector) { return vector * vector; }

float det(const Vector2 &vector1, const Vector2 &vector2) {
  return vector1.x() * vector2.y() - vector1.y() * vector2.x();
}

float leftOf(const Vector2 &a, const Vector2 &b, const Vector2 &c) {
  return det(a - c, b - a);
}

Vector2 normalize(const Vector2 &vector) { return vector / abs(vector); }
}  // namespace RVO
