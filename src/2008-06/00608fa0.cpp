// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_pvguidportableeae53016c7cf31da.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_espeon_nativeinstanceguidportablea1682bda32c99cd2.cpp")
#include "v8datamodel/PVInstance.h"
namespace RBX { void PVInstance::clearLegacyOffset() { legacyOffset.reset(); for(size_t i=0;i<numChildren();++i) { PVInstance* child=queryTypedChild<PVInstance>((int)i); if(child)child->clearLegacyOffset(); } } }
