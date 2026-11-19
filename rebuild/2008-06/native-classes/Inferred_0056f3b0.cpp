// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 0056f3b0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "reflection/type.h"
#include "v8tree/Instance.h"

namespace RBX {
class Instance;
namespace Reflection {
class DescribedBase;
}
}

extern boost::shared_ptr<RBX::Reflection::DescribedBase> __cdecl convert(const boost::shared_ptr<RBX::Instance>&);

namespace RBX {
namespace Reflection {

template<>
boost::shared_ptr<DescribedBase>& Value::convert<boost::shared_ptr<DescribedBase> >()
{
	typedef boost::shared_ptr<DescribedBase> Shared;
	typedef boost::shared_ptr<Instance> SourceShared;
	if (isType<void>()) {
		value = Shared();
		_type = &Type::singleton<Shared>();
	}
	if (isType<SourceShared>()) {
		SourceShared* source = boost::any_cast<SourceShared>(&value);
		if (source)
			value = ::convert(*source);
		else
			value = Shared();
		_type = &Type::singleton<Shared>();
	}
	Shared* result = boost::any_cast<Shared>(&value);
	if (!result)
		throw std::runtime_error("Unable to cast value to Object");
	return *result;
}

}
}
