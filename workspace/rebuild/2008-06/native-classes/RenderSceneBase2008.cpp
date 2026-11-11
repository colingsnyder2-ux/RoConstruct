// 2008-06 native RBX::RenderBase::RenderSceneBase and RBX::Render::RenderScene (inactive). One optimized unit
// (document-swap flags, /O2, /fp:fast), as in the original: the RenderSceneBase ctor 00504fd0 sits between the
// Render::RenderScene bodies and is called out of line by both scene constructors; the base dtor is header-inline and
// its out-of-line copy 005039d0 is emitted for the constructors' EH unwind.
//   RenderSceneBase: ctor 00504fd0, dtor 005039d0, ??_G 00503a30, presetLighting default 005039e0.
//   Render::RenderScene: ctor 00505040, dtor 00503a60, ??_G 00503fc0, setThrottle 00502d30, setLighting 00502e70,
//   presetLighting 00503cc0, the RenderSurface sort procs 005051e0 / 00505220 / 00505240 and sortBy* 00505860 /
//   00505890 / 005058c0 with their std::sort helpers. render 00504bf0 is not built (declared only).
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// RenderSceneBase2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 7224c665 | roc native-status --write
#include "RenderLib/RenderSceneRender2008.h"
#include <exception>

namespace RBX
{
	namespace RenderBase
	{
		RenderSceneBase::RenderSceneBase()
			: colorClearValue(0.5f, 0.5f, 1.0f, 1.0f),
			  shadingQuality(-1.0f),
			  meshDetail(-1.0f)
		{
		}

		void RenderSceneBase::presetLighting(G3D::ReferenceCountedPointer<G3D::Sky> sky, G3D::LightingParameters skyParameters,
		                                     G3D::Color3 ambientTop, G3D::Color3 ambientBottom)
		{
			throw std::exception("shouldn't be here");
		}
	}

	namespace Render
	{
		bool materialDepthPtrSortProc(RenderSurface* const& A, RenderSurface* const& B)
		{
			return A->material < B->material || (A->material == B->material && A->z > B->z);
		}

		bool materialPtrSortProc(RenderSurface* const& A, RenderSurface* const& B)
		{
			return A->material < B->material;
		}

		bool depthPtrSortProc(RenderSurface* const& A, RenderSurface* const& B)
		{
			return A->z < B->z;
		}

		void sortByMaterialAndDepth(G3D::Array<RenderSurface*>& array)
		{
			std::sort(array.begin(), array.end(), &materialDepthPtrSortProc);
		}

		void sortByMaterial(G3D::Array<RenderSurface*>& array)
		{
			std::sort(array.begin(), array.end(), &materialPtrSortProc);
		}

		void sortByDepth(G3D::Array<RenderSurface*>& array)
		{
			std::sort(array.begin(), array.end(), &depthPtrSortProc);
		}

		RenderScene::RenderScene()
			: shadows(false),
			  cameraDistance(G3D::inf()),
			  debugShadowVolumes(false)
		{
			desiredLighting = lighting = G3D::Lighting::create();
		}

		RenderScene::~RenderScene()
		{
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
			this->sky = sky;
			desiredSkyParameters = skyParameters;

			G3D::ReferenceCountedPointer<G3D::Lighting> lighting = G3D::Lighting::create();
			lighting->ambientTop = ambientTop;
			lighting->ambientBottom = ambientBottom;

			G3D::GLight sun = G3D::GLight::directional(skyParameters.lightDirection, skyParameters.lightColor * 0.9f);
			lighting->shadowedLightArray.append(sun);

			if (sky.notNull())
			{
				lighting->environmentMap = sky->getEnvironmentMap();
			}

			setLighting(lighting);
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class G3D::ReferenceCountedPointer<G3D::Lighting>;
template class std::pair<RBX::Render::RenderSurface * *,RBX::Render::RenderSurface * *>;
