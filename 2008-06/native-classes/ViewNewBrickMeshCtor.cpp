// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/brickcache-profile
// 2008-06 native RBX::ViewNew::BrickMesh constructor 004e53c0 (inactive). Same image block as the BrickMesh cache
// unit (ViewNewBrickMeshBuild2008.cpp: shadow box 004e3570, cache 004e5300..004e5710); the seven-argument
// constructor is declared by brickcache-profile/ViewNew/BrickMesh.h (INFERRED there from the create calls 004e5574 /
// 004e563c, ret 0x1c).
// Evidence (original 004e53c0, 248 bytes): Mesh() 00548570, vptr 00826e7c, meshKind +0x84 = 1; buildBevel 004e3720
// with all seven arguments when the three ints are non-zero, else buildBevel 004e2c80 (size, surfaceTypes, color);
// then, when the shadows flag 0096de64 is set and the render-mode int 00942ec4 is 0, buildShadowBox 004e3570 on
// size * 0.5f (00819bac) less the current bevel float 00972758 per axis, with shadowVertices +0x68 / shadowIndices
// +0x50.
#include "ViewNewBrickBuild2008/BrickMeshCache2008.h"

namespace RBX
{
	extern bool shadowsEnabled;   // 0096de64 (INFERRED name, pbb-surface-profile/RenderLib/ViewBase2008.h)
	// INFERRED: 00942ec4 is the render-mode int; createMaterial 00551730 builds RenderNew materials when it is 0.
	extern int renderMode;

	namespace ViewNew
	{
		// INFERRED: original global float 00972758 (same name as ViewNewBrickCacheRecovery2008.cpp).
		extern float currentBevel;

		// 004e53c0
		BrickMesh::BrickMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes, BrickColor color, int a, int b,
		                     int c, float scale)
		{
			meshKind = 1;

			if (a && b && c)
				buildBevel(size, surfaceTypes, color, a, b, c, scale);
			else
				buildBevel(size, surfaceTypes, color);

			if (shadowsEnabled && renderMode == 0)
			{
				G3D::Vector3 halfSize = size * 0.5f;
				buildShadowBox(G3D::Vector3(halfSize.x - currentBevel, halfSize.y - currentBevel, halfSize.z - currentBevel),
				               shadowVertices, shadowIndices);
			}
		}
	}
}
