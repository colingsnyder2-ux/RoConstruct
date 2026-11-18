// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../native-classes
// 005bbea0: EnumDesc<RBX::Soundscape::ReverbType>::callDoSingleton, a 5-byte jump to 005bbe40. The constructor called by the target installs the RTTI vftable of RBX::Reflection::EnumDesc<RBX::Soundscape::ReverbType> (thunk_lane.py, no model)
#include "util/Sound.h"
#include "reflection/enumconverter.h"
template class RBX::Reflection::EnumDesc<RBX::Soundscape::ReverbType>;
