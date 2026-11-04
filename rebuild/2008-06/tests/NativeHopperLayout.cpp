#include "v8datamodel/Hopper.h"
// 0048ec70 allocates 0x168 for LegacyHopperService (ctor 005d10a0, vtable RTTI .?AVLegacyHopperService@RBX@@),
// whose ctor stores no own members; Hopper's last fields end at +0x168.
// RelativePanel ctor 005cf770 initializes shorts +164/+166; Hopper
// ctor 005cf900 stores yLocation at +160. Service is an empty base.
typedef char HopperSize[(sizeof(RBX::Hopper)==0x168)?1:-1];
typedef char LegacyHopperSize[(sizeof(RBX::LegacyHopperService)==0x168)?1:-1];
