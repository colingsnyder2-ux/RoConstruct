// 2008-06 util/NormalId.cpp (application range 005ec000..005f0000, rows 005ec180..005ec9ef). Inactive native unit.
// Declarations: the donor util/NormalId.h (read-only) plus native-headers/AppUnit5EC/NormalIdVector.h.
#include "AppUnit5EC/NormalIdVector.h"

using G3D::Vector3;
using G3D::Matrix3;

namespace RBX
{
	// 005ec180: (id + 3) % 6
	NormalId normalIdOpposite(NormalId normalId)
	{
		return (NormalId)((normalId + NORM_X_NEG) % NORM_UNDEFINED);
	}

	// per-face uvw -> object transforms; NORM_X 005ec1a0, NORM_Y 005ec1c0, NORM_X_NEG 005ec1e0, NORM_Y_NEG 005ec200,
	// NORM_Z_NEG 005ec220 (the NORM_Z copy is folded with another Vector3 copy outside this range)
	template<> Vector3 uvwToObject<NORM_X>(const Vector3& v)     { return Vector3(v.z, v.y, -v.x); }
	template<> Vector3 uvwToObject<NORM_Y>(const Vector3& v)     { return Vector3(-v.x, v.z, v.y); }
	template<> Vector3 uvwToObject<NORM_Z>(const Vector3& v)     { return Vector3(v.x, v.y, v.z); }
	template<> Vector3 uvwToObject<NORM_X_NEG>(const Vector3& v) { return Vector3(-v.z, v.y, v.x); }
	template<> Vector3 uvwToObject<NORM_Y_NEG>(const Vector3& v) { return Vector3(v.x, -v.z, v.y); }
	template<> Vector3 uvwToObject<NORM_Z_NEG>(const Vector3& v) { return Vector3(-v.x, v.y, -v.z); }

	// 005ec240
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

	// 005ec290
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

	// 005ec310 (Matrix3::getColumn 00513240)
	NormalId Matrix3ToNormalId(const Matrix3& m)
	{
		return Vector3ToNormalId(m.getColumn(2));
	}

	// 005ec330
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

	// 005ec450
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

	// 005ec570 (statics 0097ae3c.., guard 0097ae48)
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

	// 005ec6e0 (G3D Vector3::unitX/unitY/unitZ function statics)
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

	// 005ec800 (statics 0097af00.., guard 0097af24)
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

	// 005ec9d0
	Vector3 mapToUvw_Legacy(const Vector3& ptInObject, NormalId faceId)
	{
		return uvwToObject(ptInObject, faceId);
	}
}
