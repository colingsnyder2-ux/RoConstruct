// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/openrbx/3rdparty/fmod/api/inc
// 2008-06 native leftovers of the view / sound units (inactive):
//   InstanceHandle::empty 004dc3d0 (util/Handle.h declaration; `target.px == NULL`).
//   SoundServiceStatsItem::update 005bcd80 (util/Sound.h declaration; service +0x158, currentalloced +0x15c,
//   maxalloced +0x160, numSounds +0x164, numUnusedSounds +0x168; SoundService system +0x134, fmod_version +0x138,
//   loadedSounds +0x180, loaded3DSounds +0x1a0; strings "fmod %08x" 008380a4 and "-disabled-" 00838098).
// Not built here (declarations owned elsewhere; see the header proposals of this batch):
//   ViewRbxGfx::suppressSkybox 004d9c90 needs the Lighting getters (v8datamodel/Lighting2008.h keeps the fields private).
//   Render::RenderScene::render 00504bf0 needs the private RenderScene helpers in RenderLib/RenderSceneRender2008.h.
// Already defined elsewhere (not duplicated): ViewNew EndcapTransform 004fd4a0 / CylinderTransform 004fd530
// (ViewNewCylinderMesh.cpp), LevelBuilder::offset 004f1ff0 (ViewNew/QuadVolume.h inline), CameraVerb::isEnabled
// 00565950 (NativeCameraCommands.h inline, ICF `return true`), ArrowTool::isSticky 005a04b0 (tool/ToolsArrow.h inline).
#include "util/Handle.h"
#include "util/Sound.h"
#include <fmod.hpp>

namespace RBX
{
	// 004dc3d0
	bool InstanceHandle::empty() const
	{
		return !target;
	}
}

// 005b83d0 (cdecl, called twice by update): counts the map's sounds and the ones nothing references.
// Decorated ?countSounds@@YAXABV?$map@VSoundId@Soundscape@RBX@@V?$shared_ptr@VSound@Soundscape@RBX@@@boost@@...@std@@AAI1@Z.
void countSounds(const std::map<RBX::Soundscape::SoundId, boost::shared_ptr<RBX::Soundscape::Sound> >& sounds,
                 size_t& numSounds, size_t& numUnusedSounds);

// 005bcd80
// PARKED near miss (293/293 B): the only divergence is the countSounds call setup; target
//   push edi; lea ecx,[esi+0x180]; push ebx; mov [edi],0; push ecx; mov [ebx],0
// this source emits push ecx before mov [edi],0. Rejected variants (do not repeat):
//   1. separate `numSounds = 0; numUnusedSounds = 0;` (ebx/edi swap: ebx=+0x168, edi=+0x164, push order changes).
//   2. chain `numSounds = numUnusedSounds = 0;` moved after the soundService local (service kept in ebx, this
//      advanced in esi; different registers).
//   3. no soundService local, `service->loadedSounds` directly (service reloaded into ecx, 299 B).
//   4. compiler gate roc_cl 50727 (native_bulk config): VC8 STL headers shift the layout (service +0x120), so the
//      unit is VS2008 RTM 21022 (MSVCP90 imports); /fp:fast flag profile gives the identical one-instruction diff.
void SoundServiceStatsItem::update()
{
	if (service->system)
	{
		formatValue(service->fmod_version, "fmod %08x", service->fmod_version);

		int current, max;
		if (FMOD::Memory_GetStats(&current, &max) == FMOD_OK)
		{
			currentalloced = current;
			maxalloced = max;
		}

		numSounds = numUnusedSounds = 0;
		const RBX::Soundscape::SoundService* soundService = service;
		countSounds(soundService->loadedSounds, numSounds, numUnusedSounds);
		countSounds(soundService->loaded3DSounds, numSounds, numUnusedSounds);
	}
	else
	{
		std::string disabled("-disabled-");
		val = 0;
		sValue = disabled;
	}
}
