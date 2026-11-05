// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-render roc_espclaude_e4709e8f6228ed75.cpp

// Candidate translation unit (score above; library headers required).
#define getIfResolved exeV0(); virtual void exeV1(); virtual void exeV2(); virtual void exeV3(); virtual void exeV4(); virtual void exeV5(); virtual void exeV6(); virtual void exeV7(); virtual G3D::ReferenceCountedPointer<G3D::Texture> getIfResolved
#include "RenderLib/TextureProxy.h"
#undef getIfResolved

namespace RBX
{
	namespace Render
	{
		G3D::ReferenceCountedPointer<G3D::Texture> TextureProxy::getIfResolved() const
		{
			return texture;
		}

		G3D::ReferenceCountedPointer<TextureProxy> TextureProxy::alphaOnlyVersion()
		{
			return new TextureProxy(this);
		}

		G3D::Vector2 TextureProxy::getSize()
		{
			G3D::ReferenceCountedPointer<G3D::Texture> t = getIfResolved();
			G3D::Vector2 out;
			if (t.notNull())
			{
				out.x = t->texelWidth();
				out.y = t->texelHeight();
			}
			else
			{
				out.y = 0.0f;
				out.x = 0.0f;
			}
			return out;
		}

		G3D::ReferenceCountedPointer<TextureProxy> TextureProxy::shade(const G3D::Color3& baseColor, const G3D::ReferenceCountedPointer<TextureProxy>& baseTex)
		{
			TextureProxy* newTex = new TextureProxy(baseTex);
			newTex->textureManager = textureManager;
			newTex->root = baseTex;
			newTex->shadeColor = baseColor;
			newTex->shadeTexture = this;
			return newTex;
		}
	}
}

