// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::MD5Hasher::convertToLegacyHash (inactive). Identity: 0055bf20 is called only by
// TextXmlParser::parse 0058f6c0 (at 0058fb6b) with a by-value std::string copy of the registered content's hash, and its
// body is the openrbx 2007 MD5Hasher::convertToLegacyHash (ROBLOX 0x0057d850): for i = 0..30 step 2, append hash[i]
// unless it is '0', then hash[i + 1] (checked operator[] -> _invalid_parameter_noinfo, operator+=(char)).
#include "util/ContentProvider.h"
#include <string>

namespace RBX
{
#ifdef MD5HASHER_HEADER_DECLARES_CONVERTTOLEGACYHASH
	// Pending: core util/ContentProvider.h declares no static MD5Hasher::convertToLegacyHash(std::string). With that one
	// declaration added after create() (scratch copy, batch 43) this body is byte-identical to 0055bf20 (215 B).
	// 0055bf20
	std::string MD5Hasher::convertToLegacyHash(std::string hash)
	{
		std::string result;
		for (int i = 0; i < 32; i += 2)
		{
			if (hash[i] != '0')
				result += hash[i];
			result += hash[i + 1];
		}
		return result;
	}
#endif
}
