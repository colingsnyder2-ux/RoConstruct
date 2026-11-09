// from server: 56% by colin
struct VCamera {
    char pad0[0xe8];
    char field_e8[0x44];
    char pad12c[0x60];
    int field_18c;
    int field_190;
    int field_194;
    void sub_59a0e0();
    void* sub_59a6d0(void*);
    void* sub_599480();
};

void __stdcall sub_5095d0(void*);
void __stdcall sub_506ae0(void*, void*);
void __stdcall sub_506b10(void*, void*);
void __stdcall sub_51da70(void*, void*, void*, void*);
int __stdcall sub_5aab30(void*);
int __stdcall sub_5ab3f0(void*, void*, float, float);

extern float g_7a4cc4;
extern float g_7aa8b4;
extern float g_7a837c;

void VCamera::sub_59a0e0() {
    char buf[0xc4];
    int flag = 0;
    sub_59a0e0();
    void* edi;
    if (field_194 != 0) {
        int v = field_18c;
        if (v == 4 || v == 1 || v == 3) {
            edi = sub_59a6d0(buf + 0x94);
        } else {
            edi = pad0 + 0x12c;
        }
    } else {
        edi = pad0 + 0x12c;
    }
    sub_5095d0(buf + 4);
    float f24 = *(float*)((char*)edi + 0x24);
    float f28 = *(float*)((char*)edi + 0x28);
    float f2c = *(float*)((char*)edi + 0x2c);
    float scale;
    if (field_194 != 0) {
        int v = field_18c;
        if (v == 4 || v == 1 || v == 3) {
            scale = g_7a4cc4;
        } else {
            scale = g_7aa8b4;
        }
    } else {
        scale = g_7aa8b4;
    }
    char* base = pad0 + 0xe8;
    sub_506ae0(base, buf + 0x68);
    sub_51da70(buf + 0x68, buf + 0x38, buf + 4, &scale);
    if (sub_5aab30(buf + 0x38)) {
        sub_506b10(base, buf + 0x38);
    }
    if (field_190 != 0) {
        float g = g_7a837c;
        if (sub_5ab3f0(buf + 0x40, buf + 0x70, g, g)) {
            return;
        }
    }
    void* p = sub_599480();
    if (p) {
        void** vtbl = *(void***)p;
        void (__fastcall *fn)(void*) = (void (__fastcall *)(void*))vtbl[3];
        fn(p);
    }
}
