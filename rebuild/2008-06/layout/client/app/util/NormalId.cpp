#include "AppUnit5EC/NormalIdVector.h"

using G3D::Vector3;
using G3D::Matrix3;

namespace RBX
{
	NormalId normalIdOpposite(NormalId normalId)
	{
		return (NormalId)((normalId + NORM_X_NEG) % NORM_UNDEFINED);
	}

	template<> Vector3 uvwToObject<NORM_X>(const Vector3& v)     { return Vector3(v.z, v.y, -v.x); }
	template<> Vector3 uvwToObject<NORM_Y>(const Vector3& v)     { return Vector3(-v.x, v.z, v.y); }
	template<> Vector3 uvwToObject<NORM_Z>(const Vector3& v)     { return Vector3(v.x, v.y, v.z); }
	template<> Vector3 uvwToObject<NORM_X_NEG>(const Vector3& v) { return Vector3(-v.z, v.y, v.x); }
	template<> Vector3 uvwToObject<NORM_Y_NEG>(const Vector3& v) { return Vector3(v.x, -v.z, v.y); }
	template<> Vector3 uvwToObject<NORM_Z_NEG>(const Vector3& v) { return Vector3(-v.x, v.y, -v.z); }

	Vector3 normalIdToVector3Internal(NormalId normalId)
	{
		Vector3 answer;
		answer.x = 0.0f;
		answer.y = 0.0f;
		answer.z = 0.0f;
		int axis = normalId % 3;
		if (normalId < 3)
			answer[axis] = 1.0f;
		else
			answer[axis] = -1.0f;
		return answer;
	}

	NormalId Vector3ToNormalId(const Vector3& v)
	{
		if (v.x == 1.0f)
			return NORM_X;
		if (v.y == 1.0f)
			return NORM_Y;
		if (v.z == 1.0f)
			return NORM_Z;
		if (v.x == -1.0f)
			return NORM_X_NEG;
		if (v.y == -1.0f)
			return NORM_Y_NEG;
		return v.z == -1.0f ? NORM_Z_NEG : NORM_UNDEFINED;
	}

	NormalId Matrix3ToNormalId(const Matrix3& m)
	{
		return Vector3ToNormalId(m.getColumn(2));
	}

	Vector3 uvwToObject(const Vector3& uvwPt, NormalId faceId)
	{
		switch (faceId)
		{
		case NORM_X:     return uvwToObject<NORM_X>(uvwPt);
		case NORM_Y:     return uvwToObject<NORM_Y>(uvwPt);
		case NORM_Z:     return uvwToObject<NORM_Z>(uvwPt);
		case NORM_X_NEG: return uvwToObject<NORM_X_NEG>(uvwPt);
		case NORM_Y_NEG: return uvwToObject<NORM_Y_NEG>(uvwPt);
		case NORM_Z_NEG: return uvwToObject<NORM_Z_NEG>(uvwPt);
		}
		return Vector3::unitX();
	}

	Vector3 objectToUvw(const Vector3& objectPt, NormalId faceId)
	{
		switch (faceId)
		{
		case NORM_X:     return Vector3(-objectPt.z, objectPt.y, objectPt.x);
		case NORM_Y:     return Vector3(-objectPt.x, objectPt.z, objectPt.y);
		case NORM_Z:     return Vector3(objectPt.x, objectPt.y, objectPt.z);
		case NORM_X_NEG: return Vector3(objectPt.z, objectPt.y, -objectPt.x);
		case NORM_Y_NEG: return Vector3(objectPt.x, objectPt.z, -objectPt.y);
		case NORM_Z_NEG: return Vector3(-objectPt.x, objectPt.y, -objectPt.z);
		}
		return Vector3::unitX();
	}

	const Vector3& normalIdToVector3(NormalId normalId)
	{
		switch (normalId)
		{
		case NORM_X:     { static const Vector3 x = normalIdToVector3Internal(NORM_X); return x; }
		case NORM_Y:     { static const Vector3 y = normalIdToVector3Internal(NORM_Y); return y; }
		case NORM_Z:     { static const Vector3 z = normalIdToVector3Internal(NORM_Z); return z; }
		case NORM_X_NEG: { static const Vector3 xn = normalIdToVector3Internal(NORM_X_NEG); return xn; }
		case NORM_Y_NEG: { static const Vector3 yn = normalIdToVector3Internal(NORM_Y_NEG); return yn; }
		case NORM_Z_NEG: { static const Vector3 zn = normalIdToVector3Internal(NORM_Z_NEG); return zn; }
		}
		return Vector3::zero();
	}

	Matrix3 normalIdToMatrix3Internal(NormalId normalId)
	{
		const Vector3 uInObject = uvwToObject(Vector3::unitX(), normalId);
		const Vector3 vInObject = uvwToObject(Vector3::unitY(), normalId);
		const Vector3 wInObject = uvwToObject(Vector3::unitZ(), normalId);
		return Matrix3(
			uInObject.x, vInObject.x, wInObject.x,
			uInObject.y, vInObject.y, wInObject.y,
			uInObject.z, vInObject.z, wInObject.z);
	}

	const Matrix3& normalIdToMatrix3(NormalId normalId)
	{
		switch (normalId)
		{
		case NORM_X:     { static const Matrix3 x = normalIdToMatrix3Internal(NORM_X); return x; }
		case NORM_Y:     { static const Matrix3 y = normalIdToMatrix3Internal(NORM_Y); return y; }
		case NORM_Z:     { static const Matrix3 z = normalIdToMatrix3Internal(NORM_Z); return z; }
		case NORM_X_NEG: { static const Matrix3 xn = normalIdToMatrix3Internal(NORM_X_NEG); return xn; }
		case NORM_Y_NEG: { static const Matrix3 yn = normalIdToMatrix3Internal(NORM_Y_NEG); return yn; }
		case NORM_Z_NEG: { static const Matrix3 zn = normalIdToMatrix3Internal(NORM_Z_NEG); return zn; }
		}
		return Matrix3::identity();
	}

	Vector3 mapToUvw_Legacy(const Vector3& ptInObject, NormalId faceId)
	{
		return uvwToObject(ptInObject, faceId);
	}
}
