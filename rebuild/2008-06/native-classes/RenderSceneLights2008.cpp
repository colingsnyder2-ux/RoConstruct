// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 2008-06 native RBX::Render::RenderScene::turnOnLights 00502100 (inactive). Source: the donor RenderLib/RenderScene.cpp
// body (authentic, tools/rbxgs). Declaration: RenderLib/RenderSceneRender2008.h.
#include "RenderLib/RenderSceneRender2008.h"
#include <GLG3D/RenderDevice.h>

namespace RBX
{
	namespace Render
	{
		void RenderScene::turnOnLights(G3D::RenderDevice* rd, bool allLights) const
		{
			rd->enableLighting();

			for (int i = 0; i < lighting->lightArray.size(); i++)
			{
				rd->setLight(i, lighting->lightArray[i]);
			}

			if (allLights)
			{
				for (int i = 0; i < lighting->shadowedLightArray.size(); i++)
				{
					rd->setLight(lighting->lightArray.size() + i, lighting->shadowedLightArray[i]);
				}
			}

			G3D::Color3 average = (lighting->ambientTop + lighting->ambientBottom) / 2.0f;
			rd->setAmbientLightColor(average);

			int runningTotal = lighting->shadowedLightArray.size() * 2;

			G3D::Vector3 direction = G3D::Vector3(-0.4f, -1.0f, 0.1f);
			if (lighting->shadowedLightArray.size() > 0)
			{
				direction = -lighting->shadowedLightArray.front().position.xyz();
			}

			if (effectSettings.hemisphereLighting())
			{
				if (lighting->ambientBottom != average)
				{
					rd->setLight(runningTotal, G3D::GLight::directional(direction, lighting->ambientBottom - average, false, true));
					runningTotal++;
				}

				if (lighting->ambientTop != average)
				{
					rd->setLight(runningTotal + 1, G3D::GLight::directional(G3D::Vector3::unitY(), lighting->ambientTop - average, false, true));
				}
			}
		}
	}
}
