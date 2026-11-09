// from server: 100% by colin
struct RakPeerInterface {
    char pad[0x1c];
};

extern "C" void* (__cdecl* mallocPtr)(unsigned int);

RakPeerInterface* __cdecl createRakPeer(RakPeerInterface* peer) {
    RakPeerInterface* result = (RakPeerInterface*)mallocPtr((unsigned int)(peer->pad + 0x1c));
    *(RakPeerInterface**)(result->pad + 0xc) = peer;
    *(RakPeerInterface**)(result->pad + 0x14) = (RakPeerInterface*)(result->pad + 0x1c);
    result->pad[0x18] = 0;
    return result;
}
