// 2008-06 native RBX::Render::RenderScene private helpers and render (draft).
// 00504b60: prepareProxyArrays
// 00504bf0: render (vftable slot 5)
// roc-flags: /nologo /c /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /DNOMINMAX /DBOOST_ALL_NO_LIB /DWIN32 /DNDEBUG /D_LIB /D_RELEASE /D_RELEASEASSERT /D_VC80_UPGRADE=0x0710 /IC:\Users\colin\RoConstruct\rebuild\2008-06\native-headers /IC:\Users\colin\RoConstruct\tools\libs\mfc-9.0-rtm\atlmfc\include /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\App\include /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\RbxGraphics\include /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Network\include /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\RbxView\include /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Rendering\png /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Rendering\g3d\include /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Rendering\g3d\zlib /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Rendering\RenderLib\include /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Rendering\AppDraw\include /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\boost_1_34_1\src /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\App\lua-5.1.1\src /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Rendering\SDL-1.2.6\include /IC:\Users\colin\ROCONS~1\tools\VC2008~2\MICROS~1\VISUAL~1\9.0\WinSDK\Include /IC:\Users\colin\RoConstruct\tools\libs\ogre-1.4.5\ogrenew\OgreMain\include
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
		// 00504b60: Prepares proxy arrays for rendering. Sets up cameras, classifies proxies,
		// and sorts the three proxy pointer arrays.
		void RenderScene::prepareProxyArrays(int a1, int a2)
		{
			// Set up camera at +0x1e8
			G3D::GCamera& camera1 = *reinterpret_cast<G3D::GCamera*>(reinterpret_cast<char*>(this) + 0x1e8);
			camera1.GCamera::GCamera(); // 00511cf0

			// Call 00504290 with a1, a2
			setupProxyArrays(a1, a2); // INFERRED: 00504290

			// Call 00503540 - classify proxies into diffuse/transparent
			classifyProxies(); // INFERRED: 00503540

			// Set up camera at +0xe0
			G3D::GCamera& camera2 = *reinterpret_cast<G3D::GCamera*>(reinterpret_cast<char*>(this) + 0xe0);
			camera2.GCamera::GCamera(); // 00511cf0

			// Sort the three proxy arrays
			sortByMaterialAndDepth(diffuseProxyArray);    // 00505860
			sortByMaterial(reflectProxyArray);            // 00505890
			sortByDepth(transparentProxyArray);           // 005058c0

			camera2.GCamera::~GCamera(); // 00511df0
			camera1.GCamera::~GCamera(); // 00511df0

			// Copy size of diffuseProxyArray to +0x250
			*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x250) = diffuseProxyArray.size();
		}

		// 00504bf0: render (vftable slot 5)
		void RenderScene::render(G3D::RenderDevice* rd, const G3D::GCamera& camera)
		{
			// Stack frame setup (sub esp, 0x14)
			// Save registers: ebx, ebp, esi, edi
			// esi = rd (RenderDevice*), edi = this

			// Set up shadow camera at this + 0x138
			G3D::GCamera& shadowCamera = *reinterpret_cast<G3D::GCamera*>(reinterpret_cast<char*>(this) + 0x138);
			shadowCamera.GCamera::GCamera(); // 00511cf0

			// RenderDevice state setup
			// call 00476fc0 - increment state change counter
			// call 00476c90 - VARArea setup
			// call 0047b030 - floating point setup
			// call 00476cc0 - VARArea setup

			// Get camera far plane (camera + 0x3c)
			float cameraFarPlane = *reinterpret_cast<const float*>(reinterpret_cast<const char*>(&camera) + 0x3c);

			// Check shadow flag at this + 0x2d8
			bool shadowsEnabled = *reinterpret_cast<const char*>(this) + 0x2d8;

			// Check sky flag at this + 0x308 (sky RCP)
			bool hasSky = *reinterpret_cast<const int*>(reinterpret_cast<const char*>(this) + 0x308) != 0;

			// Set up render device for scene rendering
			// call 0047cd20 - complex state setup
			// call 0047cce0 - lea eax, [esi+0x120], lea ecx, [esi+0x880]
			// call 0047d360 - read stats counters

			// Call prepareProxyArrays (this + 0, 0)
			prepareProxyArrays(0, 0); // 00504b60

			// Turn on lights (first pass - all lights?)
			turnOnLights(rd, true); // 00502100

			// Render diffuse proxies
			// This is an inline loop over diffuseProxyArray
			for (int i = 0; i < diffuseProxyArray.size(); ++i)
			{
				const RenderSurface& surf = diffuseProxyArray[i];
				// Render each surface...
				rd->setObjectToWorldMatrix(surf.cframe);
				// ... rendering code
			}

			// Check debugShadowVolumes flag at this + 0x304
			bool debugShadows = *reinterpret_cast<const char*>(this) + 0x304;

			if (!debugShadows)
			{
				// Render shadow/reflect proxies
				for (int i = 0; i < reflectProxyArray.size(); ++i)
				{
					const RenderSurface& surf = *reflectProxyArray[i];
					rd->setObjectToWorldMatrix(surf.cframe);
					// ... rendering code
				}
				for (int i = 0; i < shadowProxyArray.size(); ++i)
				{
					const RenderSurface& surf = shadowProxyArray[i];
					rd->setObjectToWorldMatrix(surf.cframe);
					// ... rendering code
				}
			}

			// Light iteration loop
			G3D::ReferenceCountedPointer<G3D::Lighting>& lighting = *reinterpret_cast<G3D::ReferenceCountedPointer<G3D::Lighting>*>(reinterpret_cast<char*>(this) + 0x2ec);
			if (lighting.get() && lighting->lightArray.size() > 0)
			{
				for (int i = 0; i < lighting->lightArray.size(); ++i)
				{
					// Set up light-specific render state
					// call 00476d90, 00477090, etc.

					// Check EffectSettings flag at this + 0x2d5
					bool effectFlag = *reinterpret_cast<const char*>(this) + 0x2d5;

					if (effectFlag)
					{
						// call 004774f0, 00477770, 00478a00
					}
					else
					{
						// Turn on lights for this light
						turnOnLights(rd, false); // 00502100

						// Render sky/lighting for this light
						// This would be a call to 00503fe0
					}

					// Render transparent proxies
					for (int j = 0; j < transparentProxyArray.size(); ++j)
					{
						const RenderSurface& surf = *transparentProxyArray[j];
						rd->setObjectToWorldMatrix(surf.cframe);
						// ... rendering code
					}

					// Check debugShadowVolumes again
					if (!debugShadows)
					{
						// Additional rendering
					}
				}
			}

			// Final render device state cleanup
			// call 0047d360

			// Check EffectSettings flag at this + 0x2d4
			bool effectSettingsFlag = *reinterpret_cast<const char*>(this) + 0x2d4;

			if (effectSettingsFlag)
			{
				// Set up camera at this + 0x190
				G3D::GCamera& effectCamera = *reinterpret_cast<G3D::GCamera*>(reinterpret_cast<char*>(this) + 0x190);
				effectCamera.GCamera::GCamera(); // 00511cf0
				effectCamera.GCamera::~GCamera(); // 00511df0
			}

			// Final render pass
			// call 0047cce0
			// Render sky if present
			if (hasSky)
			{
				G3D::Sky* sky = sky.get(); // sky is at this + 0x308
				if (sky)
				{
					// Render sky
					sky->draw(rd, *reinterpret_cast<G3D::GCamera*>(reinterpret_cast<char*>(this) + 0xe0));
				}
			}

			// Check shadow flag at this + 0x2d8
			if (shadowsEnabled)
			{
				// Render shadow volumes
			}

			// Check another flag at this + 0x2da
			// Check sky flag at this + 0x2d8 again

			// Destroy shadow camera
			shadowCamera.GCamera::~GCamera(); // 00511df0

			// Final stats collection
			// call 004781b0, 004781c0, 004781d0, 004781e0 - get render stats
			// call 00420950 - timer
			// call 004781b0, 004781c0, 004781d0 - more stats

			// Store stats at this + 0x244, 0x24c, 0x240, 0x248, 0x254, 0x25c, 0x258, 0x260, 0x264
		}

		// INFERRED helper declarations (add to RenderSceneRender2008.h as // INFERRED: lines)
		// void clearProxyArrays();                                    // 00504b00
		// void prepareProxyArrays(int, int);                          // 00504b60
		// void setupProxyArrays(int, int);                            // 00504290
		// void classifyProxies();                                     // 00503540
	}
}