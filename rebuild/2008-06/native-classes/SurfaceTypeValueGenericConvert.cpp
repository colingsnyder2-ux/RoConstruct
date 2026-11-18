// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 005eef20: Value::genericConvert<SurfaceType> (inactive)
#include "reflection/type.h"
#include "util/SurfaceType.h"
#include "util/Utilities.h"
#include "G3D/format.h"
#include "util/SurfaceTypeType.h"
#include <stdexcept>

namespace RBX
{
	namespace Reflection
	{
		template<>
		SurfaceType& Value::genericConvert<SurfaceType>()
		{
			SurfaceType* id = boost::any_cast<SurfaceType>(&value);
			if (id)
				return *id;
			if (isType<std::string>())
			{
				boost::any_cast<std::string>(&value);
			}
			throw std::runtime_error(G3D::format("Unable to cast %s to %s", _type->tag.name.c_str(), Type::singleton<SurfaceType>().tag.name.c_str()));
		}
	}
}