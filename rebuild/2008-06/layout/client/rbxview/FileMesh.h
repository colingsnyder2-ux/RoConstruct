// =============================================================================
// FileMesh.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rbxview/FileMesh.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "ViewNew/RenderBaseMesh.h"
#include "util/NativeContentProvider.h"
#include "util/MeshId.h"

namespace RBX
{
	namespace ViewNew
	{
		class FileMesh : public RenderBase::Mesh
		{
		public:
			FileMesh() {}
			bool loadFromMeshFile(ContentProvider* provider, const G3D::Vector3& scale, MeshId meshFile);  // 00500780
		public:
			static G3D::ReferenceCountedPointer<RenderBase::Mesh> create(ContentProvider* provider, const G3D::Vector3& scale, MeshId meshFile);  // 00500b90
		};
	}
}
