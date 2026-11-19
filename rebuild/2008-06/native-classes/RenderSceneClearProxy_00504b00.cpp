// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 00504b00 RenderScene::clearProxyArrays (95 bytes); other drafted members split off, unproven.
#include <RenderLib/RenderSceneRender2008.h>
#include <GLG3D/RenderDevice.h>
#include <G3D/GCamera.h>
#include <GLG3D/LightingParameters.h>
#include <GLG3D/Sky.h>
#include <GLG3D/VAR.h>
#include <GLG3D/VARArea.h>
#include <GLG3D/Texture.h>
namespace RBX
{
	namespace Render
	{
		// 00504b00: Clears all proxy arrays and shadow caching chunk array.
		// Calls resize(0, false) (fastClear) on each array.
		void RenderScene::clearProxyArrays()
		{
			// diffuseProxyArray: G3D::Array<RenderSurface*> at +0x274
			diffuseProxyArray.resize(0, false);
			// shadowProxyArray: G3D::Array<RenderSurface> at +0x298
			shadowProxyArray.resize(0, false);
			// reflectProxyArray: G3D::Array<RenderSurface*> at +0x280
			reflectProxyArray.resize(0, false);
			// transparentProxyArray: G3D::Array<RenderSurface*> at +0x28c
			transparentProxyArray.resize(0, false);
			// proxyArray: G3D::Array<RenderSurface> at +0x268
			proxyArray.resize(0, false);
			// shadowCachingChunkArray: G3D::Array<G3D::ReferenceCountedPointer<RenderBase::Chunk>> at +0x2a4
			shadowCachingChunkArray.resize(0, false);
		}
	}
}
