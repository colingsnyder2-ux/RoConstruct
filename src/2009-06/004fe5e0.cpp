// from server: 100% by tester
struct RakPeer {
    char pad0[0xc];
    char field_c;
    char pad_d[0x54c - 0xd];
    char field_23c;
    void sub_671390();
    void sub_49f950();
    void sub_49fe90(void*, unsigned int);
    void sub_4ca1d0();
    void func(void* a, unsigned int b);
};

void RakPeer::func(void* a, unsigned int b)
{
    char* p = (char*)this + 0x54c;
    ((RakPeer*)p)->sub_671390();
    char* q = (char*)this + 0xc;
    ((RakPeer*)q)->sub_49f950();
    if (a != 0 && b > 0)
        ((RakPeer*)q)->sub_49fe90(a, b);
    ((RakPeer*)p)->sub_4ca1d0();
}
