// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00492a90: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "Network/Player.h"

namespace boost {

template<class Target, class Source>
Target polymorphic_cast(Source* x);

template<>
RBX::Network::Player* polymorphic_cast<RBX::Network::Player*, RBX::Reflection::DescribedBase>(RBX::Reflection::DescribedBase* x)
{
	RBX::Network::Player* tmp = dynamic_cast<RBX::Network::Player*>(x);
	if (tmp == 0)
		throw std::bad_cast("bad cast");
	return tmp;
}

}
