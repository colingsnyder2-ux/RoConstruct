// 2008-06 native RBX::ViewNew::MeshFactory<Mesh, numMeshes> static caches (inactive): the per-mesh cache constructors
// 004d91f0..004d9560, initCache 004d9750..004d9930, flushCache 004daf50..004db400 and the create / createDecal /
// createTexture / releaseUnused instances 004ec220..004ef7b0 (bodies in ViewNewPartMesh2008/MeshFactoryCache2008.h).
// PBBMesh::create 004edb20 calls the PBBMesh surface constructor 004f4cb0 declared in ViewNew/PBBMesh.h.
#include "ViewNew/SphereMesh.h"
#include "ViewNew/CylinderMesh.h"
#include "ViewNew/HeadMesh.h"
#include "ViewNew/WedgeMesh.h"
#include "ViewNew/TorsoMesh.h"
#include "ViewNew/PBBMesh.h"
#include "ViewNewPartMesh2008/MeshFactoryCache2008.h"

namespace RBX
{
	namespace ViewNew
	{
		template class MeshFactory<SphereMesh, 1>;
		template class MeshFactory<CylinderAlongXMesh, 1>;
		template class MeshFactory<HeadMesh, 1>;
		template class MeshFactory<WedgeMesh, 1>;
		template class MeshFactory<TorsoMesh, 1>;
		template class MeshFactory<PBBMesh, 4>;
	}
}
