// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native Value::convert<TextureId> (inactive); flags and includes copied from MeshIdValueConvert.cpp (the MeshId
// twin 006156c0) and TextureIdValueGenericConvert.cpp (genericConvert<TextureId> 00597740, the tail callee here).
#include "reflection/type.h"
#include "util/TextureId.h"
#include "AppUnit594_2008/TextureIdType2008.h"

namespace RBX
{
	namespace Reflection
	{
		// 00597a90 (191 B, unit of the Decal / TextureId reflection rows 00597620..00597b50): a held std::string (typeid
		// 0092bef8) becomes TextureId(any_cast<std::string>) (ContentId(const std::string&) 00615440, any(const TextureId&)
		// 00597620 swapped in, holder deleted through slot 0), the Type singleton is stored (0056cd80: the ContentId
		// singleton, as in the MeshId twin 006156c0), then genericConvert<TextureId> 00597740.
		template<>
		TextureId& Value::convert<TextureId>()
		{
			if (isType<std::string>())
			{
				value = TextureId(boost::any_cast<std::string>(value));
				_type = &Type::singleton<ContentId>();
			}
			return genericConvert<TextureId>();
		}
	}
}
