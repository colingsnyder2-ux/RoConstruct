#include "util/Utilities.h"
#include "G3D/Vector3.h"
#include "reflection/type.h"
#include "util/Name.h"

namespace boost { template<> G3D::Vector3 any_cast<G3D::Vector3>(const any&); }

namespace RBX { namespace Reflection {

template<> std::string& Value::convert<std::string>() {
	if (isType<bool>()) {
		value = StringConverter<bool>::convertToString(cast<bool>());
		_type = &Type::singleton<bool>();
	}
	if (isType<int>()) {
		value = StringConverter<int>::convertToString(cast<int>());
		_type = &Type::singleton<int>();
	}
	if (isType<float>()) {
		value = StringConverter<float>::convertToString(cast<float>());
		_type = &Type::singleton<float>();
	}
	if (isType<double>()) {
		value = StringConverter<double>::convertToString(cast<double>());
		_type = &Type::singleton<double>();
	}
	if (isType<G3D::Vector3>()) {
		value = StringConverter<G3D::Vector3>::convertToString(boost::any_cast<G3D::Vector3>(static_cast<const boost::any&>(value)));
		_type = &Type::singleton<G3D::Vector3>();
	}
	std::string* result = boost::any_cast<std::string>(&value);
	if (!result) throw std::runtime_error("Unable to cast value to std::string");
	return *result;
}

} }

#include "v8tree/Instance.h"

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
