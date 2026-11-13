// 2008-06 native RBX::ViewNew::WedgeBuilder / WedgeMesh (inactive): the unit 004f6e30..004f7d8f.
// The per-face grid instances (004f4e60..004f6a80, 004f6fa0, 004f7390) come from ViewNew/QuadVolumeFace.h. The functor
// operator() bodies are class-inline: the original inlines them into the strips (DeformSide3 004f4e60 / 004f54d0,
// DeformTop3 004f51a0, DeformFront 004f5810), whose x87 code they are read from (functor at [esp+0x80]: inset, flip).
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// ViewNewWedgeMesh | 2008-06 | draft (no current byte proof)
// 0/9 mapped addresses byte-exact | 9 unproved | no mapped strings | by auto (+2) (deepseek:deepseek-chat)
// <<< native-status | src 33f6b106 | roc native-status --write
#include "ViewNew/WedgeMesh.h"
#include "ViewNew/QuadVolumeFace.h"

namespace RBX
{
	namespace ViewNew
	{
		class DeformFront
		{
			const float inset;
		public:
			DeformFront(float inset)
				: inset(inset)
			{
			}
			void operator()(G3D::Vector3& vertex, G3D::Vector3& normal, G3D::Vector2&, const G3D::Vector3& size, const G3D::Vector2int16&)
			{
				if (vertex.x > 0)
					vertex.x -= inset;
				else
					vertex.x += inset;
				if (vertex.y > 0)
					vertex.z = inset - vertex.z;
				else
					vertex.y += inset;
				normal.z = size.y;
				normal.y = size.z;
			}
		};

		class DeformSide3
		{
			const float inset;
			const float flip;
		public:
			DeformSide3(float inset, bool flip)
				: inset(inset),
				  flip(flip ? -1.0f : 1.0f)
			{
			}
			void operator()(G3D::Vector3& vertex, G3D::Vector3&, G3D::Vector2&, const G3D::Vector3&, const G3D::Vector2int16&)
			{
				if (vertex.y > 0)
				{
					vertex.y -= inset;
					vertex.x = (fabs(vertex.x) - inset) * flip;
				}
				else
				{
					vertex.y += inset;
					if (vertex.x > 0)
						vertex.x -= inset;
					else
						vertex.x += inset;
				}
			}
		};

		class DeformTop3
		{
			const float inset;
		public:
			DeformTop3(float inset)
				: inset(inset)
			{
			}
			void operator()(G3D::Vector3& vertex, G3D::Vector3&, G3D::Vector2&, const G3D::Vector3&, const G3D::Vector2int16&)
			{
				if (vertex.x > 0)
					vertex.x -= 2 * inset;
				else
					vertex.x += inset;
				vertex.y = (vertex.y > 0 ? vertex.y : -vertex.y) - inset;
			}
		};

		void WedgeBuilder::buildRight(Purpose purpose)
		{
			buildFace<NORM_X>(DeformSide3(bevel, true), G3D::Vector2int16(1, 1), purpose);
		}

		void WedgeBuilder::buildTop(Purpose purpose)
		{
			buildFace<NORM_Y>(DeformTop3(bevel), G3D::Vector2int16(1, 1), purpose);
		}

		void WedgeBuilder::buildBack(Purpose purpose)
		{
			buildFace<NORM_Z>(*this, 1, 1, purpose);
		}

		void WedgeBuilder::buildLeft(Purpose purpose)
		{
			buildFace<NORM_X_NEG>(DeformSide3(bevel, false), G3D::Vector2int16(1, 1), purpose);
		}

		void WedgeBuilder::buildBottom(Purpose purpose)
		{
			buildFace<NORM_Y_NEG>(*this, 1, 1, purpose);
		}

		void WedgeBuilder::buildFront(Purpose purpose)
		{
			buildFace<NORM_Z_NEG>(DeformFront(bevel), G3D::Vector2int16(1, 1), purpose);
		}

		static const float bevel = 0.065f; // 00827080

		WedgeMesh::WedgeMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes)
		{
			levels.push_back(new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS));

			WedgeBuilder builder(levels.last(), size, surfaceTypes, 0.0f);
			builder.build(LevelBuilder::Surface);
		}

		WedgeMesh::WedgeMesh(const G3D::Vector3& size, NormalId decalFace)
		{
			G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level = new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS);
			levels.push_back(level);

			WedgeBuilder builder(level, size, RenderSurfaceTypes(), bevel);
			builder.buildFace(decalFace, LevelBuilder::Decal);
		}

		WedgeMesh::WedgeMesh(const G3D::Vector3& size, NormalId textureFace, const G3D::Vector2& studsPerTile)
		{
			G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level = new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS);
			levels.push_back(level);

			WedgeBuilder builder(level, size, RenderSurfaceTypes(), bevel);
			builder.textureScale = mapToUvw_Legacy(size, textureFace).xy() * 2.0f / studsPerTile;

			builder.buildFace(textureFace, LevelBuilder::Decal);
		}
	}
}
