// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 2008-06 native RBX::Render::RenderScene::computeProxyArrays 00504b60 and render 00504bf0 (vftable 00827454 slot 5;
// inactive). Source: the donor RenderLib/RenderScene.cpp bodies (authentic, tools/rbxgs), whose call sequence the
// 2008-06 bodies follow call for call: RenderStats Stopwatches at +0x30 + 0x58 * n (sort +0xe0, cpuRenderTotal +0x138,
// cpuShadow +0x190, computeProxyArrays +0x1e8; tick 00511cf0 / tock 00511df0), diffuseProxyCount +0x250, the int
// stats +0x240..+0x264, EffectSettings flags +0x2d4..+0x2da. Differences from the donor seen in the binary: the six
// fastClear calls are the out-of-line clearProxyArrays 00504b00 (RenderSceneClearProxy_00504b00.cpp).
// Declarations: RenderLib/RenderSceneRender2008.h.
#include "RenderLib/RenderSceneRender2008.h"
#include "ViewNew/RenderBaseMesh.h"
#include <GLG3D/RenderDevice.h>
#include <GLG3D/Sky.h>

namespace RBX
{
	namespace Render
	{
		// 00504b60
		void RenderScene::computeProxyArrays(G3D::RenderDevice* rd, const G3D::GCamera& camera)
		{
			renderStats.computeProxyArrays.tick();

			clearProxyArrays();                      // 00504b00
			allocateProxies(rd, camera);             // 00504290
			classifyProxies();                       // 00503540

			renderStats.sort.tick();

			sortByMaterialAndDepth(diffuseProxyArray);
			sortByMaterial(reflectProxyArray);
			sortByDepth(transparentProxyArray);

			renderStats.sort.tock();
			renderStats.computeProxyArrays.tock();

			renderStats.diffuseProxyCount = diffuseProxyArray.size();
		}

		// 00504bf0
		void RenderScene::render(G3D::RenderDevice* rd, const G3D::GCamera& camera)
		{
			int startTriangleCount = rd->getTriangleCount();
			int markShadowsTriCount = 0;
			int unshadowedTriCount = 0;
			int shadowedTriCount = 0;

			renderStats.cpuRenderTotal.tick();

			rd->setStencilConstant(0);
			rd->setStencilClearValue(0);
			rd->setProjectionAndCameraMatrix(camera);

			if (effectSettings.applyToneMap())
			{
				effectSettings.getToneMap()->beginFrame(rd);
			}

			rd->setColorClearValue(colorClearValue);
			rd->clear(sky.isNull() || !effectSettings.skyBox(), true, true);

			if (sky.notNull() && effectSettings.skyBox())
			{
				sky->render(rd, skyParameters);
			}

			computeProxyArrays(rd, camera);

			rd->setShadeMode(G3D::RenderDevice::SHADE_SMOOTH);
			rd->setDepthTest(G3D::RenderDevice::DEPTH_LEQUAL);
			rd->setAlphaTest(G3D::RenderDevice::ALPHA_GREATER, 0.1);
			rd->pushState();

			turnOnLights(rd, effectSettings.useAllLightsInUnshadowedPass());

			RenderBase::Mesh::beginRender(rd, true, false);

			if (!debugShadowVolumes)
			{
				int prevTriangleCount = rd->getTriangleCount();
				sendDiffuseProxyMeshGeometry(rd);
				unshadowedTriCount = rd->getTriangleCount() - prevTriangleCount;
			}

			RenderBase::Mesh::endRender(rd);

			rd->popState();

			if (effectSettings.stencilShadows())
			{
				rd->pushState();
				rd->disableDepthWrite();
				rd->setDepthTest(G3D::RenderDevice::DEPTH_LEQUAL);

				for (int i = 0; i < lighting->shadowedLightArray.size(); i++)
				{
					if (i > 0)
					{
						rd->clear(false, false, true);
					}

					const G3D::GLight& current = lighting->shadowedLightArray[i];

					if (effectSettings.alphaBlendShadowLights())
					{
						rd->setBlendFunc(G3D::RenderDevice::BLEND_ONE, G3D::RenderDevice::BLEND_ONE, G3D::RenderDevice::BLENDEQ_ADD);
						rd->enableLighting();
						rd->setLight(0, current);
					}
					else
					{
						turnOnLights(rd, true);
					}

					int prevTriangleCount = rd->getTriangleCount();
					markStencilShadows(rd, camera, current);
					markShadowsTriCount += rd->getTriangleCount() - prevTriangleCount;

					if (!debugShadowVolumes)
					{
						rd->setStencilConstant(0);
						rd->setDepthTest(G3D::RenderDevice::DEPTH_LEQUAL);

						int prevTriCount = rd->getTriangleCount();

						rd->setPolygonOffset(0.0);
						rd->setStencilTest(G3D::RenderDevice::STENCIL_EQUAL);

						RenderBase::Mesh::beginRender(rd, true, false);
						sendDiffuseProxyMeshGeometry(rd);
						RenderBase::Mesh::endRender(rd);

						shadowedTriCount += rd->getTriangleCount() - prevTriCount;
					}
				}

				rd->popState();
			}
			else
			{
				renderStats.cpuShadow.tick();
				renderStats.cpuShadow.tock();
			}

			rd->pushState();

			RenderBase::Mesh::beginRender(rd, true, false);
			reflectionPass(rd);
			RenderBase::Mesh::endRender(rd);

			rd->popState();

			rd->pushState();

			turnOnLights(rd, true);
			RenderBase::Mesh::beginRender(rd, true, false);
			transparentPass(rd);
			RenderBase::Mesh::endRender(rd);

			rd->popState();

			if (sky.notNull() && effectSettings.skyBox())
			{
				sky->renderLensFlare(rd, skyParameters);
			}

			if (effectSettings.applyDepthBlur())
			{
				effectSettings.getDepthBlur()->apply(rd);
			}

			if (effectSettings.applyToneMap())
			{
				effectSettings.getToneMap()->endFrame(rd);
			}

			renderStats.cpuRenderTotal.tock();
			renderStats.pushPopCount = rd->debugNumPushStateCalls();

			int endTriangleCount = rd->getTriangleCount();

			renderStats.markShadowsTriangles = markShadowsTriCount;
			renderStats.totalTriangles = endTriangleCount - startTriangleCount;
			renderStats.shadowedLightTriangles = shadowedTriCount;
			renderStats.unshadowedTriangles = unshadowedTriCount;
			renderStats.majorGLStateChanges = rd->debugNumMajorOpenGLStateChanges();
			renderStats.minorGLStateChanges = rd->debugNumMinorOpenGLStateChanges();
			renderStats.majorStateChanges = rd->debugNumMajorStateChanges();
			renderStats.minorStateChanges = rd->debugNumMinorStateChanges();
		}
	}
}
