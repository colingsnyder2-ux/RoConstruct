// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 004914b0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "v8datamodel/MergeBinder2008.h"
#include "v8tree/Instance.h"
#include "util/Name.h"

namespace RBX {
namespace Reflection {

template<>
void RefPropDescriptor<Instance, Instance>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
	binder.announceIDREF(element, instance, this);
}

}
}
