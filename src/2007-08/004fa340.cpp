// from server: 52% by colin
struct G3D_LightingParameters {
    char pad[0x48];
};

struct G3D_Color3 {
    float r, g, b;
};

struct Lighting {
    char pad0[0x48];
    G3D_LightingParameters skyParameters;
    bool hasSky;
    char pad1[3];
    G3D_Color3 clearColor;
    float clearAlpha;
    G3D_Color3 shadowColor;
    G3D_Color3 fogColor;
    float fogStart;
    float fogEnd;
    char pad2[0x2e8 - 0x98];
    bool globalShadows;
    char pad3[3];
    float globalBrightness;
    G3D_Color3 topColorShift;
    G3D_Color3 bottomColorShift;
    char pad4[0x3f8 - 0x300];
    char timeOfDay[0x100];
    char pad5[0x100];

    Lighting();
};

extern float g_float_79646c;
extern float g_float_797e9c;
extern double g_double_8bd100;
extern int g_int_8bd108;
extern double* g_ptr_77e564;

extern "C" void __stdcall sub_486460();
extern "C" void __stdcall sub_4f74c0();
extern "C" void __stdcall sub_736070();
extern "C" void __stdcall sub_4f8fa0();
extern "C" void __stdcall sub_474f70();
extern "C" void __stdcall sub_457dd0();
extern "C" int __stdcall InterlockedDecrement(int*);

Lighting::Lighting()
{
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 8) = 0;
    *(int*)((char*)this + 0) = 0;
    *(int*)((char*)this + 0x10) = 0;
    *(int*)((char*)this + 0x14) = 0;
    *(int*)((char*)this + 0xc) = 0;
    *(int*)((char*)this + 0x1c) = 0;
    *(int*)((char*)this + 0x20) = 0;
    *(int*)((char*)this + 0x18) = 0;
    *(int*)((char*)this + 0x28) = 0;
    *(int*)((char*)this + 0x2c) = 0;
    *(int*)((char*)this + 0x24) = 0;
    *(int*)((char*)this + 0x34) = 0;
    *(int*)((char*)this + 0x38) = 0;
    *(int*)((char*)this + 0x30) = 0;
    *(int*)((char*)this + 0x40) = 0;
    *(int*)((char*)this + 0x44) = 0;
    *(int*)((char*)this + 0x3c) = 0;
    sub_486460();
    *(int*)((char*)this + 0x68) = 0;
    *(int*)((char*)this + 0x80) = 0;
    *(int*)((char*)this + 0x84) = 0;
    *(float*)((char*)this + 0x88) = g_float_79646c;
    *(char*)((char*)this + 0x90) = 0;
    *(float*)((char*)this + 0x8c) = g_float_79646c;
    if (!(g_int_8bd108 & 1)) {
        g_int_8bd108 |= 1;
        g_double_8bd100 = *g_ptr_77e564;
    }
    *(float*)((char*)this + 0x94) = (float)g_double_8bd100;
    *(int*)((char*)this + 0x9c) = 0;
    *(int*)((char*)this + 0xa0) = 0;
    *(int*)((char*)this + 0x98) = 0;
    *(int*)((char*)this + 0xa8) = 0;
    *(int*)((char*)this + 0xac) = 0;
    *(int*)((char*)this + 0xa4) = 0;
    sub_4f74c0();
    *(char*)((char*)this + 0x2e8) = 0;
    *(int*)((char*)this + 0x2ec) = 0;
    *(float*)((char*)this + 0x2f0) = g_float_797e9c;
    *(float*)((char*)this + 0x2f4) = g_float_797e9c;
    *(float*)((char*)this + 0x2f8) = 1.0f;
    *(float*)((char*)this + 0x2fc) = 1.0f;
    sub_736070();
    sub_736070();
    sub_4f8fa0();
    *(int*)((char*)this + 0x84) = *(int*)((char*)this + 0x84);
    sub_474f70();
    sub_474f70();
    if (*(int*)((char*)this + 0x14) != 0) {
        if (InterlockedDecrement((int*)(*(int*)((char*)this + 0x14) + 4)) == 0) {
            sub_457dd0();
            if (*(int*)((char*)this + 0x14) != 0) {
                (*(void(__thiscall**)(int, int))**(int**)(*(int*)((char*)this + 0x14)))(*(int*)((char*)this + 0x14), 1);
            }
        }
    }
}
