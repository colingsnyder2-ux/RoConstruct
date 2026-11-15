// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::BallBallContact step path (inactive): computeIsColliding 00606e90 and stepContact 00606f80
// (vtable 008436bc slots 7 / 6). Flags: the sibling BlockBlockContactStep.cpp (same Contact unit 00606b00..00608950).
// numConnectors 0060cb60 / getConnector 0060cbc0 are already inline in native-headers/v8world/Contact2008.h (not
// duplicated here). Donor bodies: tools/rbxgs v8world/Contact.cpp BallBallContact::computeIsColliding / stepContact.
//
// Shared headers (as ContactUnit2008Contact.cpp includes them): the 2008 Body / GeoPair path of Connector2008.h
// (NATIVE_PRIMITIVE_NATIVE_BODY: ContactConnector::setBallBall -> GeoPair2008.h), Contact2008.h (BallBallContact,
// Contact::createConnector(Body*, Body*) 00606e00), Primitive2008.h (over IPipelined2008.h, inStage) and Ball2008.h.
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include <math.h>
#include "v8world/Contact2008.h"
#include "v8world/Primitive2008.h"
#include "v8kernel/Connector2008.h"
#include "v8kernel/Body2008.h"
#include "v8world/Ball2008.h"
#include "util/Math.h"

namespace RBX
{
	// 2008 Kernel stage type: Kernel::getStageType 0077d800 returns 7 and IPipelined::getKernel 00645850 pushes 7
	// (native-headers/v8world/CleanStage2008.h); the donor v8kernel/IStage.h numbers KERNEL_STAGE 8.
	static const IStage::StageType kernelStageType = static_cast<IStage::StageType>(7);

	// Donor v8world/Contact.h inline accessor declared in Contact2008.h (rbx_static_cast of getGeometry; no code of its
	// own).
	inline Ball* BallBallContact::ball(int i)
	{
		return static_cast<Ball*>(getPrimitive(i)->getGeometry());
	}

	// 00606e90: Geometry slot 4 getRadius of both balls, the Body pv translation +0xb8 read without updatePV
	// (Body2008.h getPVUnsafe), Math::longestVector3Component (std::max of the fabs), then magnitude.
	bool BallBallContact::computeIsColliding(float overlapIgnored)
	{
		float b0Radius = ball(0)->getRadius();
		float b1Radius = ball(1)->getRadius();

		G3D::Vector3 delta = getPrimitive(1)->getBody()->getPVUnsafe().position.translation
			- getPrimitive(0)->getBody()->getPVUnsafe().position.translation;
		float b0b1RadiusSum = b0Radius + b1Radius;

		if (b0b1RadiusSum > Math::longestVector3Component(delta))
			return delta.magnitude() < (b0b1RadiusSum - overlapIgnored);
		else
			return false;
	}

	// 00606f80: computeIsColliding called directly (not through the vtable), createConnector 00606e00, inline
	// setBallBall, else deleteAllConnectors through slot 5.
	bool BallBallContact::stepContact()
	{
		if (BallBallContact::computeIsColliding(0.0f))
		{
			if (inStage(kernelStageType))
			{
				if (!ballBallConnector)
					ballBallConnector = createConnector(getPrimitive(0)->getBody(), getPrimitive(1)->getBody());

				ballBallConnector->setBallBall(ball(0)->getRadius(), ball(1)->getRadius());
			}
			return true;
		}
		else
		{
			deleteAllConnectors();
		}

		return false;
	}
}
