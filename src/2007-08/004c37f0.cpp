// from server: 78% by colin
struct RakPeer {
    char pad0[4];
    char field4;
    char field5;
    char pad6[0x70a];
    int field710;
    void sub_4C2340();

    void sub_4C37F0(RakPeer* peer);
};

extern "C" void __cdecl sub_4CA670(int);

void RakPeer::sub_4C37F0(RakPeer* peer) {
    peer->field5 = 1;
    while (peer->field4 == 0) {
        peer->sub_4C2340();
        int v = peer->field710;
        if (v >= 0) {
            sub_4CA670(v);
        }
    }
    peer->field5 = 0;
}
