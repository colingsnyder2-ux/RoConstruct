// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 005d4640: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "v8datamodel/Clothing.h"
#include "v8datamodel/PartInstance.h"
#include "util/Name.h"

namespace RBX {

PartInstance* __thiscall Clothing::getLeftLeg()
{
	boost::shared_ptr<PartInstance> leg;
	if (getParent())
		leg = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Left Leg"));
	return leg.get();
}

}
