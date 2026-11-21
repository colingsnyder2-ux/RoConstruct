// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// DescribedNonCreatable<DataModel, ServiceProvider, sDataModel>::DescribedNonCreatable() 0057abf0 (inactive), the
// inline reflection/reflection.h constructor that the DataModel unit (00574f10..0057c1af) emits for DataModel().
// Identity: the registry row of 0057abf0 carries the GlobalSettings name (??0?$DescribedNonCreatable@VGlobalSettings@..),
// but the constructor stores vtable 008302ac whose RTTI locator names
// .?AV?$DescribedNonCreatable@VDataModel@RBX@@VServiceProvider@2@$1?sDataModel@2@3QBDB@RBX@@; the real
// GlobalSettings instance is 00568ed0 (AppUnit568GlobalSettings.cpp). It calls the inline
// NonFactoryProduct<ServiceProvider, sDataModel>() 0057a7b0 (registry name also says sGlobalSettings) and
// Described<DataModel, ...>::classDescriptor() 005788c0 for the descriptor at +0x1c.
#include "v8datamodel/DataModel.h"

// 0057abf0
template RBX::DescribedNonCreatable<RBX::DataModel, RBX::ServiceProvider, RBX::sDataModel>::DescribedNonCreatable();
