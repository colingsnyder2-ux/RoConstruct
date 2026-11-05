// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_rotate_kernel_native_6a4b4d96eefe4e74.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#include <v8world/RotateJoint.h>
#include <v8world/Primitive.h>
#include <v8world/World.h>
#include <v8kernel/Body.h>
#include <util/Math.h>
namespace RBX {
class RotatePrimitiveApi {
public:
    Body* getBody() { return *(Body**)((char*)this+0xa0); }
};
class RotateBodyApi {
private:
    void updatePV() const;
public:
    const G3D::CoordinateFrame& getCoordinateFrame() const {
        updatePV();
        return *(const G3D::CoordinateFrame*)((const char*)this+0x94);
    }
};
	void RotateJoint::putInKernel(Kernel* _kernel)
	{
		MultiJoint::putInKernel(_kernel);

		Body* b0 = ((RotatePrimitiveApi*)getAxlePrim())->getBody();
		Body* b1 = ((RotatePrimitiveApi*)getHolePrim())->getBody();

		G3D::CoordinateFrame cAxleWorld = ((RotateBodyApi*)b0)->getCoordinateFrame() * jointCoord0;
		G3D::CoordinateFrame cHoleWorld = ((RotateBodyApi*)b1)->getCoordinateFrame() * jointCoord1;

		G3D::Vector3 vAxleWorld = cAxleWorld.rotation.getColumn(2);
		G3D::Vector3 vHoleWorld = cHoleWorld.rotation.getColumn(2);

		for (int i = 0; i < 2; i++)
		{
			float multiplier = i == 0 ? -1.0f : 1.0f;

			G3D::Vector3 pAxleWorldPos = vAxleWorld * multiplier + cAxleWorld.translation;
			G3D::Vector3 pHoleWorldPos = vHoleWorld * multiplier + cHoleWorld.translation;

			Point* pAxleWorld = getKernel()->newPoint(b0, pAxleWorldPos);
			Point* pHoleWorld = getKernel()->newPoint(b1, pHoleWorldPos);

			PointToPointBreakConnector* connector = new PointToPointBreakConnector(pAxleWorld, pHoleWorld, getJointK(), Math::inf());
			addToMultiJoint(pAxleWorld, pHoleWorld, connector);
		}

		if (getJointType() == ROTATE_P_JOINT || getJointType() == ROTATE_V_JOINT)
		{
			G3D::Vector3 center0 = cAxleWorld.translation;
			G3D::Vector3 perp = cAxleWorld.rotation.getColumn(0);
			G3D::Vector3 marker0 = perp * 10.0f + center0;

			Point* pMarker0 = getKernel()->newPoint(b0, marker0);
			Point* pMarker1 = getKernel()->newPoint(b1, marker0);

			RBXASSERT(!rotateConnector);
			RotateConnector* connector = new RotateConnector(getPoint(0), getPoint(2), pMarker0, pMarker1, getJointK(), getTorqueArmLength());
			rotateConnector = connector;
			addToMultiJoint(pMarker0, pMarker1, connector);
		}
	}


}
