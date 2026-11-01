// from server: 52% by atomic.potato
struct S_0061ab40 {
    char pad_0[0x14];
    void* f_14;
    char pad_18[0x18];
    void* f_30;
    void* f_38;
    void* f_40;
    void init(void* a, void* b, void* c);
};

extern "C" void* __cdecl sub_0062d140();
extern "C" void* __cdecl sub_005ba2d0();
extern "C" void* __cdecl sub_005ba1f0();
extern "C" void* __cdecl sub_005ba5e0();
extern "C" void* __cdecl sub_00592b40(void* a, void* b, void* c);
extern "C" void __cdecl sub_0062d1d0(void* a, void* b);

extern unsigned int dword_00cca3e4;
extern unsigned int dword_00cca748;
extern unsigned int dword_00cca804;
extern unsigned int dword_00cca450;

void S_0061ab40::init(void* a, void* b, void* c) {
    dword_00cca3e4 += 1;
    f_14 = sub_0062d140();
    dword_00cca748 += 1;
    void* v1 = sub_005ba2d0();
    void* t1 = sub_00592b40(v1, &f_30, 0);
    sub_0062d1d0(f_14, t1);
    dword_00cca804 += 1;
    void* v2 = sub_005ba1f0();
    void* t2 = sub_00592b40(v2, &f_38, 0);
    sub_0062d1d0(f_14, t2);
    dword_00cca450 += 1;
    void* v3 = sub_005ba5e0();
    void* t3 = sub_00592b40(v3, &f_40, 0);
    sub_0062d1d0(f_14, t3);
}
