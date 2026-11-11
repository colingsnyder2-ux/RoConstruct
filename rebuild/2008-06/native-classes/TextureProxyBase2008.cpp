// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// RBX::TextureProxyBase and the (TextureManager&, name, tiled) constructors of Render::TextureProxy /
// RenderNew::TextureProxy (2008-06, inactive native recovery).
//
// These bodies sit in an unoptimized (/Od /GS) block of the image, 00551b30..00551f2f, next to the texture-proxy
// factories 00551920 / 00551a30 (not recovered here: they select on an unnamed global 00942ec4). The optimized RenderLib
// units call them out of line (007ade34 / 007b8474 -> 00551bf0, 007b8fc1 -> 00551b30, 007ae4c1 -> 00551e30).
// >>> native-status (generated) -- do not edit >>>
// TextureProxyBase2008 | 2008-06 | 7 byte-exact, inactive (not link-selected)
// 7/9 mapped addresses byte-exact | 2 unproved | no mapped strings | by colin (+3) (mixed 5)
// <<< native-status | src 4052977e | roc native-status --write
#include "RenderLib/TextureProxy2008.h"

namespace RBX
{
	TextureProxyBase::TextureProxyBase()
		: intProperty(1),
		  floatProperty(1.0f)
	{
	}

	void TextureProxyBase::setIntProperty(int value)
	{
		intProperty = value;
	}

	int TextureProxyBase::getIntProperty() const
	{
		return intProperty;
	}

	void TextureProxyBase::setFloatProperty(float value)
	{
		floatProperty = value;
	}

	float TextureProxyBase::getFloatProperty() const
	{
		return floatProperty;
	}

	namespace Render
	{
		TextureProxy::TextureProxy(G3D::TextureManager& textureManager, const std::string& filename, bool tiled)
			: loaded(false),
			  textureManager(&textureManager),
			  tiled(tiled)
		{
			this->filename = filename;
		}
	}

	namespace RenderNew
	{
		TextureProxy::TextureProxy(G3D::TextureManager& textureManager, const std::string& filename, bool tiled)
			: loaded(false),
			  textureManager(&textureManager),
			  tiled(tiled)
		{
			this->filename = filename;
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class G3D::ReferenceCountedPointer<RBX::RenderNew::TextureProxy>;
