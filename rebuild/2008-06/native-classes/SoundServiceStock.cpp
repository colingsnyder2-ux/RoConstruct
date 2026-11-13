// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
#include "axis-vector-negation/G3D/Vector3.h"
#include "SoundChannel/SoundChannel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/Stats.h"
#include <g3d/system.h>
namespace RBX {
namespace Soundscape {
void SoundService::loadStockSounds()
		{
			stockSounds.clear();
			removeAllChildren();
			loadStockSounds(BOING_SOUND, "Sounds\\bass.wav");
			loadStockSounds(BOMB_SOUND, "Sounds\\collide.wav");
			loadStockSounds(BREAK_SOUND, "Sounds\\glassbreak.wav");
			loadStockSounds(CLICK_SOUND, "Sounds\\switch.wav");
			loadStockSounds(CLOCK_SOUND, "Sounds\\clickfast.wav");
			loadStockSounds(RUBBERBAND_SOUND, "Sounds\\Rubber band sling shot.wav");
			loadStockSounds(PAGE_SOUND, "Sounds\\pageturn.wav");
			loadStockSounds(PING_SOUND, "Sounds\\electronicpingshort.wav");
			loadStockSounds(SNAP_SOUND, "Sounds\\snap.wav");
			loadStockSounds(SPLAT_SOUND, "Sounds\\splat.wav");
			loadStockSounds(STEP_SOUND, "Sounds\\SWITCH3.wav");
			loadStockSounds(STEP_ON_SOUND, "Sounds\\flashbulb.wav");
			loadStockSounds(SWOOSH_SOUND, "Sounds\\swoosh.wav");
			loadStockSounds(VICTORY_SOUND, "Sounds\\victory.wav");
		}
}
}
