// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_sound_cache_map_native_boundary_8de67e25f930852a.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#include "util/Sound.h"
template class std::map<RBX::Soundscape::SoundId, boost::shared_ptr<RBX::Soundscape::Sound> >;
