// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: sub_004a5d40 (placeholder name for 004a5d40 from the identity tier; body byte-proved by the placeholder lane, includes as the lane resolved them)
#include "reflection/object.h"
#include "reflection/member.h"
#include "reflection/descriptor.h"
#include "util/Name.h"

namespace RBX {

std::string __stdcall sub_004a5d40(const Reflection::MemberDescriptor* desc)
{
	return desc->owner.name.toString() + ":" + desc->name.toString();
}

}
