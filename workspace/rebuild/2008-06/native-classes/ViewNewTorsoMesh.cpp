// 2008-06 native RBX::ViewNew::TorsoBuilder / TorsoMesh (inactive): the unit 004fa050..004fab2f.
// The per-face grid instances (004f7d90..004fa04f, 004fa190) come from ViewNew/QuadVolumeFace.h. The functor
// operator() bodies are class-inline: the original inlines them into the strips (DeformSide 004f7d90 / 004f8790,
// DeformTop 004f80e0, DeformFrontBack 004f8420 / 004f8ae0; functor at [esp+0x80]: inset, [esp+0x84]: shoulderInset).
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// ViewNewTorsoMesh | 2008-06 | draft (no current byte proof)
// 0/9 mapped addresses byte-exact | 9 unproved | no mapped strings | by auto (+1) (deepseek:deepseek-chat)
// <<< native-status | src ec6c597a | roc native-status --write
#include "ViewNew/TorsoMesh.h"
#include "ViewNew/QuadVolumeFace.h"

namespace RBX
{
	namespace ViewNew
	{
		class DeformFrontBack
		{
			const float inset;
			const float shoulderInset;
		public:
			DeformFrontBack(float inset, float shoulderInset)
				: inset(inset),
				  shoulderInset(shoulderInset)
			{
			}
			void operator()(G3D::Vector3& vertex, G3D::Vector3&, G3D::Vector2& tex, const G3D::Vector3&, const G3D::Vector2int16&)
			{
				if (vertex.x > 0)
					vertex.x -= inset;
				else
					vertex.x += inset;
				if (vertex.y > 0)
				{
					vertex.y -= inset;
					if (vertex.x > 0)
					{
						vertex.x -= shoulderInset;
						tex.x -= shoulderInset;
					}
					else
					{
						vertex.x += shoulderInset;
						tex.x += shoulderInset;
					}
				}
				else
					vertex.y += inset;
			}
		};

		class DeformSide
		{
			const float inset;
			const float shoulderInset;
		public:
			DeformSide(float inset, float shoulderInset)
				: inset(inset),
				  shoulderInset(shoulderInset)
			{
			}
			void operator()(G3D::Vector3& vertex, G3D::Vector3&, G3D::Vector2&, const G3D::Vector3&, const G3D::Vector2int16&)
			{
				if (vertex.x > 0)
					vertex.x -= inset;
				else
					vertex.x += inset;
				if (vertex.y > 0)
				{
					vertex.y -= inset;
					vertex.z -= shoulderInset;
				}
				else
					vertex.y += inset;
			}
		};

		class DeformTop
		{
			const float inset;
			const float shoulderInset;
		public:
			DeformTop(float inset, float shoulderInset)
				: inset(inset),
				  shoulderInset(shoulderInset)
			{
			}
			void operator()(G3D::Vector3& vertex, G3D::Vector3&, G3D::Vector2& tex, const G3D::Vector3&, const G3D::Vector2int16&)
			{
				if (vertex.x > 0)
				{
					vertex.x -= inset + shoulderInset;
					tex.x -= shoulderInset;
				}
				else
				{
					vertex.x += inset + shoulderInset;
					tex.x += shoulderInset;
				}
				if (vertex.y > 0)
					vertex.y -= inset;
				else
					vertex.y += inset;
			}
		};

		void TorsoBuilder::buildRight(Purpose purpose)
		{
			buildFace<NORM_X>(DeformSide(bevel, shoulderInset), G3D::Vector2int16(1, 1), purpose);
		}

		void TorsoBuilder::buildTop(Purpose purpose)
		{
			buildFace<NORM_Y>(DeformTop(bevel, shoulderInset), G3D::Vector2int16(1, 1), purpose);
		}

		void TorsoBuilder::buildBack(Purpose purpose)
		{
			buildFace<NORM_Z>(DeformFrontBack(bevel, shoulderInset), G3D::Vector2int16(1, 1), purpose);
		}

		void TorsoBuilder::buildLeft(Purpose purpose)
		{
			buildFace<NORM_X_NEG>(DeformSide(bevel, shoulderInset), G3D::Vector2int16(1, 1), purpose);
		}

		void TorsoBuilder::buildBottom(Purpose purpose)
		{
			buildFace<NORM_Y_NEG>(*this, 1, 1, purpose);
		}

		void TorsoBuilder::buildFront(Purpose purpose)
		{
			buildFace<NORM_Z_NEG>(DeformFrontBack(bevel, shoulderInset), G3D::Vector2int16(1, 1), purpose);
		}

		static const float bevel = 0.065f; // 008270f8

		TorsoMesh::TorsoMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes)
		{
			float shoulderInset = size.z * 0.3f;
			levels.push_back(new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS));

			TorsoBuilder builder(levels.last(), size, surfaceTypes, 0.0f, shoulderInset);
			builder.build(LevelBuilder::Surface);
		}

		TorsoMesh::TorsoMesh(const G3D::Vector3& size, NormalId decalFace)
		{
			float shoulderInset = size.z * 0.3f;
			G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level = new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS);
			levels.push_back(level);

			TorsoBuilder builder(level, size, RenderSurfaceTypes(), bevel, shoulderInset);
			builder.buildFace(decalFace, LevelBuilder::Decal);
		}

		TorsoMesh::TorsoMesh(const G3D::Vector3& size, NormalId textureFace, const G3D::Vector2& studsPerTile)
		{
			float shoulderInset = size.z * 0.3f;
			G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level = new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS);
			levels.push_back(level);

			TorsoBuilder builder(level, size, RenderSurfaceTypes(), bevel, shoulderInset);
			builder.textureScale = mapToUvw_Legacy(size, textureFace).xy() * 2.0f / studsPerTile;

			builder.buildFace(textureFace, LevelBuilder::Decal);
		}
	}
}
