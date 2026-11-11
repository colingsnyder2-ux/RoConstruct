#pragma once
// >>> native-status (generated) -- do not edit >>>
// SpecialShape | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 25ab90d5 | roc native-status --write
// 2008-06 native RBX::SpecialShape (class name "SpecialMesh"; inactive). Shape after the donor
// tools/rbxgs v8datamodel/custommesh.h; every field, virtual and descriptor below is read from the 2008-06 binary:
//   RTTI       vtable 00833584 .?AVSpecialShape@RBX@@ -> DescribedCreatable<SpecialShape, Instance, sSpecialShape>
//              (21 bases, no mesh base class; name mangled $1?sSpecialShape@2@3PADA, a char array in .data at
//              0094afac holding "SpecialMesh").
//   size       0x18c: Creatable<Instance>::create<SpecialShape> 0041ec30 allocates 0x18c.
//   fields     constructor 0059fbb0: +0x130 int 0 (meshType), +0x134/+0x138/+0x13c float 1 (scale),
//              +0x140 and +0x160 std::string + Name* (getNullName) pairs, +0x180/+0x184/+0x188 float 1
//              (vertColor), then setName("Mesh"); destructor 0059fd70 destroys +0x160 then +0x140.
//              getTextureId 004e5f50 copies +0x140, getMeshId 004e5f20 copies +0x160; getScale 0068e8b0
//              (+0x134), getVertColor 004e5ba0 (+0x180), getMeshType 00565e30 (ICF-shared int getter, +0x130).
//   vtable     slot 3 askSetParent 0062e190 (ICF-shared dynamic_cast to PartInstance); askAddChild stays 0068e880.
//   enum       EnumDesc<MeshType> 0059f630 ("MeshType"): Head 0, Torso 1, Wedge 2, Brick 6, Sphere 3,
//              Cylinder 4, FileMesh 5 (setMeshId/setTextureId 0059ffd0/005a0030 store 5).
//   descriptors (dynamic initializers 007f4c20..007f4d20 in this order, "Data" 00822490, STANDARD):
//              desc_meshType 00976858 (EnumPropDescriptor), desc_scale 0097683c, desc_meshId 00976820,
//              desc_textureId 00976804, desc_vertColor 0097687c.
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
