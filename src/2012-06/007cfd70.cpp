// from server: 12% by atomic.potato
struct SpawnerService {
    char pad0[0x80];
    unsigned char flag80;
    char pad81[3];
    void* field84;
    int field88;

    void init();
};

extern "C" void* __cdecl sub_5b19f0();
extern "C" void __cdecl sub_7cfd00();
extern "C" void __cdecl sub_684840();

extern "C" void* __stdcall sub_b22648();
extern "C" void* __stdcall sub_b2263c();

struct Vtbl {
    void* pad0;
    void* pad4;
    void* pad8;
    void (__thiscall *fn0c)(void*, char*);
};

extern void* g_e2a5a0;

void SpawnerService::init() {
    sub_7cfd00();
    flag80 = 1;
    field84 = sub_5b19f0();
    field88 = 0;
    sub_b22648();
    sub_684840();
    sub_b2263c();
    Vtbl* v = *(Vtbl**)g_e2a5a0;
    char b = 0;
    v->fn0c(v, &b);
}
