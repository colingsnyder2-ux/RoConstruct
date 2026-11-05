// from server: 42% by colin
// roc 2007-08 004ed5d0  unit: CylinderBuilder  size: 799 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ed5d0

extern "C" double __stdcall ceil(double);
extern "C" double __cdecl fabs(double);

struct CylinderBuilder {
    char pad0[0x10];
    int field10;
    void buildTop(int, float, float, float, int, int);
};

extern "C" void __stdcall sub_5b9970(void*, void*);
extern "C" void __stdcall sub_50b010(void*, void*);
extern "C" float __stdcall sub_4de980(int);
extern "C" void __stdcall sub_4e0180(void*, void*, void*, void*, int, int);
extern "C" void __stdcall sub_4ec270(void*, int, int);

extern float g_787050;
extern float g_797e9c;
extern double g_795b48;
extern double g_79f340;
extern double g_79f348;

void CylinderBuilder::buildTop(int a1, float a2, float a3, float a4, int a5, int a6)
{
    int ebx = this->field10 & 7;
    float v10;
    float v18;
    float v1c;
    float v20;
    float v24;
    float v28;
    float v2c;
    float v30;
    float v44;
    float v48;
    float v4c;
    float v5c;
    int ebp;
    int esi;
    int edi;
    int eax;
    int local10;
    int local12;
    int local14;
    int local1c;
    int local20;
    int local24;
    int local28;
    int local2c;
    int local30;
    int local34;
    int local38;
    int local3c;
    int local40;
    int local44;
    int local48;
    int local4c;
    int local50;
    int local54;
    int local58;
    int local5c;
    int local5e;
    int local60;
    int local64;

    sub_5b9970(&this->field10 + 1, &local3c);

    v18 = (float)fabs(a4);
    ebp = a6;
    edi = 0;
    v1c = v18;
    v10 = (float)fabs(local3c);
    v18 = v10;
    v10 = (float)fabs(local38);
    v44 = v10;
    v48 = v18;
    v4c = v1c;

    if (ebp == edi) {
        if (v44 == v1c) {
            esi = 1;
        } else {
            esi = 0;
        }
    } else {
        esi = 0;
    }

    if (ebp == edi && ebx != edi) {
        v24 = (float)((double)v44 * g_795b48);
        v24 = (float)ceil((double)v24);
        v1c = v24;
        ebp = (int)v1c;
    } else {
        ebp = 1;
    }

    local10 = 0;
    local12 = 0;
    edi = *(unsigned short*)((char*)&local5e - esi * 2);
    eax = (int)(short)edi;
    eax = eax / ebp;
    local1c = 1;
    local5c = (unsigned short)eax;
    if ((short)eax > 1) {
        eax = (int)&local5c;
    } else {
        eax = (int)&local1c;
    }
    *(unsigned short*)((char*)&local10 + esi * 2) = *(unsigned short*)eax;
    v18 = v4c;
    *(unsigned short*)((char*)&local12 - esi * 2) = (unsigned short)edi;

    sub_50b010(&local38, &local48);
    v5c = -*(float*)&local38;
    sub_50b010(&local30, &local48);
    v20 = -*(float*)&local34;
    *(float*)&local3c = *(float*)&local60;
    *(float*)&local40 = v20;

    if (local60 == 0) {
        if (ebx == 0) {
            *(float*)&local28 = g_787050;
            *(float*)&local2c = g_797e9c;
            *(float*)((char*)&local20 - esi * 4) = *(float*)&local28;
            *(float*)((char*)&local1c + esi * 4) = *(float*)&local2c;
        } else {
            *(float*)((char*)&local2c - esi * 4) = 0.0f;
            *(float*)&local2c = sub_4de980(ebx);
            *(float*)((char*)&local2c + esi * 4) = *(float*)&local2c;
            v5c = *(float*)((char*)&local4c - esi * 4);
            v5c = v5c + v5c;
            *(float*)((char*)&local24 - esi * 4) = v5c;
            *(float*)((char*)&local1c + esi * 4) = g_797e9c;
            if (esi == 1) {
                v1c = -v1c;
            }
        }
    } else if (local60 == 1) {
        *(float*)&local28 = 0.0f;
        *(float*)&local2c = *(float*)((char*)&local14 + 0x1c);
        v1c = *(float*)((char*)&local14 + 0x18);
        v20 = -*(float*)((char*)&local14 + 0x1c);
    } else if (local60 == 2) {
        *(float*)&local28 = 0.0f;
        *(float*)&local2c = 0.0f;
        v1c = 0.0f;
        v20 = 0.0f;
    } else {
        *(float*)&local28 = 0.0f;
        *(float*)&local2c = 0.0f;
        v1c = 0.0f;
        v20 = 0.0f;
    }

    edi = 0;
    while (edi < ebp) {
        if (edi == ebp - 1) {
            v5c = *(float*)((char*)&local44 + esi * 4);
            *(float*)((char*)&local30 + esi * 4) = v5c;
            if (local60 != 0) {
            } else if (local24 != 0) {
                v5c = v5c - *(float*)((char*)&local38 + esi * 4);
                v5c = v5c * (float)g_79f348;
                v5c = v5c * *(float*)((char*)&local1c + esi * 4);
                *(float*)((char*)&local1c + esi * 4) = v5c;
            }
        } else {
            v30 = *(float*)((char*)&local38 + esi * 4);
            v30 = v30 + (float)g_79f340;
            *(float*)((char*)&local30 + esi * 4) = v30;
        }

        sub_4e0180(&local64, &local48, &local30, &local1c, esi, local10);
        sub_4ec270((void*)local48, local10, ebx);
        *(float*)((char*)&local38 + esi * 4) = *(float*)((char*)&local30 + esi * 4);
        edi++;
    }
}
