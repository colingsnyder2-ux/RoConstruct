// M4b render-path closure (native-only rebuild, no P6/fake shell).
#include "RenderLib/Mesh.h"
#include "RenderLib/RenderSurface.h"
#include "RenderLib/RenderStats.h"
#include "RenderLib/EffectSettings.h"
#include "RenderLib/AggregatingSceneManager.h"
#include "RenderLib/RenderScene.h"
#include "RenderLib/Chunk.h"
#include <GLG3D/RenderDevice.h>
#include <G3D/GCamera.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Vector3.h>
#include <G3D/Array.h>
#include <boost/shared_ptr.hpp>
#include <string>

// View-layer headers (RbxView root + include paths added to glue layer)
#include "BrickMesh.h"
#include "MaterialFactory.h"
#include "MeshFactory.h"
#include "CylinderMesh.h"
#include "PBBMesh.h"
#include "SphereMesh.h"
#include "RbxView/View.h"

namespace RBX
{
	namespace Render
	{
		G3D::MeshAlg::Geometry Mesh::visibleGeometry;
		G3D::Array<G3D::Vector2> Mesh::texCoordArray;
		G3D::Array<G3D::Vector3> Mesh::tangentArray;
		G3D::Array<int> Mesh::vertexRefCounts;
		G3D::Array<int> Mesh::freeList;
		G3D::VAR Mesh::vertexVAR;
		G3D::VAR Mesh::normalVAR;
		G3D::VAR Mesh::texCoordVAR;
		G3D::VAR Mesh::tangentVAR;
		bool Mesh::varDirty = false;

		Mesh::ShadowSurface::ShadowSurface() {}
		Mesh::ShadowSurface::~ShadowSurface() {}

		RenderSurface::RenderSurface() {}
		RenderSurface::~RenderSurface() {}

		G3D::ToneMap* EffectSettings::getToneMap() { static G3D::ToneMap t; return &t; }
		DepthBlur* EffectSettings::getDepthBlur() { return NULL; }


		void Mesh::computeDirectionalShadowVolume(const G3D::CoordinateFrame& cframe, const G3D::Vector3& wsLightVector,
			G3D::Array<unsigned>& indexArray, G3D::Array<G3D::Vector3>& shadowVertex, bool generateLightCap) const {}

		void RenderScene::allocateProxies(G3D::RenderDevice* rd, const G3D::GCamera& camera) {}

		void AggregatingSceneManager::Bucket::addToQueue(const G3D::ReferenceCountedPointer<Chunk>& chunk) {}
		void AggregatingSceneManager::deconstructAggregate(G3D::ReferenceCountedPointer<AggregateChunk> aggregate) {}
		void AggregatingSceneManager::prerender(double time) {}

		G3D::ReferenceCountedPointer<G3D::Lighting> EffectSettings::update(
			float a, float b, bool c, float d, const G3D::ReferenceCountedPointer<G3D::Lighting>& e,
			const G3D::LightingParameters& f, G3D::LightingParameters& g) {
			return e;
		}
	}
}

RenderStats::RenderStats() {}

// Global Lookup/Variations (from BrickMesh.h)
static int orderedCompare(const G3D::Vector3& a, const G3D::Vector3& b)
{
	if (a.x < b.x) return -1; if (a.x > b.x) return 1;
	if (a.y < b.y) return -1; if (a.y > b.y) return 1;
	if (a.z < b.z) return -1; if (a.z > b.z) return 1;
	return 0;
}
bool Lookup::operator<(const Lookup& other) const
{
	int c = orderedCompare(size, other.size);
	if (c < 0) return true; if (c > 0) return false;
	if (surfaceTypes < other.surfaceTypes) return true; if (other.surfaceTypes < surfaceTypes) return false;
	return color < other.color;
}
bool Lookup::operator==(const Lookup& other) const
{
	return size == other.size && !(surfaceTypes < other.surfaceTypes) && !(other.surfaceTypes < surfaceTypes) && !(color < other.color) && !(other.color < color);
}
Variations::Variations() : count(0) {}

namespace RBX { namespace View {
	BrickMesh::BrickMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes, BrickColor color) {}

	bool MaterialFactory::Attributes::operator<(const Attributes& other) const
	{
		if (color < other.color) return true; if (other.color < color) return false;
		if (transparency < other.transparency) return true; if (other.transparency < transparency) return false;
		return reflectance < other.reflectance;
	}

	G3D::ReferenceCountedPointer<G3D::Texture> MegaTextureProxy::resolve(G3D::RenderDevice* rd)
	{
		return G3D::ReferenceCountedPointer<G3D::Texture>();
	}

	void View::onWorkspaceDescendentAdded(boost::shared_ptr<Instance> descendent) {}
	void View::updateLighting() {}
} }

// MeshFactory template statics
namespace RBX { namespace View {
	G3D::Table<RenderSurfaceTypes, G3D::Table<G3D::Vector3, MeshFactory<CylinderAlongXMesh,1>::Variations> > MeshFactory<CylinderAlongXMesh,1>::cache1;
	std::map<MeshFactory<CylinderAlongXMesh,1>::DecalKey, G3D::ReferenceCountedPointer<Render::Mesh> > MeshFactory<CylinderAlongXMesh,1>::decalCache;
	G3D::Table<RenderSurfaceTypes, G3D::Table<G3D::Vector3, MeshFactory<PBBMesh,4>::Variations> > MeshFactory<PBBMesh,4>::cache1;
	std::map<MeshFactory<PBBMesh,4>::DecalKey, G3D::ReferenceCountedPointer<Render::Mesh> > MeshFactory<PBBMesh,4>::decalCache;
	G3D::Table<RenderSurfaceTypes, G3D::Table<G3D::Vector3, MeshFactory<SphereMesh,1>::Variations> > MeshFactory<SphereMesh,1>::cache1;
	std::map<MeshFactory<SphereMesh,1>::DecalKey, G3D::ReferenceCountedPointer<Render::Mesh> > MeshFactory<SphereMesh,1>::decalCache;
} }



namespace RBX { namespace View {
	bool RenderSurfaceTypes::operator<(const RenderSurfaceTypes& other) const { return data < other.data; }
} }
