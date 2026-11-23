// =============================================================================
// EffectSettings.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/renderlib/include/renderlib/EffectSettings.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "RenderLib/DepthBlur.h"
#include <GLG3D/ToneMap.h>
#include <GLG3D/LightingParameters.h>

namespace RBX
{
	namespace Render
	{
		class EffectSettings
		{
		private:
			bool _stencilShadows;
			bool _alphaBlendShadowLights;
			bool _useAllLightsInUnshadowedPass;
			bool _skyBox;
			bool _toneMap;
			bool _hemisphereLighting;
			bool _depthBlur;
			float _farCullZ;
			float _groundLOD;
			float _LODShift;
		public:
			G3D::ReferenceCountedPointer<G3D::Lighting> update(
				float,
				float,
				bool,
				float,
				const G3D::ReferenceCountedPointer<G3D::Lighting>&,
				const G3D::LightingParameters&,
				G3D::LightingParameters&);

			bool stencilShadows() const
			{
				return _stencilShadows;
			}
			bool hemisphereLighting() const
			{
				return _hemisphereLighting;
			}
			bool skyBox() const
			{
				return _skyBox;
			}
			float farCullZ() const;
			bool alphaBlendShadowLights() const
			{
				return _alphaBlendShadowLights;
			}
			bool useAllLightsInUnshadowedPass() const
			{
				return _useAllLightsInUnshadowedPass;
			}
			float groundLOD() const;
			float LODShift() const;
			bool applyToneMap() const
			{
				return _toneMap;
			}
			bool applyDepthBlur() const
			{
				return _depthBlur;
			}

			static G3D::ToneMap* getToneMap();
			static DepthBlur* getDepthBlur();
		};
	}
}
