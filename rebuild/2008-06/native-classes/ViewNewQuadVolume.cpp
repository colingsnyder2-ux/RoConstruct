// 2008-06 native RBX::ViewNew::LevelBuilder (inactive): the QuadVolume unit 00500ca0..0050103f (+ Array<unsigned>::append 00500690).
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// ViewNewQuadVolume | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/8 mapped addresses byte-exact | 7 unproved | no mapped strings | by auto (+1) (chatgpt:gpt-6.1-sol)
// <<< native-status | src bb6961a0 | roc native-status --write
#include "ViewNew/QuadVolume.h"

namespace RBX
{
	namespace ViewNew
	{
		LevelBuilder::LevelBuilder(G3D::ReferenceCountedPointer<RenderBase::Mesh::Level>& level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes)
			: halfSize(size * 0.5f),
			  surfaceTypes(surfaceTypes),
			  level(level),
			  textureScale(2.0f, 2.0f)
		{
		}

		void LevelBuilder::buildFace(NormalId normalId, Purpose purpose)
		{
			switch (normalId)
			{
			case NORM_X:
				buildRight(purpose);
				break;
			case NORM_Y:
				buildTop(purpose);
				break;
			case NORM_Z:
				buildBack(purpose);
				break;
			case NORM_X_NEG:
				buildLeft(purpose);
				break;
			case NORM_Y_NEG:
				buildBottom(purpose);
				break;
			case NORM_Z_NEG:
				buildFront(purpose);
				break;
			}
		}

		void LevelBuilder::build(Purpose purpose)
		{
			buildTop(purpose);
			buildBottom(purpose);
			buildLeft(purpose);
			buildRight(purpose);
			buildFront(purpose);
			buildBack(purpose);
		}

		void LevelBuilder::appendQuadFromVertexIndices(unsigned int a, unsigned int b, unsigned int c)
		{
			switch (level->primitive)
			{
			case G3D::RenderDevice::TRIANGLES:
				level->indexArray.append(
					RenderBase::Mesh::allocVertex(a, 1),
					RenderBase::Mesh::allocVertex(b, 1),
					RenderBase::Mesh::allocVertex(c, 1));
				break;
			case G3D::RenderDevice::QUADS:
				level->indexArray.append(
					RenderBase::Mesh::allocVertex(a, 1),
					RenderBase::Mesh::allocVertex(a, 1),
					RenderBase::Mesh::allocVertex(b, 1),
					RenderBase::Mesh::allocVertex(c, 1));
				break;
			}
		}

		void LevelBuilder::appendQuadFromVertexIndices(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
		{
			switch (level->primitive)
			{
			case G3D::RenderDevice::TRIANGLES:
				level->indexArray.append(
					RenderBase::Mesh::allocVertex(a, 1),
					RenderBase::Mesh::allocVertex(b, 1),
					RenderBase::Mesh::allocVertex(c, 1));
				level->indexArray.append(
					RenderBase::Mesh::allocVertex(c, 1),
					RenderBase::Mesh::allocVertex(d, 1),
					RenderBase::Mesh::allocVertex(a, 1));
				break;
			case G3D::RenderDevice::QUADS:
				level->indexArray.append(
					RenderBase::Mesh::allocVertex(a, 1),
					RenderBase::Mesh::allocVertex(b, 1),
					RenderBase::Mesh::allocVertex(c, 1),
					RenderBase::Mesh::allocVertex(d, 1));
				break;
			}
		}

		void LevelBuilder::appendQuadFromIndexArray(int a, int b, int c)
		{
			appendQuadFromVertexIndices(level->indexArray[a], level->indexArray[b], level->indexArray[c]);
		}

		void LevelBuilder::appendQuadFromIndexArray(int a, int b, int c, int d)
		{
			appendQuadFromVertexIndices(level->indexArray[a], level->indexArray[b], level->indexArray[c], level->indexArray[d]);
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh::Level>;
