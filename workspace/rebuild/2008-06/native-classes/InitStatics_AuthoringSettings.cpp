// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 AuthoringSettings reflection static: dynamic initializer 007ee950 ("ShowPreliminaryObjects", "Browsing",
// bool member +0x131, flags 5; constructor 0040ae60 by RTTI BoundProp<bool,1>::BoundPropGetSet<AuthoringSettings>).
#include "AuthoringSettings.h"
#include "reflection/reflection.h"
// INFERRED: object name (not in the binary).
static RBX::Reflection::BoundProp<bool, 1> prop_ShowPreliminaryObjects("ShowPreliminaryObjects", "Browsing", &AuthoringSettings::showPreliminaryObjects, RBX::Reflection::PropertyDescriptor::STANDARD);   // 0096cb90
