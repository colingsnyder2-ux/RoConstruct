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
		// INFERRED: 004f0390 reads FaceInstance::face directly at +0x140.
		NormalId getFace() const { return face; }
		void setFace(NormalId);
	protected:
		virtual bool askSetParent(const Instance*) const;
	};
};