/*
 * Vector2.h
 * RVO2 Library
 *
 * Copyright (c) 2008-2013 University of North Carolina at Chapel Hill.
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for educational, research, and non-profit purposes, without
 * fee, and without a written agreement is hereby granted, provided that the
 * above copyright notice, this paragraph, and the following four paragraphs
 * appear in all copies.
 *
 * Permission to incorporate this software into commercial products may be
 * obtained by contacting the authors <geom@cs.unc.edu> or the Office of
 * Technology Development at the University of North Carolina at Chapel Hill
 * <otd@unc.edu>.
 *
 * This software program and documentation are copyrighted by the University of
 * North Carolina at Chapel Hill. The software program and documentation are
 * supplied "as is," without any accompanying services from the University of
 * North Carolina at Chapel Hill or the authors. The University of North
 * Carolina at Chapel Hill and the authors do not warrant that the operation of
 * the program will be uninterrupted or error-free. The end-user understands
 * that the program was developed for research purposes and is advised not to
 * rely exclusively on the program for any reason.
 *
 * IN NO EVENT SHALL THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL OR THE
 * AUTHORS BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING OUT OF THE USE OF THIS
 * SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE UNIVERSITY OF NORTH CAROLINA AT
 * CHAPEL HILL OR THE AUTHORS HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
 * THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL AND THE AUTHORS SPECIFICALLY
 * DISCLAIM ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE AND ANY
 * STATUTORY WARRANTY OF NON-INFRINGEMENT. THE SOFTWARE PROVIDED HEREUNDER IS ON
 * AN "AS IS" BASIS, AND THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL AND THE
 * AUTHORS HAVE NO OBLIGATIONS TO PROVIDE MAINTENANCE, SUPPORT, UPDATES,
 * ENHANCEMENTS, OR MODIFICATIONS.
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
 * <http://gamma.cs.unc.edu/RVO2/>
 */

#ifndef RVO_VECTOR2_H_
#define RVO_VECTOR2_H_

/**
 * \file       Vector2.h
 * \brief      Contains the Vector2 class.
 */

#include <cmath>
#include <ostream>

namespace RVO {
	/**
	 * \brief      Defines a two-dimensional vector.
	 */
	class Vector2 {
	public:
		/**
		 * \brief      Constructs and initializes a two-dimensional vector instance
		 *             to (0.0, 0.0).
		 */
		inline Vector2() : x_(0.0f), y_(0.0f) { }

		/**
		 * \brief      Constructs and initializes a two-dimensional vector from
		 *             the specified xy-coordinates.
		 * \param      x               The x-coordinate of the two-dimensional
		 *                             vector.
		 * \param      y               The y-coordinate of the two-dimensional
		 *                             vector.
		 */
		inline Vector2(float x, float y) : x_(x), y_(y) { }

		/**
		 * \brief      Returns the x-coordinate of this two-dimensional vector.
		 * \return     The x-coordinate of the two-dimensional vector.
		 */
		inline float x() const { return x_; }

		/**
		 * \brief      Returns the y-coordinate of this two-dimensional vector.
		 * \return     The y-coordinate of the two-dimensional vector.
		 */
		inline float y() const { return y_; }

		/**
		 * \brief      Computes the negation of this two-dimensional vector.
		 * \return     The negation of this two-dimensional vector.
		 */
		inline Vector2 operator-() const
		{
			return Vector2(-x_, -y_);
		}

		/**
		 * \brief      Computes the dot product of this two-dimensional vector with
		 *             the specified two-dimensional vector.
		 * \param      vector          The two-dimensional vector with which the
		 *                             dot product should be computed.
		 * \return     The dot product of this two-dimensional vector with a
		 *             specified two-dimensional vector.
		 */
		inline float operator*(const Vector2 &vector) const
		{
			return x_ * vector.x() + y_ * vector.y();
		}

		/**
		 * \brief      Computes the scalar multiplication of this
		 *             two-dimensional vector with the specified scalar value.
		 * \param      s               The scalar value with which the scalar
		 *                             multiplication should be computed.
		 * \return     The scalar multiplication of this two-dimensional vector
		 *             with a specified scalar value.
		 */
		inline Vector2 operator*(float s) const
		{
			return Vector2(x_ * s, y_ * s);
		}

		/**
		 * \brief      Computes the scalar division of this two-dimensional vector
		 *             with the specified scalar value.
		 * \param      s               The scalar value with which the scalar
		 *                             division should be computed.
		 * \return     The scalar division of this two-dimensional vector with a
		 *             specified scalar value.
		 */
		inline Vector2 operator/(float s) const
		{
			const float invS = 1.0f / s;

			return Vector2(x_ * invS, y_ * invS);
		}

		/**
		 * \brief      Computes the vector sum of this two-dimensional vector with
		 *             the specified two-dimensional vector.
		 * \param      vector          The two-dimensional vector with which the
		 *                             vector sum should be computed.
		 * \return     The vector sum of this two-dimensional vector with a
		 *             specified two-dimensional vector.
		 */
		inline Vector2 operator+(const Vector2 &vector) const
		{
			return Vector2(x_ + vector.x(), y_ + vector.y());
		}

		/**
		 * \brief      Computes the vector difference of this two-dimensional
		 *             vector with the specified two-dimensional vector.
		 * \param      vector          The two-dimensional vector with which the
		 *                             vector difference should be computed.
		 * \return     The vector difference of this two-dimensional vector with a
		 *             specified two-dimensional vector.
		 */
		inline Vector2 operator-(const Vector2 &vector) const
		{
			return Vector2(x_ - vector.x(), y_ - vector.y());
		}

