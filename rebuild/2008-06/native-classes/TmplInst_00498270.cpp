// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// std::list<RBX::Network::AbuseReport::Message> members emitted by the RBX::Network::Players unit (00496eb0..00498270):
//   00496eb0 ?_Buynode@...@IAEPAU_Node@...@XZ        (26 B, head node: new(0x44))
//   00496f50 ?_Incsize@...@IAEXI@Z                    (154 B, length_error when size > max_size 0x4444444)
//   004977c0 ?_Buynode@...@PAU342@0ABUMessage@...@Z  (144 B, new(0x44) + Message copy ctor 00496110)
//   00498270 ?clear@...@QAEXXZ                       (131 B, destroys the strings at node+8+0x20 and node+8+4)
// Identity: registry decorated names (identity-closure). Layout from the binary: node 0x44 = 8 + sizeof(Message),
// so sizeof(Message) = 0x3c (max_size 0xffffffff / 0x3c = 0x4444444): int +0x00, std::string +0x04, std::string
// +0x20 (clear destroys +0x20 then +0x04). writeMessage 00497620 writes the +0x20 string as attribute "guid".
// BLOCKED: Network/Players.h declares AbuseReport::Message as { int userID; std::string text; } (0x20 bytes).
// Measured with a scratch Players.h that adds `std::string guid; // +0x20` after text: all four bodies EXACT, plus
// Message copy ctor 00496110, ~Message 00495ee0, ehhandlers 007c6a9c / 007c6cf0 / 007c6d01 / 007de842 / 007ce811.
// Enable (drop the guard) once the Players.h owner lands that field.
#ifdef NATIVE_ABUSEREPORT_MESSAGE_GUID_DECLARED
#include "Network/Players.h"

template std::_List_nod<RBX::Network::AbuseReport::Message, std::allocator<RBX::Network::AbuseReport::Message> >::_Node *
	std::list<RBX::Network::AbuseReport::Message, std::allocator<RBX::Network::AbuseReport::Message> >::_Buynode(); // 00496eb0
template void std::list<RBX::Network::AbuseReport::Message, std::allocator<RBX::Network::AbuseReport::Message> >::_Incsize(std::list<RBX::Network::AbuseReport::Message, std::allocator<RBX::Network::AbuseReport::Message> >::size_type); // 00496f50
template std::_List_nod<RBX::Network::AbuseReport::Message, std::allocator<RBX::Network::AbuseReport::Message> >::_Node *
	std::list<RBX::Network::AbuseReport::Message, std::allocator<RBX::Network::AbuseReport::Message> >::_Buynode(
		std::_List_nod<RBX::Network::AbuseReport::Message, std::allocator<RBX::Network::AbuseReport::Message> >::_Node *,
		std::_List_nod<RBX::Network::AbuseReport::Message, std::allocator<RBX::Network::AbuseReport::Message> >::_Node *,
		const RBX::Network::AbuseReport::Message &); // 004977c0
template void std::list<RBX::Network::AbuseReport::Message, std::allocator<RBX::Network::AbuseReport::Message> >::clear(); // 00498270
#endif
