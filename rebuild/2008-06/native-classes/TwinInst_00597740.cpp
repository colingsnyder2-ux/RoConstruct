// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 00597740: Value::genericConvert<TextureId> (inactive, draft)
#include "reflection/type.h"
#include "util/Sound.h"
#include "util/TextureId.h"
#include "util/Utilities.h"
#include "G3D/format.h"
#include "AppUnit594_2008/TextureIdType2008.h"
#include <stdexcept>

namespace RBX
{
	namespace Reflection
	{
		template<>
		TextureId& Value::genericConvert<TextureId>()
		{
			TextureId* id = boost::any_cast<TextureId>(&value);
			if (id)
				return *id;
			if (isType<std::string>())
			{
				Soundscape::SoundId v;
				if (StringConverter<Soundscape::SoundId>::convertToValue(*boost::any_cast<std::string>(&value), v))
				{
					value = v;
					_type = &Type::singleton<ContentId>();
					return *boost::any_cast<TextureId>(&value);
				}
			}
			throw std::runtime_error(G3D::format("Unable to cast %s to %s", _type->tag.name.c_str(), Type::singleton<ContentId>().tag.name.c_str()));
		}
	}
}
