// 2008-06 native RBX::ViewNew::CylinderBuilder / CylinderAlongXMesh (inactive): the unit 004fd430..004fdaef.
// >>> native-status (generated) -- do not edit >>>
// ViewNewCylinderMesh | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 21552895 | roc native-status --write
#include "ViewNew/CylinderMesh.h"
#include <algorithm>
#include <math.h>

namespace RBX
{
	namespace ViewNew
	{
		// 004fd4a0: rounds the square end cap (face-local x / y) onto the circle
		static void EndcapTransform(G3D::Vector3& vertex, G3D::Vector3& normal, G3D::Vector2& tex, const G3D::Vector3& radius, const G3D::Vector2int16& ivertex)
		{
			float scale;
			if (fabs(vertex.y) >= fabs(vertex.x))
				scale = vertex.y == 0.0f ? 0.0f : float(fabs(vertex.y)) / vertex.xy().length();
			else
				scale = vertex.x == 0.0f ? 0.0f : float(fabs(vertex.x)) / vertex.xy().length();
			vertex.x *= scale;
			vertex.y *= scale;
		}

		// G3D 6 Vector2::direction() of the 2008 build: no `lenSquared != 1` shortcut (004fd530 always takes
		// 1 / sqrt and multiplies); the donor G3D header has the shortcut, so the 2008 form is spelled out here.
		static inline G3D::Vector2 unitDirection(const G3D::Vector2& v)
		{
			float invLength = 1.0f / v.length();
			return G3D::Vector2(v.x * invLength, v.y * invLength);
		}

		// 004fd530
		static void CylinderTransform(G3D::Vector3& vertex, G3D::Vector3& normal, G3D::Vector2& tex, const G3D::Vector3& radius, const G3D::Vector2int16& ivertex)
		{
			G3D::Vector2 direction = unitDirection(vertex.yz());
			vertex.y = radius.x * direction.x;
			vertex.z = radius.y * direction.y;
			normal = G3D::Vector3(0.0f, direction.x, direction.y);
		}

		CylinderBuilder::CylinderBuilder(G3D::ReferenceCountedPointer<RenderBase::Mesh::Level>& level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes, size_t slices)
			: LevelBuilder(level, size, surfaceTypes),
			  elements(std::max<size_t>(slices / 4, 1))
		{
		}

		void CylinderBuilder::buildRight(Purpose purpose)
		{
			int e = elements;
			buildFace<NORM_X>(&EndcapTransform, G3D::Vector2int16(e, e), purpose);
		}

		void CylinderBuilder::buildTop(Purpose purpose)
		{
			buildFace<NORM_Y>(&CylinderTransform, G3D::Vector2int16(elements, 1), purpose);
		}

		void CylinderBuilder::buildBack(Purpose purpose)
		{
			buildFace<NORM_Z>(&CylinderTransform, G3D::Vector2int16(elements, 1), purpose);
		}

		void CylinderBuilder::buildLeft(Purpose purpose)
		{
			int e = elements;
			buildFace<NORM_X_NEG>(&EndcapTransform, G3D::Vector2int16(e, e), purpose);
		}

		void CylinderBuilder::buildBottom(Purpose purpose)
		{
			buildFace<NORM_Y_NEG>(&CylinderTransform, G3D::Vector2int16(elements, 1), purpose);
		}

		void CylinderBuilder::buildFront(Purpose purpose)
		{
			buildFace<NORM_Z_NEG>(&CylinderTransform, G3D::Vector2int16(elements, 1), purpose);
		}

		CylinderAlongXMesh::CylinderAlongXMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes)
		{
			meshKind = 3;
			levels.push_back(new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS));

			G3D::ReferenceCountedPointer<RenderBase::Mesh::Level>& lastLevel = levels.last();

			CylinderBuilder builder(lastLevel, size, surfaceTypes, 12);
			builder.build(LevelBuilder::Surface);
		}

		CylinderAlongXMesh::CylinderAlongXMesh(const G3D::Vector3& size, NormalId decalFace)
		{
			meshKind = 3;
			G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level = new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS);
			levels.push_back(level);

			CylinderBuilder builder(level, size, RenderSurfaceTypes(), 12);
			builder.buildFace(decalFace, LevelBuilder::Decal);
		}

		CylinderAlongXMesh::CylinderAlongXMesh(const G3D::Vector3& size, NormalId textureFace, const G3D::Vector2& studsPerTile)
		{
			meshKind = 3;
			G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level = new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS);
			levels.push_back(level);

			CylinderBuilder builder(level, size, RenderSurfaceTypes(), 12);
			builder.textureScale = mapToUvw_Legacy(size, textureFace).xy() * 2.0f / studsPerTile;

			builder.buildFace(textureFace, LevelBuilder::Decal);
		}
	}
}
