#include "v8datamodel/Hopper.h"
// 0048ec70 allocates 0x168 for StarterPackService, which has no own members.
// RelativePanel ctor 005cf770 initializes shorts +164/+166; Hopper
// ctor 005cf900 stores yLocation at +160. Service is an empty base.
typedef char HopperSize[(sizeof(RBX::Hopper)==0x168)?1:-1];
typedef char StarterPackSize[(sizeof(RBX::StarterPackService)==0x168)?1:-1];
