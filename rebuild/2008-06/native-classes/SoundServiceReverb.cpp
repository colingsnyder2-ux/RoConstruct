// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/openrbx/Client/fmod/api/inc /I{headers}/../../../tools/openrbx/Client/fmod/api/inc
#include "util/Sound.h"
#include <G3D/System.h>
#include <fmod.hpp>
#include <stdlib.h>

namespace RBX {
namespace Soundscape {

void logFmodResult(FMOD_RESULT result);   // 005b87a0 (non-throwing check)

void SoundService::updateAmbientReverb()
		{
			if (system)
			{
				switch (ambientReverb)
				{
				case NoReverb:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_OFF;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case GenericReverb:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_GENERIC;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case PaddedCell:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_PADDEDCELL;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case Room:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_PADDEDCELL;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case Bathroom:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_BATHROOM;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case LivingRoom:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_LIVINGROOM;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case StoneRoom:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_STONEROOM;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case Auditorium:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_AUDITORIUM;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case ConcertHall:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_CONCERTHALL;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case Cave:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_CAVE;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case Arena:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_ARENA;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case Hangar:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_HANGAR;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case CarpettedHallway:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_CARPETTEDHALLWAY;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case Hallway:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_HALLWAY;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case StoneCorridor:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_STONECORRIDOR;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case Alley:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_ALLEY;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case Forest:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_FOREST;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case City:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_CITY;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case Mountains:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_MOUNTAINS;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case Quarry:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_QUARRY;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case Plain:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_PLAIN;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case ParkingLot:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_PARKINGLOT;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case SewerPipe:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_SEWERPIPE;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				case UnderWater:
				{
					FMOD_REVERB_PROPERTIES p = FMOD_PRESET_UNDERWATER;
					logFmodResult(system->setReverbProperties(&p));
					break;
				}
				}
			}
		}


}
}
