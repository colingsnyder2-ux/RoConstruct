// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 0064a4d0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "v8world/JointStage2008.h"
#include "AppUnit658/Edge.h"
#include "v8world/CleanStage2008.h"
#include "util/Name.h"

namespace RBX {

void CleanStage::onEdgeAdded(Edge* edge)
{
	edge->putInStage(this);
	if (edge->getPrimitive(0) && edge->getPrimitive(1) && edge->getPrimitive(0) != edge->getPrimitive(1))
		static_cast<CleanStage*>(getDownstream())->onEdgeAdded(edge);
}

}
