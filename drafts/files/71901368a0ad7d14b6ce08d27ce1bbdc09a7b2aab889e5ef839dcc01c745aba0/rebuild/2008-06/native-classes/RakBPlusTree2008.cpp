// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /FImalloc.h /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// RakNet resend tree; inactive pending original identity and ABI proof.
#include "../native-headers/ReliabilityLayer.h"
template class DataStructures::BPlusTree<MessageNumberType, InternalPacket*, RESEND_TREE_ORDER>;
