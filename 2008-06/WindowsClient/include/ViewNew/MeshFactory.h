#pragma once
// >>> native-status (generated) -- do not edit >>>
// MeshFactory | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src fd0b8097 | roc native-status --write
// 2008-06 native RBX::ViewNew::MeshFactory<Mesh, numMeshes> (inactive): the empty second base of the cached meshes.
//   RTTI     .?AV?$MeshFactory@VSphereMesh@ViewNew@RBX@@$00@ViewNew@RBX@@ (and WedgeMesh / TorsoMesh / HeadMesh /
//            CylinderAlongXMesh with $00 = 1, PBBMesh with $03 = 4) is the last base class descriptor of each mesh,
//            mdisp 0x89, no fields (the meshes stay 0x88 bytes).
//   The factory's static caches and create functions live in other units and are not declared here.
#include <cstddef>

namespace RBX
{
	namespace ViewNew
	{
		template<class Mesh, size_t numMeshes>
		class MeshFactory
		{
		};
	}
}