		/**
		 * \brief      Tests this two-dimensional vector for equality with the
		 *             specified two-dimensional vector.
		 * \param      vector          The two-dimensional vector with which to
		 *                             test for equality.
		 * \return     True if the two-dimensional vectors are equal.
		 */
		inline bool operator==(const Vector2 &vector) const
		{
			return x_ == vector.x() && y_ == vector.y();
		}

		/**
		 * \brief      Tests this two-dimensional vector for inequality with the
		 *             specified two-dimensional vector.
		 * \param      vector          The two-dimensional vector with which to
		 *                             test for inequality.
		 * \return     True if the two-dimensional vectors are not equal.
		 */
		inline bool operator!=(const Vector2 &vector) const
		{
			return x_ != vector.x() || y_ != vector.y();
		}

		/**
		 * \brief      Sets the value of this two-dimensional vector to the scalar
		 *             multiplication of itself with the specified scalar value.
		 * \param      s               The scalar value with which the scalar
		 *                             multiplication should be computed.
		 * \return     A reference to this two-dimensional vector.
		 */
		inline Vector2 &operator*=(float s)
		{
			x_ *= s;
			y_ *= s;

			return *this;
		}

		/**
		 * \brief      Sets the value of this two-dimensional vector to the scalar
		 *             division of itself with the specified scalar value.
		 * \param      s               The scalar value with which the scalar
		 *                             division should be computed.
		 * \return     A reference to this two-dimensional vector.
		 */
		inline Vector2 &operator/=(float s)
		{
			const float invS = 1.0f / s;
			x_ *= invS;
			y_ *= invS;

			return *this;
		}

		/**
		 * \brief      Sets the value of this two-dimensional vector to the vector
		 *             sum of itself with the specified two-dimensional vector.
		 * \param      vector          The two-dimensional vector with which the
		 *                             vector sum should be computed.
		 * \return     A reference to this two-dimensional vector.
		 */
		inline Vector2 &operator+=(const Vector2 &vector)
		{
			x_ += vector.x();
			y_ += vector.y();

			return *this;
		}

		/**
		 * \brief      Sets the value of this two-dimensional vector to the vector
		 *             difference of itself with the specified two-dimensional
		 *             vector.
		 * \param      vector          The two-dimensional vector with which the
		 *                             vector difference should be computed.
		 * \return     A reference to this two-dimensional vector.
		 */
		inline Vector2 &operator-=(const Vector2 &vector)
		{
			x_ -= vector.x();
			y_ -= vector.y();

			return *this;
		}

	private:
		float x_;
		float y_;
	};

	/**
	 * \relates    Vector2
	 * \brief      Computes the scalar multiplication of the specified
	 *             two-dimensional vector with the specified scalar value.
	 * \param      s               The scalar value with which the scalar
	 *                             multiplication should be computed.
	 * \param      vector          The two-dimensional vector with which the scalar
	 *                             multiplication should be computed.
	 * \return     The scalar multiplication of the two-dimensional vector with the
	 *             scalar value.
	 */
	inline Vector2 operator*(float s, const Vector2 &vector)
	{
		return Vector2(s * vector.x(), s * vector.y());
	}

	/**
	 * \relates    Vector2
	 * \brief      Inserts the specified two-dimensional vector into the specified
	 *             output stream.
	 * \param      os              The output stream into which the two-dimensional
	 *                             vector should be inserted.
	 * \param      vector          The two-dimensional vector which to insert into
	 *                             the output stream.
	 * \return     A reference to the output stream.
	 */
	inline std::ostream &operator<<(std::ostream &os, const Vector2 &vector)
	{
		os << "(" << vector.x() << "," << vector.y() << ")";

		return os;
	}

	/**
	 * \relates    Vector2
	 * \brief      Computes the length of a specified two-dimensional vector.
	 * \param      vector          The two-dimensional vector whose length is to be
	 *                             computed.
	 * \return     The length of the two-dimensional vector.
	 */
	inline float abs(const Vector2 &vector)
	{
		return std::sqrt(vector * vector);
	}

	/**
	 * \relates    Vector2
	 * \brief      Computes the squared length of a specified two-dimensional
	 *             vector.
	 * \param      vector          The two-dimensional vector whose squared length
	 *                             is to be computed.
	 * \return     The squared length of the two-dimensional vector.
	 */
	inline float absSq(const Vector2 &vector)
	{
		return vector * vector;
	}

	/**
	 * \relates    Vector2
	 * \brief      Computes the determinant of a two-dimensional square matrix with
	 *             rows consisting of the specified two-dimensional vectors.
	 * \param      vector1         The top row of the two-dimensional square
	 *                             matrix.
	 * \param      vector2         The bottom row of the two-dimensional square
	 *                             matrix.
	 * \return     The determinant of the two-dimensional square matrix.
	 */
	inline float det(const Vector2 &vector1, const Vector2 &vector2)
	{
		return vector1.x() * vector2.y() - vector1.y() * vector2.x();
	}

	/**
	 * \relates    Vector2
	 * \brief      Computes the normalization of the specified two-dimensional
	 *             vector.
	 * \param      vector          The two-dimensional vector whose normalization
	 *                             is to be computed.
	 * \return     The normalization of the two-dimensional vector.
	 */
	inline Vector2 normalize(const Vector2 &vector)
	{
		return vector / abs(vector);
	}
}

#endif /* RVO_VECTOR2_H_ */
