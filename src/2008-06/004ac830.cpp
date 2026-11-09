// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_unit_698bb9e97bcd0996.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("util/Profiling.h", "roc_unit_dc79b233469e3206.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("Network/Player.h", "roc_unit_1cb1f788b2f04b82.cpp")
#undef _RELEASEASSERT
#include <RakPeer.h>
#include "v8datamodel/Stats.h"
#include "Replicator.h"
namespace RBX { namespace Network {
Peer::~Peer(){rakPeer->DetachPlugin(this);}
} }
