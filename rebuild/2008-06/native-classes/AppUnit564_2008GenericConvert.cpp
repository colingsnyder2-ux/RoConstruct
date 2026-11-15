// 2008-06 native Value::genericConvert<T> instances of the reflection unit in 00564000..00570000 (inactive).
// Same body as the committed SoundValueGenericFloat.cpp (genericConvert<float> 0056d650, counted there): any_cast
// to T, else a string parsed through StringConverter<T>, else runtime_error("Unable to cast %s to %s").
#include "reflection/type.h"
#include "util/Utilities.h"
#include "util/ContentProvider.h"
#include "G3D/format.h"
#include "G3D/Vector3.h"
#include "G3D/Color3.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/Vector2int16.h"
#include "v8datamodel/BrickColor.h"
#include "v8tree/Instance.h"
#include <stdexcept>

namespace RBX
{
	namespace Reflection
	{
		template<class T>
		T& Value::genericConvert()
		{
			T* id = boost::any_cast<T>(&value);
			if (id)
				return *id;
			if (isType<std::string>())
			{
				T v;
				if (StringConverter<T>::convertToValue(*boost::any_cast<std::string>(&value), v))
				{
					value = v;
					_type = &Type::singleton<T>();
					return *boost::any_cast<T>(&value);
				}
			}
			throw std::runtime_error(G3D::format("Unable to cast %s to %s", _type->tag.c_str(), Type::singleton<T>().tag.c_str()));
		}

		template int& Value::genericConvert<int>();
		template bool& Value::genericConvert<bool>();
		template double& Value::genericConvert<double>();
		template G3D::Vector3& Value::genericConvert<G3D::Vector3>();
		template G3D::Color3& Value::genericConvert<G3D::Color3>();
		template BrickColor& Value::genericConvert<BrickColor>();
		template ContentId& Value::genericConvert<ContentId>();
		template G3D::CoordinateFrame& Value::genericConvert<G3D::CoordinateFrame>();
		template G3D::Vector2int16& Value::genericConvert<G3D::Vector2int16>();

		// 0056d090 (inline any_cast, so /Ob2; the /Ob1 build calls an out-of-line any_cast and is 103 B): any_cast to the Objects type (00938950) or runtime_error("Unable to cast value to Objects")
		template<>
		boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >& Value::convert<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >()
		{
			boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >* result =
				boost::any_cast<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >(&value);
			if (!result)
			{
				std::string message("Unable to cast value to Objects");
				throw std::runtime_error(message);
			}
			return *result;
		}
	}
}
