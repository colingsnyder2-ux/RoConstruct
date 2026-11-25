// INFERRED: buildFace EndcapTransform spelling at004ff1e0; unique714B body and original references verified.
// 2008-06 native RBX::ViewNew::HeadBuilder / HeadMesh (inactive): the unit 004fdaf0..0050068f.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "ViewNew/HeadMesh.h"
#include "ViewNew/QuadVolumeFace.h"
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
			// The face slots pass `elements`; the ctor halves it (2007 RenderLibNew/HeadMesh.cpp shape).
			CylinderTransform(float bevel, int vertexCount)
				: bevel(bevel),
				  halfVertexCount((vertexCount + 1) / 2)
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

		// 004fdcc0 (2007 RenderLibNew/HeadMesh.cpp shape: ratio *= 1.0 - bevel / radius)
		void EndcapTransform::operator()(G3D::Vector3& vertex, G3D::Vector3& normal, G3D::Vector2& tex, const G3D::Vector3& radius, const G3D::Vector2int16& ivertex)
		{
			float ratio;
			if (fabs(vertex.y) >= fabs(vertex.x))
			{
				if (vertex.y == 0)
					ratio = 0;
				else
				{
					ratio = fabs(vertex.y) / vertex.xy().length();
					ratio *= 1.0 - bevel / radius.y;
				}
			}
			else
			{
				if (vertex.x == 0)
					ratio = 0;
				else
				{
					ratio = fabs(vertex.x) / vertex.xy().length();
					ratio *= 1.0 - bevel / radius.x;
				}
			}
			vertex.x *= ratio;
			vertex.y *= ratio;
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

		// 00500080 / 005000c0 / 00500100 / 00500140 (with the grid instances 004ff4b0 / 004ff790 / 004ffa60 / 004ffd40):
		// the 2007 RenderLibNew/HeadMesh.cpp shape, CylinderTransform(bevel, elements) halving in its ctor and the
		// two counts passed through the inline (Builder, x, y, purpose) buildFace overload (dword reloads of elements).
		void HeadBuilder::buildLeft(Purpose purpose)
		{
			buildFace<NORM_X_NEG>(CylinderTransform(bevel, elements), elements, elements, purpose);
		}

		// 005000c0
		void HeadBuilder::buildRight(Purpose purpose)
		{
			buildFace<NORM_X>(CylinderTransform(bevel, elements), elements, elements, purpose);
		}

		// 00500100
		void HeadBuilder::buildFront(Purpose purpose)
		{
			buildFace<NORM_Z_NEG>(CylinderTransform(bevel, elements), elements, elements, purpose);
		}

		// 00500140
		void HeadBuilder::buildBack(Purpose purpose)
		{
			buildFace<NORM_Z>(CylinderTransform(bevel, elements), elements, elements, purpose);
		}

		HeadMesh::HeadMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes)
		{
			float bevel = std::min(size.x, size.z) * 0.25f;
			levels.push_back(new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS));

			G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level = levels.last();
			HeadBuilder builder(level, size, surfaceTypes, 9, bevel);
			builder.build(LevelBuilder::Surface);
		}

		// INFERRED: constructor identity from original HeadMesh factory call and unique exact body.
		HeadMesh::HeadMesh(const G3D::Vector3& size, NormalId decalFace)
		{
			float bevel = std::min(size.x, size.z) * 0.25f;
			RenderBase::Mesh::Level* created = new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS);
			{
				G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> reference(created);
				levels.push_back(reference);
			}
			HeadBuilder builder(created, size, RenderSurfaceTypes(), 9, bevel);
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
