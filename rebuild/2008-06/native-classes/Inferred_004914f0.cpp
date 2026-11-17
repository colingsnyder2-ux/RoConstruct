// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 004914f0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "v8datamodel/ModelInstance.h"

namespace boost {

template<class Target, class Source>
Target polymorphic_cast(Source* x)
{
	Target tmp = dynamic_cast<Target>(x);
	if (tmp == 0)
		throw std::bad_cast("bad cast");
	return tmp;
}

template RBX::ModelInstance* polymorphic_cast<RBX::ModelInstance*, RBX::Reflection::DescribedBase>(RBX::Reflection::DescribedBase*);

}
