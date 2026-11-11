// Rebuild glue: the RenderLib TextureProxy members its TextureProxy.cpp lacks (the module compiles that
// file; the rest of RenderLib needs Ogre). A proxy loads its file through the texture manager on first
// use; shaded and alpha-only variants use their root's texture (the per-pixel shading pass is not
// reconstructed yet). Behavioural reconstruction, not byte-verified.
#include "RenderLib/TextureProxy.h"

namespace RBX
{
	namespace Render
	{
		G3D::ReferenceCountedPointer<G3D::Texture> TextureProxy::resolve(G3D::RenderDevice* rd)
		{
			if (!loaded)
			{
				loaded = true;
				if (root.notNull())
					texture = root->resolve(rd);
				else if (textureManager && !filename.empty())
					texture = textureManager->loadTexture(filename, G3D::TextureFormat::AUTO,
														  tiled ? G3D::Texture::TILE : G3D::Texture::CLAMP);
			}
			return texture;
		}

		TextureProxy::~TextureProxy()
		{
		}
	}
}
