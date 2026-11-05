#pragma once
#include <string>
#include <G3D/ReferenceCount.h>
#include <G3D/Vector2.h>
#include <G3D/Color3.h>

namespace G3D
{
	class RenderDevice;
	class Texture;
}

namespace RBX
{
	namespace Render
	{
		class TextureProxy;
	}

	typedef G3D::ReferenceCountedPointer<class TextureProxyBase> TextureProxyBaseRef;

	class TextureProxyBase : public G3D::ReferenceCountedObject
	{
	public:
		std::string filename;   // 0x0c
		unsigned value28;       // 0x28: native ctor 00551bf0 initializes it to 1
		float scale;            // 0x2c: native ctor initializes it to 1.0f

	public:
		TextureProxyBase()
			: value28(1),
			  scale(1.0f)
		{
		}
		virtual ~TextureProxyBase()
		{
		}
	public:
		// Native 00551c70 / 00551c90 / 00551cb0 / 00551cd0 fill vtable slots 1-4.
		// value28 is named for its proven native offset; no original spelling evidence exists.
		virtual void setValue28(unsigned value) { value28 = value; }
		virtual unsigned getValue28() const { return value28; }
		virtual void setScale(float value) { scale = value; }
		virtual float getScale() const { return scale; }

		virtual G3D::Vector2 getSize() = 0;
		virtual G3D::ReferenceCountedPointer<G3D::Texture> resolve(G3D::RenderDevice* rd) = 0;
		virtual G3D::ReferenceCountedPointer<Render::TextureProxy> shade(const G3D::Color3& baseColor,
			const G3D::ReferenceCountedPointer<Render::TextureProxy>& baseTex) = 0;
	};
}
