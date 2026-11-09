// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern void (*rakFree)(void*);
struct Packet { char pad[0x24]; unsigned char* data; bool deleteData; };
class RakPeer { public: void DeallocatePacket(Packet* packet); };
void RakPeer::DeallocatePacket(Packet* packet) { if (packet == 0) return; if (packet->deleteData) rakFree(packet->data); rakFree(packet); }
