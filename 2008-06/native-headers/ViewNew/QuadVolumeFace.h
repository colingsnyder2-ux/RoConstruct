#pragma once
// >>> native-status (generated) -- do not edit >>>
// QuadVolumeFace | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src de40ab62 | roc native-status --write
// 2008-06 native RBX::ViewNew::LevelBuilder per-face grid templates (inactive): the bodies of the two buildFace templates
// that QuadVolume.h declares, included by the builder units (Sphere / Cylinder / Head / Wedge / Torso / PBB), which
// instantiate them implicitly as the original units did (tests/record_native_viewnew.py checks every instance).
// Codegen notes (one evidence-backed spelling each, not claims about the original declarations):
//   * faceToObject<id> is an inline pass-through to the out-of-line uvwToObject<id> (util/NormalId.h): the original
//     reads the transformed half size back from its stack temporary (fld [esp+..]) instead of through eax, which a
//     direct G3D::abs(uvwToObject<id>(halfSize)) produces; with the wrapper all 18 outer instances are exact.
//   * the strip names the scaled texture coordinate and both transformed vectors before Mesh::allocVertex: the
//     original computes all three temporaries (texture, normal, position) before it pushes the share flag.
//   grid    buildFace<id, Function>(Function, Vector2int16 divisions, Purpose) (instances 004fbdb0.. for the plain
//           vertex function, ret 0xc plus the functor size): surface type (data >> 3*id) & 7, halfSize in face
//           space through uvwToObject<id> (005ec1a0 NORM_X, 005ec1c0 NORM_Y, ..) and fabs, the long axis, the strip
//           count iRound(ceil(size[axis] * 0.5f)) for studded surfaces, the texture origin / extent per purpose
//           (FLAT surface (0.25, 0.5); studded offset() 004f1ff0 and 0.5; Decal from textureScale +0x18), then one
//           strip per 4 studs (4.0f 00826e6c; the last strip scales the extent by 0.25f 0083a3e4).
//   strip   buildFace<id, Function>(Function, Rect2D, depth, textureOrigin, textureExtent, axis, divisions)
//           (instances 004fac10.., ret 0x30 plus the functor size): new unsigned[(x+1)*(y+1)] (operator new[] 006a0956),
//           one Mesh::allocVertex 00548000 per grid point after the vertex function, a texture coordinate reset to
//           the origin when the extent is Vector2::zero() 00509ba0, then appendQuadFromVertexIndices 00500eb0 per
//           cell, Mesh::freeVertex 00548640 per vertex and delete[] 006a094a.
#include "ViewNew/QuadVolume.h"
#include <G3D/g3dmath.h>
#include <G3D/vectorMath.h>
#include <G3D/Rect2D.h>
#include <algorithm>

namespace RBX
{
	namespace ViewNew
	{
		template<NormalId id>
		inline G3D::Vector3 faceToObject(const G3D::Vector3& v)
		{
			return uvwToObject<id>(v);
		}

