// from server: 39% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client RbxView/PBBMesh.cpp

// Candidate translation unit (score above; library headers required).
#include "PBBMesh.h"

#include "QuadVolume.h"

#include <G3D/Vector3int16.h>

// SIZE 0x28
class PBBBuilder : public RBX::View::LevelBuilder
{
private:
	G3D::Vector3int16 strips; // 0x20

public:
	PBBBuilder(
		G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>& level,
		G3D::Vector3 size,
		RBX::View::RenderSurfaceTypes surfaceTypes
	);

protected:
	virtual void buildTop(Purpose purpose);    // vtable+0x04
	virtual void buildBottom(Purpose purpose); // vtable+0x08
	virtual void buildLeft(Purpose purpose);   // vtable+0x0c
	virtual void buildRight(Purpose purpose);  // vtable+0x10
	virtual void buildFront(Purpose purpose);  // vtable+0x14
	virtual void buildBack(Purpose purpose);   // vtable+0x18
};

DECOMP_SIZE_ASSERT(PBBBuilder, 0x28)

// STUB: WEBSERVICE 0x1017abc0
PBBBuilder::PBBBuilder(
	G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>& level,
	G3D::Vector3 size,
	RBX::View::RenderSurfaceTypes surfaceTypes
)
	: RBX::View::LevelBuilder(level, size, surfaceTypes), strips(0, 0, 0)
{
	strips.x = G3D::max(1, (int) (size.x / 6.0));
	strips.y = G3D::max(1, (int) (size.y / 6.0));
	strips.z = G3D::max(1, (int) (size.z / 6.0));

	strips.x = G3D::min(4, (int) strips.x);
	strips.y = G3D::min(4, (int) strips.y);
	strips.z = G3D::min(4, (int) strips.z);
}

// STUB: WEBSERVICE 0x1017d7c0
void PBBBuilder::buildTop(Purpose)
{
	STUB(0x1017d7c0);
}

// STUB: WEBSERVICE 0x1017d820
void PBBBuilder::buildBottom(Purpose)
{
	STUB(0x1017d820);
}

// STUB: WEBSERVICE 0x1017d880
void PBBBuilder::buildLeft(Purpose)
{
	STUB(0x1017d880);
}

// STUB: WEBSERVICE 0x1017d8e0
void PBBBuilder::buildRight(Purpose)
{
	STUB(0x1017d8e0);
}

// STUB: WEBSERVICE 0x1017d940
void PBBBuilder::buildFront(Purpose)
{
	STUB(0x1017d940);
}

// STUB: WEBSERVICE 0x1017d9a0
void PBBBuilder::buildBack(Purpose)
{
	STUB(0x1017d9a0);
}

namespace RBX {
namespace View {

// STUB: WEBSERVICE 0x1017da00
PBBMesh::PBBMesh(const G3D::Vector3& size, NormalId decalFace)
{
	Render::Mesh::LevelRef level = new Render::Mesh::Level(G3D::RenderDevice::QUADS);

	levels.append(level);

	PBBBuilder builder(level, size, RenderSurfaceTypes());

	builder.buildFace(decalFace, LevelBuilder::Decal);
}

// STUB: WEBSERVICE 0x1017db60
PBBMesh::PBBMesh(const G3D::Vector3& size, NormalId, const G3D::Vector2&)
{
	Render::Mesh::LevelRef level = new Render::Mesh::Level(G3D::RenderDevice::QUADS);

	levels.append(level);

	PBBBuilder builder(level, size, RenderSurfaceTypes());
}

template PBBMesh* MeshFactory<PBBMesh, 4>::createDecal(const G3D::Vector3&, NormalId);

template PBBMesh* MeshFactory<PBBMesh, 4>::createTexture(const G3D::Vector3&, NormalId, const G3D::Vector2&);

} // namespace View
} // namespace RBX
