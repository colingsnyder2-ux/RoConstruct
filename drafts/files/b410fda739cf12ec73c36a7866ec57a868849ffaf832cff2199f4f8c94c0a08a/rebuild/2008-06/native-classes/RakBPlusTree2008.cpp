// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /FImalloc.h /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// RakNet resend tree; inactive pending original identity and ABI proof.
#include "../native-headers/ReliabilityLayer.h"
template DataStructures::BPlusTree<MessageNumberType, InternalPacket*, RESEND_TREE_ORDER>::~BPlusTree();
template bool DataStructures::BPlusTree<MessageNumberType, InternalPacket*, RESEND_TREE_ORDER>::Delete(MessageNumberType, InternalPacket*&);
template bool DataStructures::BPlusTree<MessageNumberType, InternalPacket*, RESEND_TREE_ORDER>::Insert(MessageNumberType, InternalPacket* const&);
