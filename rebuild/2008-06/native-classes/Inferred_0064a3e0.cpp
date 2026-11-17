// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: RBX::CleanStage::sub_0064a3e0 (placeholder name for 0064a3e0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "v8world/CleanStage2008.h"
#include "v8world/Primitive2008.h"
#include "v8world/JointStage2008.h"

namespace RBX {

void CleanStage::sub_0064a3e0(Primitive* p)
{
	p->putInStage(this);
	reinterpret_cast<JointStage*>(getDownstream())->onPrimitiveAdded(p);
}

}
