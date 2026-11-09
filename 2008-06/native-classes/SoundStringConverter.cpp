#include "util/Sound.h"
#include "util/Utilities.h"
namespace RBX {
template<> bool StringConverter<Soundscape::SoundId>::convertToValue(const std::string& text, Soundscape::SoundId& value) { value = Soundscape::SoundId(text); return true; }
}
