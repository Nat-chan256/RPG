#ifndef __SIZES_HPP
#define __SIZES_HPP

/*
	Vector, но свой. Чтобы убрать зависимость от SFML - потом моно будет переехать на что-то покруче, при желании.
	Так как лень реализовывать - просто using.
	Ps Да, это нагло скопировано с кода SFML. Но оформлено по стилю рпгешки и без inc файла.
*/

#include <inttypes.h>

namespace data
{

template <typename T>
class Vector
{
public:
	inline Vector(T _x, T _y) :
		x(_x),
		y(_y) {};

	inline Vector() :
		x(0),
		y(0) {};

	template <typename U>
	inline explicit Vector(const Vector<U>& _vector) :
		x(static_cast<T>(_vector.x)),
		y(static_cast<T>(_vector.y)) {};

	~Vector() = default;

	T x;
	T y;
};

using VectorF = Vector<float>;

using VectorI8 = Vector<int8_t>;
using VectorI16 = Vector<int16_t>;
using VectorI32 = Vector<int32_t>;
using VectorI64 = Vector<int64_t>;

using VectorUI8 = Vector<uint8_t>;
using VectorUI16 = Vector<uint16_t>;
using VectorUI32 = Vector<uint32_t>;
using VectorUI64 = Vector<uint64_t>;


// = = = = =

template <typename T>
inline Vector<T> operator - (const Vector<T>& _right)
{
	return Vector<T>(-_right.x, -_right.y);
}

template <typename T>
inline Vector<T>& operator += (Vector<T>& _left, const Vector<T>& _right)
{
	_left.x += _right.x;
	_left.y += _right.y;

	return _left;
}

template <typename T>
inline Vector<T>& operator -= (Vector<T>& _left, const Vector<T>& _right)
{
	_left.x -= _right.x;
	_left.y -= _right.y;

	return _left;
}

template <typename T>
inline Vector<T> operator + (const Vector<T>& _left, const Vector<T>& _right)
{
	return Vector<T>(_left.x + _right.x, _left.y + _right.y);
}

template <typename T>
inline Vector<T> operator - (const Vector<T>& _left, const Vector<T>& _right)
{
	return Vector<T>(_left.x - _right.x, _left.y - _right.y);
}

template <typename T>
inline Vector<T> operator * (const Vector<T>& _left, T _right)
{
	return Vector<T>(_left.x * _right, _left.y * _right);
}

template <typename T>
inline Vector<T> operator * (T _left, const Vector<T>& _right)
{
	return Vector<T>(_right.x * _left, _right.y * _left);
}

template <typename T>
inline Vector<T>& operator *= (Vector<T>& _left, T _right)
{
	_left.x *= _right;
	_left.y *= _right;

	return _left;
}

template <typename T>
inline Vector<T> operator / (const Vector<T>& _left, T _right)
{
	return Vector<T>(_left.x / _right, _left.y / _right);
}

template <typename T>
inline Vector<T>& operator /= (Vector<T>& _left, T _right)
{
	_left.x /= _right;
	_left.y /= _right;

	return _left;
}

template <typename T>
inline bool operator == (const Vector<T>& _left, const Vector<T>& _right)
{
	return (_left.x == _right.x) && (_left.y == _right.y);
}

template <typename T>
inline bool operator != (const Vector<T>& _left, const Vector<T>& _right)
{
	return (_left.x != _right.x) || (_left.y != _right.y);
}

} // namespace Data

#endif /* __SIZES_HPP */
