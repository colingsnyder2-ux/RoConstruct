// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00585310: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "v8datamodel/PartInstance.h"

namespace boost {

template<class Target, class Source>
Target polymorphic_cast(Source* x);

template<>
RBX::PartInstance* polymorphic_cast<RBX::PartInstance*, RBX::Reflection::DescribedBase>(RBX::Reflection::DescribedBase* x)
{
	RBX::PartInstance* tmp = dynamic_cast<RBX::PartInstance*>(x);
	if (tmp == 0)
		throw std::bad_cast("bad cast");
	return tmp;
}

}
