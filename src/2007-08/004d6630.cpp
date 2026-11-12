// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client RbxView/PBBMesh.cpp

// Candidate translation unit (score above; library headers required).
#include "PBBMesh.h"

#include "BrickMesh.h"
#include "QuadVolume.h"
#include "ViewBase.h"

#include <G3D/Vector2int16.h>
#include <G3D/Vector3int16.h>
#include <G3D/g3dmath.h>
#include <algorithm>

// SIZE 0xc
class Face
{
private:
	G3D::Vector2 perturbation; // 0x00
	bool bulge[2];             // 0x08

public:
	Face();

	void operator()(
		G3D::Vector3& vertex,
		G3D::Vector3& normal,
		G3D::Vector2& tex,
		const G3D::Vector3& radius,
		const G3D::Vector2int16& ivertex
	)
	{
		for (int i = 0; i < 2; ++i) {
			if (bulge[i]) {
				normal[i] = vertex[i] * perturbation[i] / radius[i];
			}
			else {
				normal[i] = perturbation[i];
			}
		}
	}
};

DECOMP_SIZE_ASSERT(Face, 0xc)

// SIZE 0xc
class TopBottom : public Face
{
public:
	void operator()(
		G3D::Vector3& vertex,
		G3D::Vector3& normal,
		G3D::Vector2& tex,
		const G3D::Vector3& radius,
		const G3D::Vector2int16& ivertex
	)
	{
		if (vertex.x > 0) {
			vertex.x -= RBX::View::BrickMesh::widthInset;
		}
		else {
			vertex.x += RBX::View::BrickMesh::widthInset;
		}
		if (vertex.y > 0) {
			vertex.y -= RBX::View::BrickMesh::widthInset;
		}
		else {
			vertex.y += RBX::View::BrickMesh::widthInset;
		}
		Face::operator()(vertex, normal, tex, radius, ivertex);
	}
};

DECOMP_SIZE_ASSERT(TopBottom, 0xc)

// SIZE 0xc
class Side : public Face
{
public:
	void operator()(
		G3D::Vector3& vertex,
		G3D::Vector3& normal,
		G3D::Vector2& tex,
		const G3D::Vector3& radius,
		const G3D::Vector2int16& ivertex
	)
	{
		if (vertex.x > 0) {
			vertex.x -= RBX::View::BrickMesh::widthInset;
		}
		else {
			vertex.x += RBX::View::BrickMesh::widthInset;
		}
		vertex.z -= RBX::View::BrickMesh::widthInset;
		Face::operator()(vertex, normal, tex, radius, ivertex);
	}
};

DECOMP_SIZE_ASSERT(Side, 0xc)

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

// FUNCTION: WEBSERVICE 0x1017abc0
// FUNCTION: ROBLOX 0x00484f50
PBBBuilder::PBBBuilder(
	G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>& level,
	G3D::Vector3 size,
	RBX::View::RenderSurfaceTypes surfaceTypes
)
	: RBX::View::LevelBuilder(level, size, surfaceTypes), strips(0, 0, 0)
{
	strips.x = std::max(1, (int) (size.x / 6.0));
	strips.y = std::max(1, (int) (size.y / 6.0));
	strips.z = std::max(1, (int) (size.z / 6.0));

	strips.x = std::min(4, (int) strips.x);
	strips.y = std::min(4, (int) strips.y);
	strips.z = std::min(4, (int) strips.z);
}

// FUNCTION: WEBSERVICE 0x1017ad40
// FUNCTION: ROBLOX 0x004850d0
Face::Face()
{
	perturbation.x =
		G3D::uniformRandom(-RBX::View::BrickMesh::normalPerturbation, RBX::View::BrickMesh::normalPerturbation);
	perturbation.y =
		G3D::uniformRandom(-RBX::View::BrickMesh::normalPerturbation, RBX::View::BrickMesh::normalPerturbation);
	bulge[0] = G3D::uniformRandom() > 0.5f;
	bulge[1] = G3D::uniformRandom() > 0.5f;
}

