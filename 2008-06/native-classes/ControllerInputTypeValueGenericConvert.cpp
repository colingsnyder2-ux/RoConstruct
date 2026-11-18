// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 005ef020: Value::genericConvert<Controller::InputType> (inactive)
#include "reflection/type.h"
#include "util/Controller.h"
#include "util/Utilities.h"
#include "G3D/format.h"
#include "util/ControllerInputTypeType.h"
#include <stdexcept>

namespace RBX
{
	namespace Reflection
	{
		template<>
		Controller::InputType& Value::genericConvert<Controller::InputType>()
		{
			Controller::InputType* id = boost::any_cast<Controller::InputType>(&value);
			if (id)
				return *id;
			if (isType<std::string>())
			{
				Controller::InputType v;
				if (StringConverter<Controller::InputType>::convertToValue(*boost::any_cast<std::string>(&value), v))
				{
					value = v;
					_type = &Type::singleton<Controller::InputType>();
					return *boost::any_cast<Controller::InputType>(&value);
				}
			}
			throw std::runtime_error(G3D::format("Unable to cast %s to %s", _type->tag.name.c_str(), Type::singleton<Controller::InputType>().tag.name.c_str()));
		}
	}
}