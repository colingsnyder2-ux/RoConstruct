// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 00447e70: EnumDesc<T>::callDoSingleton and its target doSingleton (00447e10); T is read from the RTTI vftable the constructor called by 00447e10 installs (thunk_lane.py, no model)
#include "CRenderSettings.h"
#include "reflection/enumconverter.h"
template class RBX::Reflection::EnumDesc<CRenderSettings::GraphicsMode>;
