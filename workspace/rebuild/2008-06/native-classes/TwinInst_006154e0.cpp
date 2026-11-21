// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 006154e0: Value::genericConvert<MeshId> (inactive, draft)
#include "reflection/type.h"
#include "util/MeshId.h"
#include "util/Utilities.h"
#include "G3D/format.h"
#include "util/MeshIdType.h"
#include <stdexcept>

namespace RBX
{
	namespace Reflection
	{
		template<>
		MeshId& Value::genericConvert<MeshId>()
		{
			MeshId* id = boost::any_cast<MeshId>(&value);
			if (id)
				return *id;
			if (isType<std::string>())
			{
				MeshId v;
				if (StringConverter<MeshId>::convertToValue(*boost::any_cast<std::string>(&value), v))
				{
					value = v;
					_type = &Type::singleton<MeshId>();
					return *boost::any_cast<MeshId>(&value);
				}
			}
			throw std::runtime_error(G3D::format("Unable to cast %s to %s", _type->tag.name.c_str(), Type::singleton<MeshId>().tag.name.c_str()));
		}
	}
}