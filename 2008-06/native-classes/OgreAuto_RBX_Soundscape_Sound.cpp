// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../native-headers/util/Sound.h"

namespace RBX {
namespace Soundscape {
Sound::Sound(FMOD::System* system, RBX::Soundscape::SoundId id, bool is3D)
    : fmod_sound(0),
      system(system),
      refCount(0),
      id(id),
      is3D(is3D)
{
}
}
}
