// from server: 36% by colin
// roc 2012-06 005c8350  unit: RakNet::RakPeer  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c8350
//
// 005c8350  8b442414             mov eax, dword ptr [esp + 0x14]
// 005c8354  c21800               ret 0x18

struct RakPeer {
    int f();
};

int RakPeer::f() {
    int eax = *(int*)(this + 0x14);
    return eax;
}
