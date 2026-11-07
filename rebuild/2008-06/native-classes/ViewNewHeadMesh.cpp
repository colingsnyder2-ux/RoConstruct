// 2008-06 native RBX::ViewNew::HeadBuilder / HeadMesh (inactive): the unit 004fdaf0..0050068f.
// >>> native-status (generated) -- do not edit >>>
// ViewNewHeadMesh | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 1894b6a1 | roc native-status --write
#include "ViewNew/HeadMesh.h"
#include <algorithm>
#include <math.h>

namespace RBX
{
	namespace ViewNew
	{
		class CylinderTransform
		{
			const float bevel;
			const int halfVertexCount;
		public:
			CylinderTransform(float bevel, int halfVertexCount)
				: bevel(bevel),
				  halfVertexCount(halfVertexCount)
			{
			}
			void operator()(G3D::Vector3& vertex, G3D::Vector3& normal, G3D::Vector2& tex, const G3D::Vector3& radius, const G3D::Vector2int16& ivertex); // 004fdbd0
		};

		class EndcapTransform
		{
			const float bevel;
		public:
			EndcapTransform(float bevel)
				: bevel(bevel)
			{
			}
			void operator()(G3D::Vector3& vertex, G3D::Vector3& normal, G3D::Vector2& tex, const G3D::Vector3& radius, const G3D::Vector2int16& ivertex); // 004fdcc0
		};

		HeadBuilder::HeadBuilder(G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes, size_t elements, float bevel)
			: LevelBuilder(level, G3D::Vector3(std::min(size.x, size.z), size.y, std::min(size.x, size.z)), surfaceTypes),
			  bevel(bevel),
			  elements(elements)
		{
		}

		void CylinderTransform::operator()(G3D::Vector3& vertex, G3D::Vector3& normal, G3D::Vector2& tex, const G3D::Vector3& radius, const G3D::Vector2int16& ivertex)
		{
			float angleX = vertex.x / radius.x * 0.7853982f;
			float angleY = float(ivertex.y - halfVertexCount + 1) * 1.5707964f / float(halfVertexCount - 1);
			vertex.x = (radius.x - (1.0f - cosf(angleY)) * bevel) * sinf(angleX);
			if (ivertex.y >= halfVertexCount)
				vertex.y = radius.y - (1.0f - sinf(angleY)) * bevel;
			else
				vertex.y = (sinf(angleY) + 1.0f) * bevel - radius.y;
			vertex.z = (radius.z - (1.0f - cosf(angleY)) * bevel) * cosf(angleX);
			normal.x = cosf(angleY) * sinf(angleX);
			normal.y = sinf(angleY);
			normal.z = cosf(angleY) * cosf(angleX);
			float arc = 1.5707964f * bevel;
			float factor = arc / (radius.y + arc - bevel);
			if (ivertex.y >= halfVertexCount)
				tex.y *= factor;
			else
				tex.y = 2.0f * radius.y - (1.0f - (tex.y - radius.y) / radius.y) * radius.y * factor;
		}

		void EndcapTransform::operator()(G3D::Vector3& vertex, G3D::Vector3& normal, G3D::Vector2& tex, const G3D::Vector3& radius, const G3D::Vector2int16& ivertex)
		{
			float scale;
			float absY = float(fabs(vertex.y));
			float absX = float(fabs(vertex.x));
			if (absY >= absX)
				scale = vertex.y == 0.0f ? 0.0f : absY / vertex.xy().length() * (1.0f - bevel / radius.y);
			else
				scale = vertex.x == 0.0f ? 0.0f : absX / vertex.xy().length() * (1.0f - bevel / radius.x);
			vertex.x *= scale;
			vertex.y *= scale;
		}

		void HeadBuilder::buildTop(Purpose purpose)
		{
			int e = elements;
			buildFace<NORM_Y>(EndcapTransform(bevel), G3D::Vector2int16(e, e), purpose);
		}

		void HeadBuilder::buildBottom(Purpose purpose)
		{
			int e = elements;
			buildFace<NORM_Y_NEG>(EndcapTransform(bevel), G3D::Vector2int16(e, e), purpose);
		}

		void HeadBuilder::buildLeft(Purpose purpose)
		{
			int e = elements;
			buildFace<NORM_X_NEG>(CylinderTransform(bevel, (elements + 1) / 2), G3D::Vector2int16(e, e), purpose);
		}

		void HeadBuilder::buildRight(Purpose purpose)
		{
			int e = elements;
			buildFace<NORM_X>(CylinderTransform(bevel, (elements + 1) / 2), G3D::Vector2int16(e, e), purpose);
		}

		void HeadBuilder::buildFront(Purpose purpose)
		{
			int e = elements;
			buildFace<NORM_Z_NEG>(CylinderTransform(bevel, (elements + 1) / 2), G3D::Vector2int16(e, e), purpose);
		}

		void HeadBuilder::buildBack(Purpose purpose)
		{
			int e = elements;
			buildFace<NORM_Z>(CylinderTransform(bevel, (elements + 1) / 2), G3D::Vector2int16(e, e), purpose);
		}

		HeadMesh::HeadMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes)
		{
			float bevel = std::min(size.x, size.z) * 0.25f;
			levels.push_back(new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS));

			G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level = levels.last();
			HeadBuilder builder(level, size, surfaceTypes, 9, bevel);
			builder.build(LevelBuilder::Surface);
		}

		HeadMesh::HeadMesh(const G3D::Vector3& size, NormalId decalFace)
		{
			float bevel = std::min(size.x, size.z) * 0.25f;
			levels.push_back(new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS));

			HeadBuilder builder(levels.last(), size, RenderSurfaceTypes(), 9, bevel);
			builder.buildFace(decalFace, LevelBuilder::Decal);
		}

		HeadMesh::HeadMesh(const G3D::Vector3& size, NormalId textureFace, const G3D::Vector2& studsPerTile)
		{
			float bevel = std::min(size.x, size.z) * 0.25f;
			levels.push_back(new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS));

			HeadBuilder builder(levels.last(), size, RenderSurfaceTypes(), 9, bevel);
			builder.textureScale = mapToUvw_Legacy(size, textureFace).xy() * 2.0f / studsPerTile;
			builder.buildFace(textureFace, LevelBuilder::Decal);
		}
	}
}
