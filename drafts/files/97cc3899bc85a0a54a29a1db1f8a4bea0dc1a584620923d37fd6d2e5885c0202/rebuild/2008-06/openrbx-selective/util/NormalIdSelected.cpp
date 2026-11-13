#include "util/NormalId.h"

// PORT: donor size annotations are metadata, not 2008 API.

namespace RBX {
// PORT: donor relied on G3D type imports.
using namespace G3D;

// PORT: selective unit and required original helper.

Vector3 normalIdToVector3Internal(NormalId normalId)
{
	Vector3 answer;
	answer.x = 0.0f;
	answer.y = 0.0f;
	answer.z = 0.0f;

	int axis = normalId % 3;

	if (normalId < 3) {
		(&answer.x)[axis] = 1.0f;
	}
	else {
		(&answer.x)[axis] = -1.0f;
	}

	return answer;
}

NormalId Vector3ToNormalId(const Vector3& v)
{
	if (v.x == 1.0f) {
		return NORM_X;
	}
	if (v.y == 1.0f) {
		return NORM_Y;
	}
	if (v.z == 1.0f) {
		return NORM_Z;
	}
	if (v.x == -1.0f) {
		return NORM_X_NEG;
	}
	if (v.y == -1.0f) {
		return NORM_Y_NEG;
	}

	return v.z == -1.0f ? NORM_Z_NEG : NORM_UNDEFINED;
}

const Vector3& normalIdToVector3(NormalId normalId)
{
	switch (normalId) {
	case NORM_X: {
		static const Vector3 x = normalIdToVector3Internal(NORM_X);
		return x;
	}
	case NORM_Y: {
		static const Vector3 y = normalIdToVector3Internal(NORM_Y);
		return y;
	}
	case NORM_Z: {
		static const Vector3 z = normalIdToVector3Internal(NORM_Z);
		return z;
	}
	case NORM_X_NEG: {
		static const Vector3 xn = normalIdToVector3Internal(NORM_X_NEG);
		return xn;
	}
	case NORM_Y_NEG: {
		static const Vector3 yn = normalIdToVector3Internal(NORM_Y_NEG);
		return yn;
	}
	case NORM_Z_NEG: {
		static const Vector3 zn = normalIdToVector3Internal(NORM_Z_NEG);
		return zn;
	}
	}

	return Vector3::zero();
}

const Matrix3& normalIdToMatrix3(NormalId normalId)
{
	switch (normalId) {
	case NORM_X: {
		static const Matrix3 x = normalIdToMatrix3Internal(NORM_X);
		return x;
	}
	case NORM_Y: {
		static const Matrix3 y = normalIdToMatrix3Internal(NORM_Y);
		return y;
	}
	case NORM_Z: {
		static const Matrix3 z = normalIdToMatrix3Internal(NORM_Z);
		return z;
	}
	case NORM_X_NEG: {
		static const Matrix3 xn = normalIdToMatrix3Internal(NORM_X_NEG);
		return xn;
	}
	case NORM_Y_NEG: {
		static const Matrix3 yn = normalIdToMatrix3Internal(NORM_Y_NEG);
		return yn;
	}
	case NORM_Z_NEG: {
		static const Matrix3 zn = normalIdToMatrix3Internal(NORM_Z_NEG);
		return zn;
	}
	}

	return Matrix3::identity();
}

} // namespace RBX
