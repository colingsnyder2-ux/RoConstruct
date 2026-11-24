// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 00447e70: EnumDesc<T>::callDoSingleton and its target doSingleton (00447e10); T is read from the RTTI vftable the constructor called by 00447e10 installs (thunk_lane.py, no model)
#include "CRenderSettings.h"
#include "reflection/enumconverter.h"
template class RBX::Reflection::EnumDesc<CRenderSettings::GraphicsMode>;
// The neighbouring callDoSingleton / doSingleton pairs of the same CRenderSettings EnumDesc run (batch 51). Each
// doSingleton calls the constructor that EnumDescCtors2008.cpp specializes; its name string identifies the enum:
//   00447e00 -> 00447da0 (ctor 00447060 "AASamples", vftable 00815ec8)
//   00447fc0 -> 00447f60 (ctor 00447680 "Bevels", vftable 00815ef8)
//   00448030 -> 00447fd0 (ctor 00447800 "Shadow", vftable 00815f04)
template class RBX::Reflection::EnumDesc<CRenderSettings::AASamples>;
template class RBX::Reflection::EnumDesc<CRenderSettings::BevelMode>;
template class RBX::Reflection::EnumDesc<CRenderSettings::ShadowMode>;
