// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// 0056e080: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "reflection/reflection.h"
#include "v8tree/Instance.h"

namespace boost {

template<>
shared_ptr<RBX::Reflection::DescribedBase> __cdecl static_pointer_cast<RBX::Reflection::DescribedBase, RBX::Instance>(const shared_ptr<RBX::Instance>& r)
{
	return shared_ptr<RBX::Reflection::DescribedBase>(r, boost::detail::static_cast_tag());
}

}
