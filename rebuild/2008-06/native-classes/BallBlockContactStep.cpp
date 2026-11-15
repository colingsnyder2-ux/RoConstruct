// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::BallBlockContact step path (inactive): stepContact 00607150 (vtable 008436e8 slot 6). Flags: the
// sibling BallBallContactStep.cpp (same Contact unit 00606b00..00608950). deleteAllConnectors 0060cb50 is already
// inline in native-headers/v8world/Contact2008.h (folded with BallBallContact's) and is not duplicated here. Donor
// body: tools/rbxgs v8world/Contact.cpp BallBlockContact::stepContact.
//
// Shared headers (as ContactUnit2008Contact.cpp includes them): the 2008 Body / GeoPair path of Connector2008.h
// (NATIVE_PRIMITIVE_NATIVE_BODY: ContactConnector::setBallBlock -> GeoPair2008.h), Contact2008.h (computeIsColliding
// (int&, ...) 00607020 and the donor accessors), Primitive2008.h (over IPipelined2008.h, inStage), Ball2008.h and
// Block2008.h (getBallBlockInfo 00647a20 / getBallInsideInfo 00647ab0).
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8world/Contact2008.h"
#include "v8world/Primitive2008.h"
#include "v8kernel/Connector2008.h"
#include "v8world/Ball2008.h"
#include "v8world/Block2008.h"
#include <G3D/Vector3int16.h>

namespace RBX
{
	// 2008 Kernel stage type: Kernel::getStageType 0077d800 returns 7 and IPipelined::getKernel 00645850 pushes 7
	// (native-headers/v8world/CleanStage2008.h); the donor v8kernel/IStage.h numbers KERNEL_STAGE 8.
	static const IStage::StageType kernelStageType = static_cast<IStage::StageType>(7);

	// Donor v8world/Contact.h inline accessors declared in Contact2008.h (rbx_static_cast of getGeometry; no code of
	// their own).
	inline Ball* BallBlockContact::ball()
	{
		return static_cast<Ball*>(ballPrim()->getGeometry());
	}
	inline Block* BallBlockContact::block()
	{
		return static_cast<Block*>(blockPrim()->getGeometry());
	}

	// 00607150: computeIsColliding(int&, Vector3int16&, Vector3&, float) 00607020 called directly with a zeroed
	// clip / projection, createConnector 00606e00, Block::getBallBlockInfo 00647a20 or getBallInsideInfo 00647ab0,
	// then the inline setBallBlock; else deleteAllConnectors through slot 5.
	bool BallBlockContact::stepContact()
	{
		G3D::Vector3int16 clip(0, 0, 0);
		G3D::Vector3 projectionInBlock(0.0f, 0.0f, 0.0f);
		int onBorder;

		if (BallBlockContact::computeIsColliding(onBorder, clip, projectionInBlock, 0.0f))
		{
			if (inStage(kernelStageType))
			{
				if (!ballBlockConnector)
					ballBlockConnector = createConnector(ballPrim()->getBody(), blockPrim()->getBody());

				const G3D::Vector3* offset;
				NormalId normId;
				GeoPairType ballInsideType;

				if (onBorder)
					ballInsideType = block()->getBallBlockInfo(onBorder, clip, offset, normId);
				else
					ballInsideType = block()->getBallInsideInfo(projectionInBlock, offset, normId);

				ballBlockConnector->setBallBlock(ball()->getRadius(), offset, normId, ballInsideType);
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
