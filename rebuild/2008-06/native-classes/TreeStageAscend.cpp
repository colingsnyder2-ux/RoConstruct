// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#undef _RELEASEASSERT
// 2008-06 native RBX::TreeStage::ascend (inactive). Flags and includes copied from AppUnit668TreeStage2.cpp, whose
// reconcile 00669090 is the only caller (four calls); kept in its own unit so reconcile's /Ob2 build does not see it.
#include "AppUnit668/TreeStage.h"
#include "v8kernel/Body2008.h"
#include "v8world/Joints2008.h"
#include "v8world/Primitive2008.h"

namespace RBX
{
	class JointSort
	{
	public:
		static bool lighterJoint(const Joint* a, const Joint* b);   // 00668e20
	};

	// 00668ea0 (registry func_00668ea0; declared INFERRED in AppUnit668/TreeStage.h): walks p's joints
	// (getFirstJoint 005e7b90 / getNextJoint 005e7ba0) for the active one (+0x24) whose top primitive
	// (getTopPrimitive 005e7490) is p, records it as the lightest when none is recorded yet or
	// lighterJoint(lightest, j) holds (00668ef7: the recorded joint is the first argument), and returns the joint's
	// other primitive; NULL when no such joint exists.
	Primitive* TreeStage::ascend(int side, Primitive* p, Joint*& lightest, int& lightestSide)
	{
		for (Joint* j = p->getFirstJoint(); j; j = p->getNextJoint(j))
		{
			if (j->getActive())
			{
				// 00668eba: the other primitive is a conditional expression (prim0 kept in eax, moved to ebx on
				// the non-matching path), and p is the left operand of the top compare (00668ed1: cmp edi, eax).
				Primitive* other = (p == j->getPrimitive(0)) ? j->getPrimitive(1) : j->getPrimitive(0);
				if (p == getTopPrimitive(j))
				{
					if (!lightest || JointSort::lighterJoint(lightest, j))
					{
						lightest = j;
						lightestSide = side;
					}
					return other;
				}
			}
		}
		return 0;
	}
}
