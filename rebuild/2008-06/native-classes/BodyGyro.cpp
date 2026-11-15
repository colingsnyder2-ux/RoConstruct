// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
// 2008-06 native RBX::BodyGyro rows of the original BodyMovers unit (0062e090..00633101) that read 2008 Body fields
// (inactive): BodyGyro::computeOrientation 0062e910 and BodyGyro::computeBalance 0062ec40. BodyGyro::computeForce
// 006300d0 (their only caller) is in native-classes/BodyMovers.cpp.
//
// Batch 16: like native-classes/RocketControl.cpp, this unit defines NATIVE_PRIMITIVE_NATIVE_BODY, so the
// part-embedded Primitive.h and native-headers/v8datamodel/BodyMovers.h (-> v8kernel/Connector.h -> Connector2008.h)
// reach native-headers/v8kernel/Body2008.h (root +0x10, cofm +0x28, simBody +0x2c, moment +0x68, pv +0x94). The
// unit-local Connector / BodyMover / BodyGyro redeclarations of earlier batches are gone.
// Body::getBranchIBodyV3 (0062e100) and Body::getBranchTorque (0062e2e0) are now public inline members of
// native-headers/v8kernel/Body2008.h (donor tools/rbxgs v8kernel/Body.h shapes). With them computeOrientation 0062e910
// and the out-of-line COMDATs 0062e100 / 0062e2e0 / Body::accumulateTorque 006060b0 are prove.py inactive_exact
// (batch 12); computeBalance 0062ec40 stays parked (x87 scheduling, see below).
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8datamodel/BodyMovers.h"
#include "v8datamodel/PartInstance.h"
#include <G3D/g3dmath.h>
#include "util/Math.h"

namespace RBX
{
	// 0062e910: donor tools/rbxgs Gyro.cpp BodyGyro::computeOrientation.
	void BodyGyro::computeOrientation(Body* body)
	{
		if (G3D::fuzzyEq(maxTorque.y, 0.0f))
			return;

		Body* root = body->getRoot();

		G3D::Vector3 oldTorqueWorld = root->getBranchTorque();

		G3D::Vector3 localZNegAxis = body->getCoordinateFrame().vectorToObjectSpace(cframe.lookVector());

		float desiredTorqueY = -(root->getBranchIBodyV3().y * localZNegAxis.x * kP);

		G3D::Vector3 torqueBody = body->getCoordinateFrame().vectorToObjectSpace(oldTorqueWorld);

		if (fabs(desiredTorqueY - torqueBody.y) < root->getBranchIBodyV3().y * maxTorque.y)
			torqueBody.y = desiredTorqueY;
		else
			torqueBody.y = torqueBody.y + desiredTorqueY;

		G3D::Vector3 angVelBody = body->getCoordinateFrame().vectorToObjectSpace(body->getVelocity().rotational);
		torqueBody.y = torqueBody.y - kD * root->getBranchIBodyV3().y * angVelBody.y;

		G3D::Vector3 addedTorque = body->getCoordinateFrame().vectorToWorldSpace(torqueBody) - oldTorqueWorld;

		root->accumulateTorque(addedTorque);
	}

	// 0062ec40: donor tools/rbxgs Gyro.cpp BodyGyro::computeBalance.
	void BodyGyro::computeBalance(Body* body)
	{
		if (G3D::fuzzyEq(maxTorque.x, 0.0f) && G3D::fuzzyEq(maxTorque.z, 0.0f))
			return;

		Body* root = body->getRoot();
		G3D::Vector3 oldTorqueWorld = root->getBranchTorque();
		G3D::Vector3 localYAxis = body->getCoordinateFrame().vectorToObjectSpace(cframe.upVector());
		float desiredTorqueX = root->getBranchIBodyV3().x * localYAxis.z * kP;
		float desiredTorqueZ = -(root->getBranchIBodyV3().z * localYAxis.x * kP);

		G3D::Vector3 torqueBody = body->getCoordinateFrame().vectorToObjectSpace(oldTorqueWorld);

		if (fabs(desiredTorqueX - torqueBody.x) < root->getBranchIBodyV3().x * maxTorque.x)
			torqueBody.x = desiredTorqueX;
		else
			torqueBody.x += desiredTorqueX;

		if (fabs(desiredTorqueZ - torqueBody.z) < root->getBranchIBodyV3().z * maxTorque.z)
			torqueBody.z = desiredTorqueZ;
		else
			torqueBody.z += desiredTorqueZ;

		G3D::Vector3 angVelBody = body->getCoordinateFrame().vectorToObjectSpace(body->getVelocity().rotational);
		// Parked: 1136 bytes, first divergence at 0062ef27 (x87 scheduling only). The target loads kD first
		// ((kD * I.x) * angVelBody.x) and orders the angVelBody row as m01*y + m02*z + m00*x; every form tried compiles
		// to (I.x * angVelBody.x) * kD with m02*z first: `(I * a) * kD` (donor), `x = x - kD * I * a`,
		// `-= kD * (I * a)`, `-= kD * I * a`.
		torqueBody.x -= (root->getBranchIBodyV3().x * angVelBody.x) * kD;
		torqueBody.z -= (root->getBranchIBodyV3().z * angVelBody.z) * kD;

		G3D::Vector3 addedTorque = body->getCoordinateFrame().vectorToWorldSpace(torqueBody) - oldTorqueWorld;

		root->accumulateTorque(addedTorque);
	}
}
