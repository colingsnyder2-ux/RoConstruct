// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// RBX::Constants::getJointK, 2008-06 v8kernel Constants unit (after getKmsMaxJointForce 00649670).
// Identity: work/2008-06/identity-registry.json decorated-signature ?getJointK@Constants@RBX@@SA?BMABVVector3@G3D@@_N@Z;
// callers Primitive::computeJointK 005e7580. Body after the donor tools/rbxgs v8kernel/Constants.cpp:
// Math::sortVector3 005df1b0, the __forceinline getClippedSortedSize (Vector3::max against (1,1,1), inlined),
// getJointKMultiplier 00649390, scale 960000.0f (0084b038).
#include "v8kernel/Constants.h"
#include "util/Math.h"

namespace RBX
{
	__forceinline G3D::Vector3 getClippedSortedSize(const G3D::Vector3& v)
	{
		return v.max(G3D::Vector3(1.0f, 1.0f, 1.0f));
	}

	// 00649730
	const float Constants::getJointK(const G3D::Vector3& gridSize, bool ball)
	{
		G3D::Vector3 sortedSize = Math::sortVector3(gridSize);
		G3D::Vector3 clippedSize = getClippedSortedSize(sortedSize);

		float JointKMultiplier = getJointKMultiplier(clippedSize, ball);

		if (sortedSize.x < 1.0)
			JointKMultiplier *= sortedSize.x;

		return JointKMultiplier * 960000.0f;
	}
}
