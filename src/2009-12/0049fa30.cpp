// from server: 37% by atomic.potato
struct Inner {
    void* p0;
    char pad[8];
    int f0c;
    int f10;
    int f14;
    char pad2[0x0c];
    float f24;
    float f28;
    float f2c;
};

struct Outer {
    void* vtbl;
    char pad0[0x40];
    Inner inner;
    char pad1[0x0c];
    Inner inner2;
    char pad2[0x0c];
    unsigned char b8c;
    unsigned char b8d;
};

extern "C" void __cdecl sub_49b780();
extern "C" void* __cdecl sub_7f3860(int);
extern "C" void* __cdecl sub_5f49b0();
extern "C" void __fastcall sub_5f3900(void* ecx, void* src);

extern float g_b7cc20;
extern float g_b7cc24;
extern float g_b7cc28;
extern int g_b7cc2c;

void __fastcall sub_49fa30(Outer* self)
{
    sub_49b780();
    self->vtbl = (void*)0x9b3b4c;
    Inner* si = &self->inner;
    void* p = sub_7f3860(4);
    if (p != 0)
        *(void**)p = si;
    else
        p = 0;
    *(void**)si = p;
    si->f0c = 0;
    si->f10 = 0;
    si->f14 = 0;
    Inner* si2 = &self->inner2;
    void* q = sub_5f49b0();
    sub_5f3900(si2, q);
    if ((g_b7cc2c & 1) == 0) {
        g_b7cc2c |= 1;
        g_b7cc20 = 0.0f;
        g_b7cc24 = 0.0f;
        g_b7cc28 = 0.0f;
    }
    si2->f24 = g_b7cc20;
    si2->f28 = g_b7cc24;
    si2->f2c = g_b7cc28;
    self->b8c = 0;
    self->b8d = 0;
}
