// =============================================================================
// FaceInstance.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/FaceInstance.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
		virtual void render3dSelect(Adorn* adorn, SelectState selectState);
	protected:
		virtual bool askSetParent(const Instance*) const;
	};
};
