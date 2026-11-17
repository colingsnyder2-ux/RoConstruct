// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_005eecc0 (placeholder name for 005eecc0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {

void __stdcall sub_005eecc0(Reflection::DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder)
{
	Surfaces& s = static_cast<PartInstance*>(instance)->getSurfaces();
	s.readProperties(element, binder);
}

}
