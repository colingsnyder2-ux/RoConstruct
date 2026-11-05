// from server: 54% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" void __stdcall G1_func_00b7a224();
extern "C" bool __stdcall G1_func_00515860(int, int, int, int);

struct RbxParticleEmitter
{
    void* vfptr0;
    char pad0[4];
    char flag5;
    char pad1[2];
    int field8;
    int fieldC;
    int field10;
    char pad2[4];
    int field18;
    char pad3[0x1c];
    int field38;
    int field3C;
    int field40;
    int field44;
    void* construct(int a, int b, int c, int d, int e);
};

void* RbxParticleEmitter::construct(int a, int b, int c, int d, int e)
{
    G1_func_00b7a224();
    vfptr0 = (void*)0x9a2cc4;
    flag5 = 1;
    field8 = 0;
    fieldC = *(int*)0x9efd3c;
    field10 = e;
    vfptr0 = (void*)0x9a30c0;
    bool r = G1_func_00515860(a, b, c, d);
    field18 = r ? 0xb10858 : 0;
    field38 = 0;
    field3C = 0;
    field40 = 0;
    field44 = 0;

    return this;
}
