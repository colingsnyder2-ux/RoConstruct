// =============================================================================
// QuadVolume.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rbxview/QuadVolume.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "ViewNew/RenderBaseMesh.h"
#include "util/NormalId.h"
#include <G3D/Vector2int16.h>
#include <G3D/Rect2D.h>

namespace RBX
{
	namespace ViewNew
	{
		enum RenderSurfaceType
		{
			FLAT,
			STUDS,
			INLET,
			WELD,
			GLUE
		};

		class RenderSurfaceTypes
		{
		public:
			unsigned int data;
		public:
			RenderSurfaceTypes()
				: data(0)
			{
			}
		};

		class LevelBuilder
		{
			friend struct ::NativeViewNewLayout;
		public:
			enum Purpose
			{
				Surface,
				Decal,
				Shadow
			};
		protected:
			const G3D::Vector3 halfSize;                                             // +0x04
			const RenderSurfaceTypes surfaceTypes;                                   // +0x10
			const G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level;       // +0x14
		public:
			G3D::Vector2 textureScale;                                               // +0x18

		protected:
			LevelBuilder(G3D::ReferenceCountedPointer<RenderBase::Mesh::Level>& level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes); // 00500d80
		public:
			virtual void build(Purpose purpose);                                     // 00500d30
			void buildFace(NormalId normalId, Purpose purpose);                      // 00500ca0

			virtual void buildTop(Purpose purpose) = 0;
			virtual void buildBottom(Purpose purpose) = 0;
			virtual void buildLeft(Purpose purpose) = 0;
			virtual void buildRight(Purpose purpose) = 0;
			virtual void buildFront(Purpose purpose) = 0;
			virtual void buildBack(Purpose purpose) = 0;
		protected:
			template<NormalId id, class Function>
			void buildFace(Function function, G3D::Vector2int16 divisions, Purpose purpose);

			template<NormalId id, class Function>
			void buildFace(
				Function function,
				G3D::Rect2D rect,
				const float depth,
				G3D::Vector2 textureOrigin,
				G3D::Vector2 textureExtent,
				const int axis,
				G3D::Vector2int16 divisions);

			template<NormalId id, class Builder>
			void buildFace(Builder builder, const unsigned int x, const unsigned int y, Purpose purpose)
			{
				buildFace<id>(builder, G3D::Vector2int16(x, y), purpose);
			}

			static float offset(RenderSurfaceType surfaceType)
			{
				switch (surfaceType)
				{
				case STUDS:
					return 0.0f;
				case INLET:
					return 0.5f;
				case WELD:
					return 1.0f;
				case GLUE:
					return 1.5f;
				default:
					return 0.0f;
				}
			}

			void appendQuadFromIndexArray(int a, int b, int c, int d);               // 00501000
			void appendQuadFromIndexArray(int a, int b, int c);                      // 00500fd0
			void appendQuadFromVertexIndices(unsigned int a, unsigned int b, unsigned int c, unsigned int d); // 00500eb0
			void appendQuadFromVertexIndices(unsigned int a, unsigned int b, unsigned int c);                 // 00500de0
		};
	}
}
