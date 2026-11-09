// from server: 83% by atomic.potato
// roc 2007-03 00527e10  unit: seg_00520000  size: 90 bytes
// library rbxgs-view View.cpp (function ??0?$Table@VVector3@G3D@@UVariations@?$MeshFactory@VCylinderAlongXMesh@View@RBX@@$00@View@RBX@@@G3D@@QAE@XZ)

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile *);
extern "C" void __stdcall sub_527a30(int, int);

struct S {
    char pad0[4];
    char pad4[1];
    char pad5[3];
    int field8;
    int fieldC;
    int field10;
    char pad14[4];
    int field18;
    char pad1C[0x1C];
    int field38;
    int field3C;
    int field40;
    int field44;
    S(int a, int b, int c);
};

S::S(int a, int b, int c)
{
    InterlockedIncrement((long volatile *)0xc007ac);
    *(int *)this = 0xa0399c;
    *(char *)((char *)this + 5) = 1;
    field8 = 0;
    fieldC = *(int *)0xa54060;
    field10 = c;
    *(int *)this = 0xa03a1c;
    field18 = 0;
    sub_527a30(a, b);
    field38 = 0;
    field3C = 0;
    field40 = 0;
    field44 = 0;
}
