// >>> native-status (generated) -- do not edit >>>
// SoundStringConverter | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 018e53b5 | roc native-status --write
#include "util/Sound.h"
#include "util/Utilities.h"
namespace RBX {
template<> bool StringConverter<Soundscape::SoundId>::convertToValue(const std::string& text, Soundscape::SoundId& value) { value = Soundscape::SoundId(text); return true; }
}
