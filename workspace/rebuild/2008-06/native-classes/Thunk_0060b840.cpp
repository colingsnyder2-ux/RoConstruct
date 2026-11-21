// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../native-classes
// 0060b840: EnumDesc<RBX::Feature::LeftRight>::callDoSingleton, a 5-byte jump to 0060b7e0. The constructor called by the target installs the RTTI vftable of RBX::Reflection::EnumDesc<RBX::Feature::LeftRight> (thunk_lane.py, no model)
#include "v8datamodel/Feature.h"
#include "reflection/enumconverter.h"
template class RBX::Reflection::EnumDesc<RBX::Feature::LeftRight>;
