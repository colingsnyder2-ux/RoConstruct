#pragma once
// >>> native-status (generated) -- do not edit >>>
// FileMesh | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 1cce79ff | roc native-status --write
// 2008-06 native RBX::ViewNew::FileMesh (inactive): the unit 00500780..00500c98.
//   vtable 008271cc .?AVFileMesh@ViewNew@RBX@@ -> RenderBase::Mesh -> G3D::ReferenceCountedObject (all mdisp 0; no
//            MeshFactory base); one slot (??_G 004e54c0, the scalar deleting dtor shared by every ViewNew mesh).
//   size     0x88: create 00500b90 pushes 0x88 before the Mesh ctor 00548570 and then stores 008271cc (header-inline
//            FileMesh()); no fields of its own.
//   create   00500b90 (cdecl, hidden ReferenceCountedPointer<RenderBase::Mesh> result): ContentProvider* [esp+8],
//            const Vector3& [esp+0xc], MeshId by value [esp+0x10] (0x20 bytes: std::string copied by the imported copy
//            ctor, then the dword at +0x1c copied by mov; only the string is destroyed: the donor ContentId layout
//            std::string id + const Name* mimeTypePtr).
//   loadFromMeshFile 00500780 (thiscall, ret 0x28 = provider 4 + scale 4 + MeshId 0x20). It calls
//            ContentProvider 00562670 (thiscall, three pointer arguments: the MeshId, the status out slot, the file name
//            string), which the native util/NativeContentProvider.h does not declare (see the unit).
#include "ViewNew/RenderBaseMesh.h"
#include "util/NativeContentProvider.h"
#include "util/MeshId.h"

namespace RBX
{
	namespace ViewNew
	{
		class FileMesh : public RenderBase::Mesh
		{
		public:
			FileMesh() {}
			bool loadFromMeshFile(ContentProvider* provider, const G3D::Vector3& scale, MeshId meshFile);  // 00500780
		public:
			static G3D::ReferenceCountedPointer<RenderBase::Mesh> create(ContentProvider* provider, const G3D::Vector3& scale, MeshId meshFile);  // 00500b90
		};
	}
}
