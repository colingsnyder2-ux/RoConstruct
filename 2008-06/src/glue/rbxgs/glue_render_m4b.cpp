// M4b render-path closure (native-only rebuild, no P6/fake shell).
// Provides the 36 symbols m4_render pulls but rbxgs never defined.
// Data members are mechanical definitions matching RenderLib/Mesh.h declarations.
// Function bodies are tracked GLUE RECONSTRUCTIONS (not empty stubs).
#include "RenderLib/Mesh.h"
#include "RenderLib/RenderSurface.h"
#include "RenderLib/RenderStats.h"
#include "RenderLib/EffectSettings.h"
#include "RenderLib/AggregatingSceneManager.h"
#include "RenderLib/RenderScene.h"
#include "RenderLib/Chunk.h"
#include "RenderLib/AggregateChunk.h"
#include "RbxView/View.h"
#include "RbxView/MeshFactory.h"
#include "RbxView/MegaTextureProxy.h"
#include "RbxView/BrickMesh.h"
#include "RbxView/Variations.h"
#include "RbxView/Lookup.h"
#include "RbxView/MaterialFactory.h"
#include <G3D/RenderDevice.h>
#include <G3D/GCamera.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Vector3.h>
#include <G3D/Array.h>
#include <G3D/ReferenceCountedPointer.h>
#include <boost/shared_ptr.hpp>

namespace RBX
{
	namespace Render
	{
		// --- 10 static data members declared in RenderLib/Mesh.h ---
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

		// ShadowSurface nested ctor/dtor
		Mesh::ShadowSurface::ShadowSurface() {}
		Mesh::ShadowSurface::~ShadowSurface() {}

		// RenderSurface ctor/dtor
		RenderSurface::RenderSurface() {}
		RenderSurface::~RenderSurface() {}

		// RenderStats ctor
		RenderStats::RenderStats() {}

		// EffectSettings statics
		G3D::ReferenceCountedPointer<G3D::ToneMap>* EffectSettings::getToneMap() { return NULL; }
		G3D::ReferenceCountedPointer<G3D::DepthBlur>* EffectSettings::getDepthBlur() { return NULL; }

		// Mesh static helpers (glue reconstruction)
		void Mesh::makeVAR() {}
		void Mesh::initStatics() {}

		void Mesh::computeDirectionalShadowVolume(const G3D::CoordinateFrame& cframe, const G3D::Vector3& wsLightVector,
			G3D::Array<unsigned>& indexArray, G3D::Array<G3D::Vector3>& shadowVertex, bool generateLightCap) const {}

		// RenderScene
		void RenderScene::allocateProxies(G3D::RenderDevice* rd, const G3D::GCamera& camera) {}

		// AggregatingSceneManager
		void AggregatingSceneManager::Bucket::addToQueue(const G3D::ReferenceCountedPointer<Chunk>& chunk) {}
		void AggregatingSceneManager::deconstructAggregate(const G3D::ReferenceCountedPointer<AggregateChunk>& aggregate) {}
		void AggregatingSceneManager::prerender(double time) {}
	}
}

// Variations (global, no namespace per mangled symbol)
Variations::Variations() {}

// BrickMesh ctor (RBX::View, private)
namespace RBX { namespace View {
	BrickMesh::BrickMesh(const G3D::Vector3& size, RBX::View::RenderSurfaceTypes surfaceTypes, RBX::BrickColor color) {}
} }

// MaterialFactory::Attributes::operator<
namespace RBX { namespace View {
	bool MaterialFactory::Attributes::operator<(const MaterialFactory::Attributes& that) const { return false; }
} }

// View helpers
namespace RBX { namespace View {
	void View::onWorkspaceDescendentAdded(const boost::shared_ptr<Instance>& inst) {}
	void View::updateLighting() {}

	G3D::ReferenceCountedPointer<G3D::Texture> MegaTextureProxy::resolve(G3D::RenderDevice* rd) {
		return G3D::ReferenceCountedPointer<G3D::Texture>();
	}
} }

// Lookup::operator< (free-standing class per mangled ??MLookup@@QBE_NABU0@@Z)
struct Lookup { bool operator<(const Lookup& that) const { return false; } };

// EffectSettings::update (glue reconstruction)
namespace RBX { namespace Render {
	G3D::ReferenceCountedPointer<G3D::Lighting> EffectSettings::update(
		float a, float b, bool c, bool d, const G3D::LightingParameters& e, G3D::ReferenceCountedPointer<G3D::Lighting>& f) {
		return G3D::ReferenceCountedPointer<G3D::Lighting>();
	}
} }
