// from server: 100% by atomic.potato




extern "C" void __stdcall sub_52d8d0_impl();
extern "C" void __stdcall sub_4159a0_impl();

struct ProfiledRakPeer {
    char pad0[0xc];
    unsigned int field_c;
    char pad10[0x8];
    unsigned int field_18;
    char pad1c[0x28c];
    char field_2a8[8];

    void method(unsigned int* a, unsigned int* b);
};

void ProfiledRakPeer::method(unsigned int* a, unsigned int* b) {
    char* p = field_2a8;
    ((void (__thiscall*)(void*))sub_52d8d0_impl)(p);
    *a = field_18;
    *b = (field_c + 7) >> 3;
    ((void (__thiscall*)(void*))sub_4159a0_impl)(p);
}
