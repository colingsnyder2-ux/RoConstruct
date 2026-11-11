// 2008-06 native RBX::RenderNew::RenderScene (the Ogre render scene; inactive). Its own optimized unit (document-swap
// flags, /O2, /fp:fast, Ogre 1.4.5 client headers), 007aa770 .. 007ab0a0: setThrottle 007aa770, setLighting 007aa8b0,
// presetLighting 007aacc0, ??_G 007aae20 and the ctor 007aae40 (all exact). The dtor 007aaa30 (deletes the Ogre::RbxSceneNode /
// RbxEntity forks) and render 007ab0a0 are not built. Declarations: RenderLib/RenderSceneNew2008.h.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#include "RenderLib/RenderSceneNew2008.h"
#include <G3D/Vector4.h>

namespace RBX
{
	namespace RenderNew
	{
		RenderScene::RenderScene()
			: entity(NULL),
			  shadows(false),
			  cameraDistance(G3D::inf()),
			  debugShadowVolumes(false)
		{
			desiredLighting = lighting = G3D::Lighting::create();
			rootNode = NULL;

			// The clear colour goes through the out-of-line G3D Color4(const Vector4&) (Color4.cpp; call 007ab068 ->
			// 00476550, ret 4) into a named local, then the inline operator= copies it from the stack to +0x14.
			// (A Color4 copy ctor would be inline: G3D Color4.inl.)
			G3D::Color4 clearColor(G3D::Vector4(0.5f, 0.5f, 1.0f, 1.0f));
			colorClearValue = clearColor;
		}

		void RenderScene::setThrottle(float t, float m, bool s, float c)
		{
			t = G3D::clamp(t, 0.0f, 100.0f);
			if (t != shadingQuality || m != meshDetail || s != shadows || c != cameraDistance)
			{
				shadingQuality = t;
				meshDetail = m;
				cameraDistance = c;
				shadows = s;

				lighting = effectSettings.update(t, m, s, c, desiredLighting, desiredSkyParameters, skyParameters);
			}
		}

		void RenderScene::setLighting(const G3D::ReferenceCountedPointer<G3D::Lighting>& L)
		{
			desiredLighting = L;
			lighting = effectSettings.update(shadingQuality, meshDetail, shadows, cameraDistance, desiredLighting,
			                                 desiredSkyParameters, skyParameters);
		}

		void RenderScene::presetLighting(G3D::ReferenceCountedPointer<G3D::Sky> sky, G3D::LightingParameters skyParameters,
		                                 G3D::Color3 ambientTop, G3D::Color3 ambientBottom)
		{
			desiredSkyParameters = skyParameters;

			G3D::ReferenceCountedPointer<G3D::Lighting> lighting = G3D::Lighting::create();
			lighting->ambientTop = ambientTop;
			lighting->ambientBottom = ambientBottom;

			G3D::GLight sun = G3D::GLight::directional(skyParameters.lightDirection, skyParameters.lightColor * 0.9f);
			lighting->shadowedLightArray.append(sun);

			setLighting(lighting);
		}
	}
}
