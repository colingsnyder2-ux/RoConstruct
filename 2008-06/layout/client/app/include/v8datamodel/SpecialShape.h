// =============================================================================
// SpecialShape.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/SpecialShape.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "v8tree/Instance.h"
#include "util/TextureId.h"
#include "util/MeshId.h"
#include <G3D/Vector3.h>

struct NativeSpecialShapeLayout;

namespace RBX
{
	extern char sSpecialShape[];

	class SpecialShape : public DescribedCreatable<SpecialShape, Instance, sSpecialShape>
	{
		friend struct ::NativeSpecialShapeLayout; // tests/NativeSpecialShapeLayout.cpp offset asserts
	public:
		enum MeshType
		{
			HEAD_MESH = 0,
			TORSO_MESH = 1,
			WEDGE_MESH = 2,
			SPHERE_MESH = 3,
			CYLINDER_MESH = 4,
			FILE_MESH = 5,
			BRICK_MESH = 6
		};

	private:
		MeshType meshType;         // +0x130
		G3D::Vector3 scale;        // +0x134
		TextureId textureId;       // +0x140
		MeshId meshId;             // +0x160
		G3D::Vector3 vertColor;    // +0x180

	public:
		SpecialShape();            // 0059fbb0 (destructor 0059fd70, deleting 0059fde0)

		const MeshType getMeshType() const          // 00565e30 (ICF-shared)
		{
			return meshType;
		}
		void setMeshType(MeshType value);           // 0059fee0

		const G3D::Vector3& getScale() const        // 0068e8b0
		{
			return scale;
		}
		void setScale(const G3D::Vector3& value);   // 0059ff10

		const G3D::Vector3& getVertColor() const    // 004e5ba0
		{
			return vertColor;
		}
		void setVertColor(const G3D::Vector3& value); // 0059ff70

		const MeshId getMeshId() const              // 004e5f20
		{
			return meshId;
		}
		void setMeshId(const MeshId& value);        // 0059ffd0

		const TextureId getTextureId() const        // 004e5f50
		{
			return textureId;
		}
		void setTextureId(const TextureId& value);  // 005a0030

	protected:
		virtual bool askSetParent(const Instance* instance) const; // 0062e190 (ICF-shared)
	};
}
