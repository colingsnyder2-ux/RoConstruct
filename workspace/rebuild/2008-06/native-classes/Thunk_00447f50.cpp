// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../native-classes
// 00447f50: EnumDesc<CRenderSettings::AntialiasingMode>::callDoSingleton, a 5-byte jump to 00447ef0. The constructor called by the target installs the RTTI vftable of RBX::Reflection::EnumDesc<CRenderSettings::AntialiasingMode> (thunk_lane.py, no model)
#include "CRenderSettings.h"
#include "reflection/enumconverter.h"
template class RBX::Reflection::EnumDesc<CRenderSettings::AntialiasingMode>;
