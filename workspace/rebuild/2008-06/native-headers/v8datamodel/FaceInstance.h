#pragma once
// >>> native-status (generated) -- do not edit >>>
// FaceInstance | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src bef9f5d1 | roc native-status --write

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
	protected:
		virtual bool askSetParent(const Instance*) const;
	};
};