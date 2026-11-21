// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#undef _RELEASEASSERT
// 2008-06 joint ordering helpers of the JointStage / TreeStage object (00668bb0..00668e20; flags and headers copied
// from AppUnit668TreeStage2.cpp, which declares JointSort::lighterJoint 00668e20, their caller). Identities: registry
// ?biggerJointGuid@RBX@@YAHPBVJoint@1@0@Z 00668c60 and ?biggerJointSize@RBX@@YAHPBVJoint@1@0@Z 00668d70. Body shape:
// the donor v8world/ClumpStage2.cpp helpers (openrbx), checked against the 2008 bytes: Joint primitives at +0x0c /
// +0x10, Primitive::getGuid 005e7440 (out of line), Guid::compare(a0, a1, b0, b1) 005a83b0, the size helper 00668bb0.
#include <algorithm>
#include <G3D/g3dmath.h>
#include "AppUnit668/TreeStage.h"
#include "AppUnit66C/AssemblyStage.h"
#include "v8kernel/Body2008.h"
#include "v8world/Joints2008.h"
#include "v8world/Primitive2008.h"
#include "util/Guid.h"

namespace RBX
{
	float getPrimitiveSize(const Primitive* p); // 00668bb0 (registry func_00668bb0; donor name)

	// 00668c60
	int biggerJointGuid(const Joint* j0, const Joint* j1)
	{
		const Guid* guid0 = &j0->getPrimitive(0)->getGuid();
		const Guid* other0 = &j1->getPrimitive(0)->getGuid();
		const Guid* guid1 = j0->getPrimitive(1) != NULL ? &j0->getPrimitive(1)->getGuid() : NULL;
		const Guid* other1 = j1->getPrimitive(1) != NULL ? &j1->getPrimitive(1)->getGuid() : NULL;

		return Guid::compare(guid0, guid1, other0, other1);
	}

	// 00668d70
	int biggerJointSize(const Joint* j0, const Joint* j1)
	{
		float size0 = getPrimitiveSize(j0->getPrimitive(0));

		if (j0->getPrimitive(1) != NULL)
		{
			size0 = G3D::max(size0, getPrimitiveSize(j0->getPrimitive(1)));
		}

		float size1 = getPrimitiveSize(j1->getPrimitive(0));

		if (j1->getPrimitive(1) != NULL)
		{
			size1 = G3D::max(size1, getPrimitiveSize(j1->getPrimitive(1)));
		}

		if (size1 < size0)
		{
			return 1;
		}

		if (size0 < size1)
		{
			return -1;
		}

		return 0;
	}

	// Unit-local declaration, exactly as in AppUnit668TreeStage2.cpp (no native header declares JointSort).
	class JointSort
	{
	public:
		static bool lighterJoint(const Joint* a, const Joint* b);   // 00668e20
	};

	// 00668e20 (registry ?lighterJoint@JointSort@RBX@@SA_NPBVJoint@2@0@Z, caller TreeStage 00669xxx): equal joints are
	// not lighter; getJointType (Joint vtable slot 5, +0x14) decides first (setl), then biggerJointSize 00668d70, then
	// biggerJointGuid 00668c60, then the pointer order (cmp/sbb/neg). Donor shape: native-world ClumpStage.cpp.
	bool JointSort::lighterJoint(const Joint* j0, const Joint* j1)
	{
		if (j0 == j1)
		{
			return false;
		}

		Joint::JointType type0 = j0->getJointType();
		Joint::JointType type1 = j1->getJointType();

		if (type0 != type1)
		{
			return type0 < type1;
		}

		int bigger = biggerJointSize(j0, j1);

		if (bigger == 1)
		{
			return true;
		}

		if (bigger == -1)
		{
			return false;
		}

		bigger = biggerJointGuid(j0, j1);

		if (bigger == 1)
		{
			return true;
		}

		if (bigger == -1)
		{
			return false;
		}

		return j0 < j1;
	}
}
