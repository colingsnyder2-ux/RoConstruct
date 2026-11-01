// from server: 100% by colin
struct RakPeer {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
};

extern "C" int __cdecl sub_4CA340();
extern "C" char __cdecl sub_4C0D50(RakPeer* peer, int value);

void RakPeer_Init(RakPeer* peer)
{
    int i;
    for (;;) {
        i = 0;
        do {
            *(int*)((char*)peer + i * 4) = sub_4CA340();
            i++;
        } while (i < 4);
        peer->fieldC |= 0x80000000;
        peer->field0 |= 1;
        if (sub_4C0D50(peer, 5))
            break;
    }
}