// FUNCTION: WEBSERVICE 0x1017d7c0
// FUNCTION: ROBLOX 0x00487bf0
void PBBBuilder::buildTop(Purpose purpose)
{
	buildFace<RBX::NORM_Y>(TopBottom(), 1, 1, purpose);
}

// FUNCTION: WEBSERVICE 0x1017d820
// FUNCTION: ROBLOX 0x00487c50
void PBBBuilder::buildBottom(Purpose purpose)
{
	buildFace<RBX::NORM_Y_NEG>(TopBottom(), 1, 1, purpose);
}

// FUNCTION: WEBSERVICE 0x1017d880
// FUNCTION: ROBLOX 0x00487cb0
void PBBBuilder::buildLeft(Purpose purpose)
{
	buildFace<RBX::NORM_X_NEG>(Side(), 1, 1, purpose);
}

// FUNCTION: WEBSERVICE 0x1017d8e0
// FUNCTION: ROBLOX 0x00487d10
void PBBBuilder::buildRight(Purpose purpose)
{
	buildFace<RBX::NORM_X>(Side(), 1, 1, purpose);
}

// FUNCTION: WEBSERVICE 0x1017d940
// FUNCTION: ROBLOX 0x00487d70
void PBBBuilder::buildFront(Purpose purpose)
{
	buildFace<RBX::NORM_Z_NEG>(Side(), 1, 1, purpose);
}

// FUNCTION: WEBSERVICE 0x1017d9a0
// FUNCTION: ROBLOX 0x00487dd0
void PBBBuilder::buildBack(Purpose purpose)
{
	buildFace<RBX::NORM_Z>(Side(), 1, 1, purpose);
}

namespace RBX {
namespace View {

// FUNCTION: WEBSERVICE 0x1017da00
// FUNCTION: ROBLOX 0x00487e30
PBBMesh::PBBMesh(const G3D::Vector3& size, NormalId decalFace)
{
	Render::Mesh::LevelRef level = new Render::Mesh::Level(G3D::RenderDevice::QUADS);

	levels.append(level);

	PBBBuilder builder(level, size, RenderSurfaceTypes());

	builder.buildFace(decalFace, LevelBuilder::Decal);
}

// FUNCTION: WEBSERVICE 0x1017db60
// FUNCTION: ROBLOX 0x00487f90
PBBMesh::PBBMesh(const G3D::Vector3& size, NormalId textureFace, const G3D::Vector2& studsPerTile)
{
	Render::Mesh::LevelRef level = new Render::Mesh::Level(G3D::RenderDevice::QUADS);

	levels.append(level);

	PBBBuilder builder(level, size, RenderSurfaceTypes());

	builder.textureScale = mapToUvw_Legacy(size, textureFace).xy() * 2.0 / studsPerTile;

	builder.buildFace(textureFace, LevelBuilder::Decal);
}

// FUNCTION: WEBSERVICE 0x1017dd20
// FUNCTION: ROBLOX 0x00488150
PBBMesh::PBBMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes)
{
	{
		Render::Mesh::LevelRef level = new Render::Mesh::Level(G3D::RenderDevice::QUADS);
		levels.append(level);
		PBBBuilder builder(level, size, surfaceTypes);
		builder.build(LevelBuilder::Surface);
	}

	if (ViewBase::getShadowsEnabled()) {
		Render::Mesh::LevelRef tempShadowLevel = new Render::Mesh::Level(G3D::RenderDevice::TRIANGLES);
		PBBBuilder builder(tempShadowLevel, size, surfaceTypes);
		builder.build(LevelBuilder::Shadow);
		computeShadowSurface(tempShadowLevel);
	}
}

template void MeshFactory<PBBMesh, 4>::flushCache();

template PBBMesh* MeshFactory<PBBMesh, 4>::create(const G3D::Vector3&, RenderSurfaceTypes);

template PBBMesh* MeshFactory<PBBMesh, 4>::createDecal(const G3D::Vector3&, NormalId);

template PBBMesh* MeshFactory<PBBMesh, 4>::createTexture(const G3D::Vector3&, NormalId, const G3D::Vector2&);

} // namespace View
} // namespace RBX
