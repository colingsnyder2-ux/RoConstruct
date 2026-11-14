// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/openrbx/Client/fmod/api/inc
#include "axis-vector-negation/G3D/Vector3.h"
#include "util/Sound.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/PVInstance.h"
#include <G3D/System.h>
#include <fmod.hpp>

namespace RBX {
namespace Soundscape {

void logFmodResult(FMOD_RESULT result);
bool toFmodVector(const G3D::Vector3& value, FMOD_VECTOR& out);

void SoundService::garbageCollectSounds()
{
	if (G3D::System::getTick() < nextGarbageCollectTime)
		return;
	gcSounds(loadedSounds);
	gcSounds(loaded3DSounds);
	nextGarbageCollectTime = G3D::System::getTick() + 5.0;
}

void SoundService::onEvent(const RunService*, Heartbeat)
{
	if (system)
	{
		if (Workspace* workspace = ServiceProvider::find<Workspace>(this))
		{
			if (Camera* camera = workspace->getCamera())
			{
				G3D::CoordinateFrame cf = camera->getCameraCoordinateFrame();
				FMOD_VECTOR pos;
				if (toFmodVector(cf.translation, pos))
				{
					FMOD_VECTOR forward;
					if (toFmodVector(-cf.lookVector(), forward))
					{
						FMOD_VECTOR up;
						if (toFmodVector(cf.upVector(), up))
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
			}
		}

		garbageCollectSounds();
		logFmodResult(system->update());
	}
}

}
}
