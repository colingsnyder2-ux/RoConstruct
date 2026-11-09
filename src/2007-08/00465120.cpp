// from server: 39% by colin
struct DxUserInput {
    char pad0[0x28];
    int d28;
    int d2c;
    char pad30[0x4];
    int d34;
    char pad38[0x14];
    int d4c;
    int d50;
    int d54;
    float d58;
    float d5c;
    float d60;
    float d64;
    char d68;
    char pad69[0x3];
    int d6c;
    float d70;
    float d74;
    char d78;
    char d79;
    char d7a;
    char pad7b[0x101];
    int d17c;
    int d180;
    int d184;
    int d188;
    int d18c;
    int d190;
    int d194;
    DxUserInput* construct(int* a, int b);
};

extern "C" void __cdecl sub_59C390();
extern "C" void __cdecl sub_4330B0();
extern "C" void* __cdecl sub_630A00();
extern "C" void __cdecl sub_49D670(int* a, int b);
extern "C" void __cdecl sub_463770();
extern "C" void* __cdecl sub_62FF50();
extern "C" void* __cdecl sub_62FF32(unsigned int a);
extern "C" void __cdecl sub_630B8C(void* a, int b, unsigned int c);
extern "C" void* __stdcall GetModuleHandleA(const char* a);
extern "C" void* __cdecl sub_72B670(void* a);
extern "C" void __cdecl sub_401000(void* a);
extern "C" void __cdecl sub_463630();
extern "C" void __cdecl sub_4636E0();
extern "C" void* __cdecl sub_450EC0();
extern "C" void __cdecl sub_423240(void* a, void* b);
extern "C" void __cdecl sub_463A00();

extern void* (__stdcall *g_CopyAcceleratorTableA)(void*, void*, int);

DxUserInput* DxUserInput::construct(int* a, int b)
{
    sub_59C390();
    d28 = 0x795b54;
    d2c = 0x795b60;
    d34 = 0;
    sub_4330B0();
    d50 = 0;
    d54 = 0;
    d58 = 0.0f;
    d5c = 0.0f;
    d60 = 0.0f;
    d64 = 0.0f;
    d68 = 0;
    d6c = 0;
    d70 = 0.0f;
    d74 = 0.0f;
    d78 = 0;
    d79 = 0;
    d7a = 0;
    d17c = 0;
    d180 = b;
    void* p = sub_630A00();
    if (p != 0)
        d184 = *(int*)((char*)p + 0x20);
    else
        d184 = 0;
    d188 = 0;
    d18c = 0;
    d190 = 0;
    sub_49D670(&d194, *a);
    sub_463770();
    void* q = sub_62FF50();
    d4c = (int)q;
    if (q != 0) {
        for (;;) {
            int* vt = *(int**)d4c;
            int (*fn)(int, int) = *(int (**)(int, int))((char*)vt + 0x170);
            int r = fn(0, 0);
            void* h = g_CopyAcceleratorTableA((void*)r, 0, 0);
            d54 = (int)h;
            if (h != 0) {
                unsigned int sz = (unsigned int)h * 6;
                int ovf = 0;
                if (sz / 6 != (unsigned int)h)
                    ovf = 1;
                unsigned int alloc = ovf ? 0xffffffff : sz;
                void* mem = sub_62FF32(alloc);
                d50 = (int)mem;
                int* vt2 = *(int**)d4c;
                int (*fn2)(int, int) = *(int (**)(int, int))((char*)vt2 + 0x170);
                int r2 = fn2(d54, (int)mem);
                g_CopyAcceleratorTableA((void*)r2, 0, 0);
                break;
            }
            void* n = sub_62FF50();
            d4c = (int)n;
            if (n != 0)
                break;
        }
    }
    sub_630B8C((char*)this + 0x7b, 0, 0x100);
    void* mod = GetModuleHandleA(0);
    void* res = sub_72B670(mod);
    if ((int)res < 0)
        sub_401000(res);
    sub_463630();
    sub_4636E0();
    if (*a != 0) {
        void* r = sub_450EC0();
        if (r != 0)
            sub_423240((char*)r + 0xe8, &d2c);
        if (*a != 0) {
            void* r2 = sub_450EC0();
            if (r2 != 0)
                sub_423240((char*)r2 + 0x118, &d28);
            sub_450EC0();
        }
    }
    sub_463A00();
    return this;
}
