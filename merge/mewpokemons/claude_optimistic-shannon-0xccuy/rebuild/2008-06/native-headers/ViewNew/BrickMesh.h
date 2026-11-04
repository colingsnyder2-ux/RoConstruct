#pragma once
// 2008-06 native RBX::ViewNew::BrickMesh (inactive; only what the ViewNew units here use).
//   vtable 00826e7c .?AVBrickMesh@ViewNew@RBX@@ -> RenderBase::Mesh -> ReferenceCountedObject (mdisp 0; no MeshFactory
//   base); one slot (??_G 004e54c0). ctor 004e53c0 (meshKind 1; ret 0x1c) and the cache in 004e54e0 / 004e5300 are not
//   recovered here (their helpers 004e2c80 / 004e3720 / 004e3570 and globals 0096de64 / 00942ec4 / 00972758 are
//   unnamed).
//   normalPerturbation  const float 0.05f at 00826e3c, read by the BrickMesh unit (004de50e..) and by the PBB
//                       perturbation ctor 004f2030 (fld [00826e3c]).
#include "ViewNew/RenderBaseMesh.h"

namespace RBX
{
	namespace ViewNew
	{
		class BrickMesh : public RenderBase::Mesh
		{
		public:
			static const float normalPerturbation;    // 00826e3c
		};
	}
}
