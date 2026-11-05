// from server: 29% by colin
// roc 2007-08 004e9fa0  unit: TorsoMesh.cpp  size: 794 bytes
// library rbxgs-view/TorsoMesh.cpp

extern "C" __declspec(dllimport) double __stdcall ceil(double);
extern "C" __declspec(dllimport) float __cdecl fabsf(float);

struct TorsoBuilder {
    char pad[0x10];
    unsigned int flags;
    void build(int a, int b, int c);
};

extern "C" void __cdecl sub_5b99f0(void*, void*);
extern "C" void __cdecl sub_50b010(void*, void*);
extern "C" float __cdecl sub_4de980(int);
extern "C" void __cdecl sub_4e0180(void*, void*, void*, void*, int, int, int);
extern "C" void __cdecl sub_4e8c60(void*, int);

extern float g_795b48;
extern float g_787050;
extern float g_797e9c;
extern float g_79f340;
extern float g_79f348;

void TorsoBuilder::build(int a, int b, int c)
{
    float local38[2];
    float local30[2];
    float local28[2];
    float local20[2];
    float local1c[2];
    float local18;
    float local10;
    float local44[2];
    float local48;
    float local4c;
    float local58;
    short local12[2];
    short local10w[2];
    int local1c_i;
    int local58_i;
    int local54;
    int local5c;
    int local24;
    int local14;
    int ebp;
    int esi;
    int ebx;
    int edi;
    float f;

    ebx = (this->flags >> 12) & 7;

    sub_5b99f0((char*)this + 4, local38);

    local18 = fabsf(*(float*)((char*)&a + 0));
    local1c[0] = local18;

    ebp = c;
    edi = 0;

    local10 = fabsf(local38[0]);
    local18 = local10;
    local10 = fabsf(local38[1]);
    local44[0] = local10;

    local48 = local18;
    local4c = local1c[0];

    if (ebp == 0) {
        if (local44[0] == local18) {
            esi = 1;
        } else {
            esi = 0;
        }
    } else {
        esi = 0;
    }

    if (ebp == 0 && ebx != 0) {
        f = local44[esi] * g_795b48;
        f = (float)ceil((double)f);
        local1c[0] = f;
        ebp = (int)local1c[0];
    } else {
        ebp = 1;
    }

    local10w[0] = 0;
    local10w[1] = 0;

    {
        short* p = (short*)((char*)local12 - esi * 2);
        edi = *p;
        local58_i = (int)(short)edi / ebp;
        local1c_i = 1;
        if ((short)local58_i > 1) {
            local58 = (float)local58_i;
        } else {
            local58 = (float)local1c_i;
        }
        local10w[esi] = (short)local58;
        local18 = local4c;
        *(short*)((char*)local12 - esi * 2) = (short)edi;
    }

    sub_50b010(local38, local44);
    local58 = -local44[0];
    local20[0] = -local44[1];
    local30[0] = local58;
    local30[1] = local20[0];

    sub_50b010(local38, local28);

    local28[0] = 0.0f;
    local28[1] = 0.0f;
    local1c[0] = 0.0f;
    local20[0] = 0.0f;

    switch (local5c) {
    case 0:
        if (ebx == 0) {
            local28[0] = g_787050;
            local28[1] = g_797e9c;
            local1c[0] = local28[0];
        } else {
            local28[1] = 0.0f;
            local28[1] = sub_4de980(ebx);
            local20[0] = local30[0] * 2.0f;
            local1c[0] = g_797e9c;
            if (esi == 1) {
                local1c[0] = -local1c[0];
            }
        }
        break;
    case 1:
        local28[0] = 0.0f;
        local28[1] = *(float*)((char*)this + 0x1c);
        local1c[0] = *(float*)((char*)this + 0x18);
        local20[0] = -*(float*)((char*)this + 0x1c);
        break;
    case 2:
        break;
    default:
        break;
    }

    edi = 0;
    if (ebp > 0) {
        local54 = *(int*)((char*)&a + 4);
        do {
            if (edi == ebp - 1) {
                local58 = local44[esi];
                local30[esi] = local58;
                if (local5c == 0 && local24 != 0) {
                    local1c[esi] = (local58 - local30[esi]) * g_79f348 * local1c[esi];
                }
            } else {
                local30[esi] = local38[esi] + g_79f340;
            }

            {
                float tmp1 = local1c[0];
                float tmp2 = local20[0];
                float tmp3 = local30[0];
                float tmp4 = local30[1];
                sub_4e0180(local38, local44, &tmp1, &tmp2, local54, esi, *(int*)((char*)&a + 8));
            }
            sub_4e8c60((void*)local54, c);
            local38[esi] = local30[esi];
            edi++;
        } while (edi < ebp);
    }
}
