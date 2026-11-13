#pragma once
#include "util/Sound.h"
#include <fmod.hpp>

namespace RBX { namespace Soundscape {
bool nativeReverbPreset(ReverbType type,FMOD_REVERB_PROPERTIES& result);
} }
