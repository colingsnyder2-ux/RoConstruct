// =============================================================================
// custommesh.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/custommesh.h
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

namespace RBX
{
	extern char sSpecialShape[];

	class SpecialShape : public DescribedCreatable<SpecialShape, Instance, sSpecialShape>
	{
	public:
		enum MeshType
		{
			HEAD_MESH,
			TORSO_MESH,
			WEDGE_MESH,
			SPHERE_MESH,
			CYLINDER_MESH,
			FILE_MESH,
			BRICK_MESH
		};

	private:
		MeshType meshType;
		G3D::Vector3 scale;
		TextureId textureId;
		MeshId meshId;
		G3D::Vector3 vertColor;

	public:
		SpecialShape();

		const MeshType getMeshType() const
		{
			return meshType;
		}

		void setMeshType(MeshType value);

		const G3D::Vector3& getScale() const
		{
			return scale;
		}

		void setScale(const G3D::Vector3& value);

		const G3D::Vector3& getVertColor() const
		{
			return vertColor;
		}

		void setVertColor(const G3D::Vector3& value);
		const float getAlpha() const;
		const MeshId getMeshId() const;
		void setMeshId(const MeshId& value);
		const TextureId getTextureId() const;
		void setTextureId(const TextureId& value);
	protected:
		virtual bool askSetParent(const Instance* instance) const;
	};
}
