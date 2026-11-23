// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native Value::convert<MeshId> (inactive); flags and includes copied from MeshIdValueGenericConvert.cpp
// (genericConvert<MeshId> 006154e0, the tail callee here).
#include "reflection/type.h"
#include "util/MeshId.h"
#include "util/MeshIdType.h"

namespace RBX
{
	namespace Reflection
	{
		// 006156c0 (registry func_006156c0; caller 0059f310): the MeshId twin of convert<ContentId> 0056eff0
		// (AppUnit564_2008ValueConvert.cpp). A held std::string (typeid 0092bef8) becomes MeshId(any_cast<std::string>)
		// (ContentId(const std::string&) 00615440, any(const MeshId&) 0059ef90 swapped in), the Type singleton is
		// stored (0056cd80: the ContentId singleton, as in the TextureId twin 00597a90), then genericConvert<MeshId> 006154e0.
		template<>
		MeshId& Value::convert<MeshId>()
		{
			if (isType<std::string>())
			{
				value = MeshId(boost::any_cast<std::string>(value));
				_type = &Type::singleton<ContentId>();   // 00615761: call 0056cd80 (registry singleton<ContentId>), not singleton<MeshId> 00615490
			}
			return genericConvert<MeshId>();
		}
	}
}
