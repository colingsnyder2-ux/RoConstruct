#pragma once

#include "reflection/reflection.h"
#include "v8tree/Instance.h"
#include "util/NormalId.h"
#include "util/IRenderable.h"

namespace RBX 
{
	extern char sFaceInstance[];

	class FaceInstance : public Reflection::Described<FaceInstance, sFaceInstance, Instance>, public IRenderable 
	{
	private:
		NormalId face;
	public:
		static const Reflection::EnumPropDescriptor<FaceInstance,NormalId> prop_Face;
		FaceInstance();
		NormalId getFace() const;
		void setFace(NormalId);
		// 005ef400: overrides IRenderable::render3dSelect (00458e90). The original vtables of FaceInstance (00840698
		// slot 4 at 008406a8) and of the Decal/Texture family (0083238c, 008324d8, 0083264c, 00832730, 00832808,
		// 008328e8) all reference 005ef400, not the empty IRenderable body.
		virtual void render3dSelect(Adorn* adorn, SelectState selectState);
	protected:
		virtual bool askSetParent(const Instance*) const;
	};
};