		template<NormalId id, class Function>
		void LevelBuilder::buildFace(Function function, G3D::Rect2D rect, const float depth, G3D::Vector2 textureOrigin, G3D::Vector2 textureExtent, const int axis, G3D::Vector2int16 divisions)
		{
			const G3D::Vector3 size = G3D::abs(faceToObject<id>(halfSize));

			G3D::Vector2 positionStep((rect.x1() - rect.x0()) / divisions.x, (rect.y1() - rect.y0()) / divisions.y);
			G3D::Vector2 textureStep(textureExtent.x / divisions.x, textureExtent.y / divisions.y);

			unsigned int count = (divisions.x + 1) * (divisions.y + 1);
			unsigned int* vertices = new unsigned int[count];

			float x = rect.x0();
			float u = textureOrigin.x;
			for (int i = 0; i <= divisions.x; ++i)
			{
				float y = rect.y0();
				float v = textureOrigin.y;
				for (int j = 0; j <= divisions.y; ++j)
				{
					G3D::Vector3 position(x, y, depth);
					G3D::Vector2 texCoord;
					texCoord[1 - axis] = u;
					texCoord[axis] = v;
					G3D::Vector3 normal(0.0f, 0.0f, 1.0f);

					function(position, normal, texCoord, size, G3D::Vector2int16(i, j));

					if (textureExtent == G3D::Vector2::zero())
						texCoord = textureOrigin;

					const G3D::Vector2 tex = texCoord * 0.5f;
					const G3D::Vector3 objectNormal = uvwToObject<id>(normal);
					const G3D::Vector3 objectPosition = uvwToObject<id>(position);
					vertices[(divisions.y + 1) * i + j] = RenderBase::Mesh::allocVertex(objectPosition, objectNormal, tex, true);

					y += positionStep.y;
					v += textureStep.y;
				}
				x += positionStep.x;
				u += textureStep.x;
			}

			for (int i = 0; i < divisions.x; ++i)
			{
				for (int j = 0; j < divisions.y; ++j)
				{
					int k = (divisions.y + 1) * i + j;
					int l = k + divisions.y;
					appendQuadFromVertexIndices(vertices[k + 1], vertices[k], vertices[l + 1], vertices[l + 2]);
				}
			}

			for (unsigned int i = 0; i < count; ++i)
				RenderBase::Mesh::freeVertex(vertices[i]);

			delete[] vertices;
		}

		template<NormalId id, class Function>
		void LevelBuilder::buildFace(Function function, G3D::Vector2int16 divisions, Purpose purpose)
		{
			RenderSurfaceType surfaceType = (RenderSurfaceType)((surfaceTypes.data >> (3 * id)) & 7);

			const G3D::Vector3 size = G3D::abs(faceToObject<id>(halfSize));

			bool horizontal = purpose == Surface && size.x < size.y;
			const int axis = horizontal ? 0 : 1;

			int strips = (purpose == Surface && surfaceType != FLAT) ? G3D::iRound((float)ceil(size[axis] * 0.5f)) : 1;

			G3D::Vector2int16 stripDivisions;
			short n = divisions[1 - axis];
			stripDivisions[axis] = std::max<short>(1, n / strips);
			stripDivisions[1 - axis] = n;

			const float depth = size.z;
			G3D::Vector2 begin = -size.xy();
			G3D::Vector2 end = size.xy();

			G3D::Vector2 textureOrigin;
			G3D::Vector2 textureExtent;
			switch (purpose)
			{
			case Surface:
				if (surfaceType == FLAT)
				{
					textureOrigin = G3D::Vector2(0.25f, 0.5f);
					textureExtent[1 - axis] = 0.0f;
					textureExtent[axis] = 0.0f;
				}
				else
				{
					textureOrigin[1 - axis] = 0.0f;
					textureOrigin[axis] = offset(surfaceType);
					textureExtent[1 - axis] = size[1 - axis] * 2.0f;
					textureExtent[axis] = 0.5f;
					if (axis == 1)
						textureExtent.x = -textureExtent.x;
				}
				break;
			case Decal:
				textureOrigin.x = 0.0f;
				textureOrigin.y = textureScale.y;
				textureExtent.x = textureScale.x;
				textureExtent.y = -textureScale.y;
				break;
			case Shadow:
				textureOrigin = G3D::Vector2(0.0f, 0.0f);
				textureExtent = G3D::Vector2(0.0f, 0.0f);
				break;
			}

			for (int i = 0; i < strips; ++i)
			{
				if (i == strips - 1)
				{
					end[axis] = size[axis];
					if (purpose == Surface && surfaceType != FLAT)
						textureExtent[axis] = (end[axis] - begin[axis]) * textureExtent[axis] * 0.25f;
				}
				else
				{
					end[axis] = begin[axis] + 4.0f;
				}
				buildFace<id>(function, G3D::Rect2D::xyxy(begin, end), depth, textureOrigin, textureExtent, axis, stripDivisions);
				begin[axis] = end[axis];
			}
		}
	}
}
