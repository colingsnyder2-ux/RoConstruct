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
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/Stats.h"
#include <G3D/System.h>
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

// SoundService members of the util/Sound.cpp unit (005bc2c0 sits before SoundChannel::updateListenState 005bc5b0;
// 005bdcf0 follows SoundChannel::setPlayCount 005bda10). They are built here, not in SoundChannel.cpp, because the
// FMOD subset of native-headers/SoundChannel/SoundChannel.h has no System::set3DListenerAttributes / update and no
// FMOD_VECTOR; this unit uses util/Sound.h with the SDK fmod.hpp. Layout (util/Sound.h, confirmed by the accesses):
// Listener<RunService, Heartbeat> +0x130, system +0x134, statsItem +0x168, nextGarbageCollectTime +0x178,
// loadedSounds +0x180, loaded3DSounds +0x1a0.
namespace RBX
{
	namespace Soundscape
	{
		// INFERRED: name (same declaration as SoundChannel.cpp). 005b87a0 logs a failed FMOD result (cdecl, no throw).
		void logFmodResult(FMOD_RESULT result); // 005b87a0
		// INFERRED: name. 005b70c0 (cdecl, two pointer arguments, returns bool): zeroes denormal components
		// (Math::isDenormal 005dd7b0), returns false when 005dd8b0 rejects the vector, else scales it into the FMOD vector.
		bool toFmodVector(const G3D::Vector3& v, FMOD_VECTOR& out); // 005b70c0

		// 005bc2c0 (Listener<RunService, Heartbeat> slot: this is the listener subobject, system at +4).
		// find<Workspace>(const Instance*) 00491e50, Camera::getCameraCoordinateFrame 0045af00, lookVector 005187f0,
		// Matrix3::getColumn(1) 00513240, getCameraSubjectInstance 005cc410, dynamic_cast Instance 0092907c ->
		// PVInstance 00947f1c, getPrimaryPart through the IPrimaryPart virtual base (PVInstance vbptr +0x134),
		// PartInstance velocity 00599850, getTick 005083d0, gcSounds 005ba2e0, 5.0 (008358a8).
		void SoundService::onEvent(const RunService*, Heartbeat)
		{
			if (system)
			{
				if (Workspace* workspace = ServiceProvider::find<Workspace>(this))
				{
					if (Camera* camera = workspace->getCamera())
					{
						G3D::CoordinateFrame cf = camera->getCameraCoordinateFrame();
						FMOD_VECTOR pos, forward, up;
						if (toFmodVector(cf.translation, pos) && toFmodVector(-cf.lookVector(), forward)
							&& toFmodVector(cf.upVector(), up))
						{
							FMOD_VECTOR vel;
							vel.x = vel.y = vel.z = 0;
							if (PVInstance* pv = dynamic_cast<PVInstance*>(camera->getCameraSubjectInstance()))
							{
								if (PartInstance* part = pv->getPrimaryPart())
									toFmodVector(part->getLinearVelocity(), vel);
							}
							logFmodResult(system->set3DListenerAttributes(0, &pos, &vel, &forward, &up));
						}
					}
				}

				if (G3D::System::getTick() >= nextGarbageCollectTime)
				{
					gcSounds(loadedSounds);
					gcSounds(loaded3DSounds);
					nextGarbageCollectTime = G3D::System::getTick() + 5.0;
				}

				logFmodResult(system->update());
			}
		}

		// 005bdcf0: find<RunService>() const 00452c80, removeListener 005e5a80 / addListener 004218a0 (Notifier at
		// RunService +0x130), Instance::setParent 0055a8f0, shared_ptr<Instance>::reset 00456e80, closeFmod 005ba970,
		// openFmod 005ba060, loadStockSounds 005bdb10, create<StatsService>() const 00458610,
		// Creatable<Instance>::create<SoundServiceStatsItem> 005bd1d0. No Instance::onServiceProvider call.
		void SoundService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
		{
			Notifier<RunService, Heartbeat>::disconnect(ServiceProvider::find<RunService>(oldProvider), this);

			if (statsItem)
			{
				statsItem->setParent(NULL);
				statsItem.reset();
			}

			if (oldProvider)
				closeFmod();

			Notifier<RunService, Heartbeat>::connect(ServiceProvider::find<RunService>(newProvider), this);

			if (newProvider)
			{
				openFmod();
				loadStockSounds();

				if (Stats::StatsService* stats = newProvider->create<Stats::StatsService>())
				{
					statsItem = Creatable<Instance>::create<SoundServiceStatsItem>(this);
					statsItem->setParent(stats);
				}
			}
		}
	}
}
