// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include /DNATIVE_KERNEL_STAGE_NUMBERING
// INFERRED: RBX::TreeStage::sub_00669090 (placeholder name for 00669090 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#define NATIVE_KERNEL_STAGE_NUMBERING
#include "AppUnit668/TreeStage.h"

void RBX::TreeStage::sub_00669090(Primitive* left, Primitive* right, int leftDepth, int rightDepth, void* context0, void* context1)
{
	for (;;)
	{
		if (leftDepth != rightDepth)
		{
			if (leftDepth > rightDepth)
			{
				--leftDepth;
				left = ascend(false, left, context0, context1);
			}
			else
			{
				--rightDepth;
				right = ascend(true, right, context0, context1);
			}
		}
		else
		{
			if (left == right)
				return;

			left = left ? ascend(false, left, context0, context1) : 0;
			Primitive* nextRight = right ? ascend(true, right, context0, context1) : 0;
			--rightDepth;
			--leftDepth;
			right = nextRight;
		}
	}
}
