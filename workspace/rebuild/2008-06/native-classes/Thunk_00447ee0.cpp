// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../native-classes
// 00447ee0: EnumDesc<CRenderSettings::FrameRateManagerMode>::callDoSingleton, a 5-byte jump to 00447e80. The constructor called by the target installs the RTTI vftable of RBX::Reflection::EnumDesc<CRenderSettings::FrameRateManagerMode> (thunk_lane.py, no model)
#include "CRenderSettings.h"
#include "reflection/enumconverter.h"
template class RBX::Reflection::EnumDesc<CRenderSettings::FrameRateManagerMode>;
