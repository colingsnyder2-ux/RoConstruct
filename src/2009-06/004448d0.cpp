// from server: 49% by atomic.potato
struct VCRenderSettingsItem {
    char pad0[0xb6];
    short field_b6;
    char pad1[0x6];
    short field_be;
    char pad2[0x2];
    short field_c2;
    short field_c4;
    char pad3[0x26];
    short field_ec;
    short field_ee;
    char pad4[0x2];
    int field_f0;
    char pad5[0xc];
    int field_100;
    int EnumPropDescriptor(int);
};

extern "C" int __cdecl sub_43FDB0(int*, int);
extern "C" int __cdecl sub_441C60(int*, int);
extern "C" int __cdecl sub_440BE0(void*, void*);
extern "C" int __cdecl sub_444770(int*, void*, float);
extern "C" void __cdecl sub_718A32(void*);
extern "C" void __stdcall sub_89E9AC();

int VCRenderSettingsItem::EnumPropDescriptor(int arg) {
    int local_44;
    int local_28;
    int local_1c;
    int local_c;
    int local_40;
    int local_2c;
    int local_30;
    int local_34;
    int local_3c;
    int local_10;
    int local_48;
    int local_24;
    int local_20;

    if (arg != 0) {
        sub_43FDB0(&local_44, arg);
        *(int*)((char*)this + 0xec) = local_44;
        sub_441C60(&local_24, arg);
        local_40 = 0;
        sub_440BE0((char*)this + 0xf0, &local_24);
        if (local_28 != 0) {
            sub_718A32((void*)local_28);
        }
        local_3c = -1;
        if (local_1c != 0) {
            sub_718A32((void*)local_1c);
        }
        local_2c = 0;
        local_30 = 0;
        local_34 = 0;
    }

    int v100 = *(int*)((char*)this + 0x100);
    local_44 = v100;
    char* edi = (char*)this + 0xf0;
    if (*(int*)(edi + 0xc) > v100) {
        sub_89E9AC();
    }
    int v0 = *(int*)edi;
    local_10 = v0;
    int ebp = *(int*)(edi + 0x10);
    if (*(int*)(edi + 0xc) > ebp) {
        sub_89E9AC();
    }
    int ebx = *(int*)(edi + 0xc);
    if (ebx > *(int*)(edi + 0x10)) {
        sub_89E9AC();
    }
    int eax = *(int*)edi;
    local_1c = ebx;
    if (ebx != ebp) {
        int ecx = *(int*)((char*)this + 0xb6);
        while (*(int*)ebx != ecx) {
            ebx += 4;
            if (ebx == ebp) break;
        }
    }
    if (eax != 0 && eax != local_10) {
        sub_89E9AC();
    }
    if (ebx != local_44) {
        *(int*)((char*)this + 0xbe) = *(int*)((char*)this + 0xb6);
    } else {
        int a = *(short*)((char*)this + 0xec);
        int b = *(short*)((char*)this + 0xee);
        local_44 = a;
        local_48 = b;
        float f = (float)a / (float)b;
        sub_444770(&local_24, edi, f);
        *(int*)((char*)this + 0xbe) = local_24;
    }

    if (*(short*)((char*)this + 0xba) != 0 && *(short*)((char*)this + 0xbc) != 0) {
        *(int*)((char*)this + 0xc2) = *(int*)((char*)this + 0xba);
    } else {
        float f = *(float*)0x8b67f8;
        sub_444770(&local_24, edi, f);
        *(int*)((char*)this + 0xc2) = local_24;
    }

    int c2 = *(short*)((char*)this + 0xc2);
    int ec = *(short*)((char*)this + 0xec);
    local_c = c2;
    local_44 = ec;
    int* p1 = &local_44;
    if (ec < c2) p1 = &local_c;
    unsigned short di = *(unsigned short*)p1;

    int ee = *(short*)((char*)this + 0xee);
    int c4 = *(short*)((char*)this + 0xc4);
    local_44 = ee;
    local_c = c4;
    int* p2 = &local_44;
    if (ee < c4) p2 = &local_c;
    unsigned short cx = *(unsigned short*)p2;
    *(short*)((char*)this + 0xc2) = di;
    *(short*)((char*)this + 0xc4) = cx;

    int eax2 = ec;
    int edx2 = eax2 >> 31;
    eax2 = (eax2 - edx2) >> 1;
    int edx3 = (int)di;
    local_44 = eax2;
    local_c = edx3;
    int* p3 = &local_44;
    if (edx3 < eax2) p3 = &local_c;
    unsigned short dx = *(unsigned short*)p3;
    *(short*)((char*)this + 0xc2) = dx;

    int eax3 = ee;
    int edx4 = eax3 >> 31;
    eax3 = (eax3 - edx4) >> 1;
    int ecx2 = (int)cx;
    local_44 = eax3;
    local_c = ecx2;
    if (ecx2 >= eax3) {
        unsigned short cxx = *(unsigned short*)&local_c;
        *(short*)((char*)this + 0xc4) = cxx;
    } else {
        unsigned short axx = *(unsigned short*)&local_44;
        *(short*)((char*)this + 0xc4) = axx;
    }
    return 0;
}
