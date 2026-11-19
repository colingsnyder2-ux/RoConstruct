// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 0056f8c0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "reflection/type.h"
#include "v8tree/Instance.h"
#include "util/Name.h"

namespace RBX { namespace Reflection {

template<>
boost::shared_ptr<Instance>& Value::convert<boost::shared_ptr<Instance> >()
{
	if (isType<void>())
	{
		value = boost::shared_ptr<Instance>();
		_type = &Type::singleton<boost::shared_ptr<Instance> >();
	}
	if (isType<boost::shared_ptr<DescribedBase> >())
	{
		boost::shared_ptr<DescribedBase>* base = boost::any_cast<boost::shared_ptr<DescribedBase> >(&value);
		if (base)
		{
			Instance* instance = dynamic_cast<Instance*>(base->get());
			if (!instance)
				throw std::runtime_error("Unable to cast value to Object");

			value = shared_from(instance);
		}
		else
		{
			value = boost::shared_ptr<Instance>();
		}

		_type = &Type::singleton<boost::shared_ptr<Instance> >();
	}

	boost::shared_ptr<Instance>* val = boost::any_cast<boost::shared_ptr<Instance> >(&value);
	if (!val)
		throw std::runtime_error("Unable to cast value to Object");

	return *val;
}

}}
