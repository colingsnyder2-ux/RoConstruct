// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: sub_005a2330 (placeholder name for 005a2330 from the identity tier; body byte-proved by the placeholder lane, includes as the lane resolved them)
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"
#include "util/Name.h"

namespace RBX {

template<int N>
void __cdecl wrapper(Instance* instance);

template<int N>
void __cdecl wrapper(Instance* instance)
{
	if (PartInstance* part = dynamic_cast<PartInstance*>(instance))
		part->destroyJoints();
	else
		instance->for_eachChild(&wrapper<N>);
}

void __cdecl sub_005a2330(boost::shared_ptr<Instance> instance)
{
	Instance* raw = instance.get();
	PartInstance* part = dynamic_cast<PartInstance*>(raw);
	if (part)
		part->destroyJoints();
	else
		raw->for_eachChild(&wrapper<1>);
}

}
