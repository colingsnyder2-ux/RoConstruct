// from server: 100% by EspClaude
// claude-opus-5-5 G3: row1 of pointToWorldSpace read into named locals (m10,m11,m12,t1) fixes fp:fast pair order
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lang: cpp
#include <limits>
#include <algorithm>
namespace G3D {
template <class T> inline T min(const T& x, const T& y) { return std::min<T>(x, y); }
template <class T> inline T max(const T& x, const T& y) { return std::max<T>(x, y); }
class Vector3 {
public:
    float x, y, z;
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ) {}
    Vector3(const Vector3& V) : x(V.x), y(V.y), z(V.z) {}
    Vector3& operator= (const Vector3& r) { x = r.x; y = r.y; z = r.z; return *this; }
    const float& operator[] (int i) const { return ((float*)this)[i]; }
    float& operator[] (int i) { return ((float*)this)[i]; }
    Vector3 min(const Vector3 &v) const { return Vector3(G3D::min(v.x, x), G3D::min(v.y, y), G3D::min(v.z, z)); }
    Vector3 max(const Vector3 &v) const { return Vector3(G3D::max(v.x, x), G3D::max(v.y, y), G3D::max(v.z, z)); }
};
class Matrix3 {
public:
    float elt[3][3];
    float* operator[] (int iRow) { return (float*)&elt[iRow][0]; }
    const float* operator[] (int iRow) const { return (const float*)&elt[iRow][0]; }
};
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    Vector3 pointToWorldSpace(const Vector3& v) const {
        float m10 = rotation[1][0];
        float m11 = rotation[1][1];
        float m12 = rotation[1][2];
        float t1 = translation[1];
        return Vector3(
			rotation[0][0] * v[0] + rotation[0][1] * v[1] + rotation[0][2] * v[2] + translation[0],
			m10 * v[0] + m11 * v[1] + m12 * v[2] + t1,
			rotation[2][0] * v[0] + rotation[2][1] * v[1] + rotation[2][2] * v[2] + translation[2]);
    }
	Vector3 pointToObjectSpace(const Vector3& v) const {
		float p[3];
		p[0] = v[0] - translation[0];
		p[1] = v[1] - translation[1];
		p[2] = v[2] - translation[2];
		return Vector3(
			rotation[0][0] * p[0] + rotation[1][0] * p[1] + rotation[2][0] * p[2],
			rotation[0][1] * p[0] + rotation[1][1] * p[1] + rotation[2][1] * p[2],
			rotation[0][2] * p[0] + rotation[1][2] * p[1] + rotation[2][2] * p[2]);
    }
};
}
namespace RBX {
using G3D::Vector3;
using G3D::CoordinateFrame;
class Math { public:
	static const float& inf() { static const float i = std::numeric_limits<float>::infinity(); return i; }
};
class Extents {
public:
	Extents() {}
	static Extents vv(const Vector3& v0, const Vector3& v1);
	Vector3 getCorner(int index) const;
	Extents express(const CoordinateFrame& from, const CoordinateFrame& to);
	Vector3 low, high;
};
Vector3 Extents::getCorner(int i) const
{
	const Vector3* corners = &low;
	return Vector3(corners[i / 4].x, corners[i / 2 % 2].y, corners[i % 2].z);
}
Extents Extents::express(const CoordinateFrame& myFrame, const CoordinateFrame& expressInFrame)
{
	Vector3 minC(Math::inf(), Math::inf(), Math::inf());
	Vector3 maxC(-Math::inf(), -Math::inf(), -Math::inf());

	for (int i = 0; i < 8; ++i) {
		const Vector3 inOther = expressInFrame.pointToObjectSpace(myFrame.pointToWorldSpace(getCorner(i)));

		minC = minC.min(inOther);
		maxC = maxC.max(inOther);
	}

	return vv(minC, maxC);
}
}

