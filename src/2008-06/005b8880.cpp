// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_reverb_room_ed1e431bee9bec28.cpp

// Candidate translation unit (score above; library headers required).
#include "../../../openrbx/3rdparty/fmod/api/inc/fmod.hpp"
void __cdecl soundError(FMOD_RESULT);
// Opaque 2008 service: target 005b8880 reads system at +0x134 and enum at +0x170.
// Old RBXGS SoundService layout is eight bytes smaller; do not invent missing fields.
class SoundServiceReverb { public: void updateAmbientReverb(); };
void SoundServiceReverb::updateAmbientReverb() {
 FMOD::System* system = *reinterpret_cast<FMOD::System**>(reinterpret_cast<char*>(this)+0x134);
 if (!system) return;
 switch(*reinterpret_cast<unsigned*>(reinterpret_cast<char*>(this)+0x170)) {
case 0: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_OFF; soundError(system->setReverbProperties(&p)); break; }
case 1: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_GENERIC; soundError(system->setReverbProperties(&p)); break; }
case 2: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_PADDEDCELL; soundError(system->setReverbProperties(&p)); break; }
case 3: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_PADDEDCELL; soundError(system->setReverbProperties(&p)); break; }
case 4: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_BATHROOM; soundError(system->setReverbProperties(&p)); break; }
case 5: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_LIVINGROOM; soundError(system->setReverbProperties(&p)); break; }
case 6: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_STONEROOM; soundError(system->setReverbProperties(&p)); break; }
case 7: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_AUDITORIUM; soundError(system->setReverbProperties(&p)); break; }
case 8: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_CONCERTHALL; soundError(system->setReverbProperties(&p)); break; }
case 9: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_CAVE; soundError(system->setReverbProperties(&p)); break; }
case 10: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_ARENA; soundError(system->setReverbProperties(&p)); break; }
case 11: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_HANGAR; soundError(system->setReverbProperties(&p)); break; }
case 12: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_CARPETTEDHALLWAY; soundError(system->setReverbProperties(&p)); break; }
case 13: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_HALLWAY; soundError(system->setReverbProperties(&p)); break; }
case 14: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_STONECORRIDOR; soundError(system->setReverbProperties(&p)); break; }
case 15: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_ALLEY; soundError(system->setReverbProperties(&p)); break; }
case 16: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_FOREST; soundError(system->setReverbProperties(&p)); break; }
case 17: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_CITY; soundError(system->setReverbProperties(&p)); break; }
case 18: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_MOUNTAINS; soundError(system->setReverbProperties(&p)); break; }
case 19: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_QUARRY; soundError(system->setReverbProperties(&p)); break; }
case 20: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_PLAIN; soundError(system->setReverbProperties(&p)); break; }
case 21: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_PARKINGLOT; soundError(system->setReverbProperties(&p)); break; }
case 22: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_SEWERPIPE; soundError(system->setReverbProperties(&p)); break; }
case 23: { FMOD_REVERB_PROPERTIES p = FMOD_PRESET_UNDERWATER; soundError(system->setReverbProperties(&p)); break; }
}
}
