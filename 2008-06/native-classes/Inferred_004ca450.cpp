// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 004ca450: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "v8tree/Instance.h"

namespace boost {
namespace _bi {

template boost::shared_ptr<const RBX::Instance>
list1<boost::arg<1> >::operator()<
	boost::shared_ptr<const RBX::Instance>,
	boost::shared_ptr<RBX::Instance> (__cdecl*)(RBX::Instance*),
	list1<RBX::Instance*&> >(
		type<boost::shared_ptr<const RBX::Instance> >,
		boost::shared_ptr<RBX::Instance> (__cdecl*&)(RBX::Instance*),
		list1<RBX::Instance*&>&,
		long);

}
}
