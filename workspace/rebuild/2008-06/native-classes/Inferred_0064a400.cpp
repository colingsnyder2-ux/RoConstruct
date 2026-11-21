// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: RBX::CleanStage::sub_0064a400 (placeholder name for 0064a400 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "v8world/CleanStage2008.h"
#include "v8world/JointStage2008.h"
#include "v8world/Primitive2008.h"

void RBX::CleanStage::sub_0064a400(RBX::Primitive* p)
{
	((RBX::JointStage*)getDownstream())->onPrimitiveRemoving(p);
	p->removeFromPipeline(this);
}
