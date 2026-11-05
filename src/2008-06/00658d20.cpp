// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_claudesub_dbec07a4b021be47.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8kernel/KernelIndex.h", "roc_espeon_kernelindex16f57e5495e5b6c8eb.cpp")
#pragma include_alias("v8kernel/SimBody.h", "roc_espeon_simbodyfloatlayout9e678fde612f7036.cpp")
#include "v8kernel/SimBody.h"
#include "v8kernel/Constants.h"
#include "v8kernel/Body.h"
#include "util/Units.h"
namespace RBX
{

SimBody::SimBody(RBX::Body* _body)
			:body(_body),scalarAt4(0.0f),
			dirty(1),
			force(G3D::Vector3::zero()),
			torque(G3D::Vector3::zero()),
			constantForceY(0.0f)
{}

SimBody::~SimBody() {}

G3D::Vector3 vecUnkPercent(G3D::Vector3& input)
{
	return G3D::Vector3(1.0f / input.x, 1.0f / input.y, 1.0f / input.z);
}

float precentInline(float fNum)
{
	return 1.0f / fNum;
}

inline void Quaternion::normalize()
{
	*this *= 1.0f / magnitude();
}

__forceinline void SimBody::unkSimInline(float fNum)
{
	massRecip = 1.0f / fNum;
	momentRecip = vecUnkPercent(Math::toDiagonal(body->getBranchIBody()));
}

void SimBody::update()
{ float roc_dd0 = 0; float roc_dd1 = 0; float roc_dd2 = 0;
	
	{
		const G3D::Vector3 cofmOffset = body->getCofmOffset();
		pv = body->getPV().pvAtLocalOffset(cofmOffset);
	}
	qOrientation = Quaternion::Quaternion(pv.position.rotation);
	qOrientation.normalize();
	angMomentum = pv.velocity.rotational * body->getBranchIWorld();
	float _mass = body->getBranchMass();
	unkSimInline(_mass);
	constantForceY = body->getBranchMass() * Units::kmsAccelerationToRbx(Constants::getKmsGravity()).y;
	dirty = false;
}


}

