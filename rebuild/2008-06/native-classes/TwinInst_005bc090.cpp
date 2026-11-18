// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 005bc090: explicit instantiation of the class the body at 005bc090 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "util/Sound.h"
template class RBX::Reflection::BoundFuncDesc<class RBX::Soundscape::SoundChannel,void __cdecl(void),0>;
