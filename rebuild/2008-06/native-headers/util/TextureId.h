#pragma once
#include "util/ContentProvider.h"

namespace RBX
{
	class TextureId : public ContentId
	{
	public:
		TextureId()
			: ContentId()
		{
		}
		TextureId(const std::string& id)
			: ContentId(id)
		{
		}
		TextureId(const char* id)
			: ContentId(id)
		{
		}
		TextureId(const ContentId& id)
			: ContentId(id)
		{
		}
	};
}
// 2008-06 native header port of rbxgs App/include/util/TextureId.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
