#pragma once
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
