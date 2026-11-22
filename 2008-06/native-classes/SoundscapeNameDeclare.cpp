// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native Name::doDeclare / callDoDeclare instances for the Soundscape class names (inactive). Flags copied from
// Rocket.cpp (the same explicit callDoDeclare instantiation pattern). Identity (registry, the only copies in the image):
//   00437f20 ??$doDeclare@$1?sSoundService@Soundscape@RBX@@3PADA@Name@RBX@@CAABV01@XZ   (guard 0096d1a8, n 0096d1a4)
//   00437f90 ??$doDeclare@$1?sSoundChannel@Soundscape@RBX@@3PADA@Name@RBX@@CAABV01@XZ   (guard 0096d1b0, n 0096d1ac)
//   00438830 ??$callDoDeclare@$1?sSoundService@...  5 B `jmp 00437f20`
//   00438840 ??$callDoDeclare@$1?sSoundChannel@...  5 B `jmp 00437f90`
// Their rows sit in the CPropGrid / XItem range (the SoundId property grid item emitted them); the util/Sound.cpp unit
// (AppUnit5B4SoundReflection.cpp) cannot compile here (fmod.hpp missing). The names are char arrays (3PADA) at
// 0094d2f4 / 0094d310, declared here as util/Sound.h declares them without pulling in FMOD.
#include "util/Name.h"

namespace RBX
{
	namespace Soundscape
	{
		extern char sSoundService[];   // 0094d2f4
		extern char sSoundChannel[];   // 0094d310
	}
}

// 00438830 / 00437f20
template void RBX::Name::callDoDeclare<RBX::Soundscape::sSoundService>();
// 00438840 / 00437f90
template void RBX::Name::callDoDeclare<RBX::Soundscape::sSoundChannel>();
