// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_king_originala_hopper_legacy_92722dc306f04fcf.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Hopper.h"
#include "reflection/enumconverter.h"
#include <boost/thread/once.hpp>
namespace RBX {
// Existing native descriptor bootstrap boundaries, observed at5d0360/979cb4/5d0300.
extern boost::once_flag nativeBinEnumFlag;
extern void __cdecl nativeInitializeBinEnum();
extern const Reflection::EnumDesc<HopperBin::BinType>& __cdecl nativeBinEnumDescriptor();
void HopperBin::setLegacyCommand(const std::string&text) {
 const char*characters=text.c_str();
 boost::call_once(nativeInitializeBinEnum,nativeBinEnumFlag);
 const Reflection::EnumDesc<BinType>&descriptor=nativeBinEnumDescriptor();
 BinType newBinType;
 if(!descriptor.convertToValue(Name::lookup(characters),newBinType))newBinType=SCRIPT_BIN;
 setBinType(newBinType);
}
}
