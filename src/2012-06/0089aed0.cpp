// from server: 50% by Intel
struct MotorFeature {
    MotorFeature();
};

extern "C" void __stdcall __security_cookie_init(int);
extern "C" void __cdecl sub_89abe0(void*);

struct MotorFeatureVtbl {
    void* vfptr0;
    void* vfptr1;
    void* vfptr2;
    void* vfptr3;
    void* vfptr4;
    void* vfptr5;
    void* vfptr6;
    void* vfptr7;
    void* vfptr8;
    void* vfptr9;
    void* vfptr10;
    void* vfptr11;
    void* vfptr12;
    void* vfptr13;
    void* vfptr14;
    void* vfptr15;
    void* vfptr16;
    void* vfptr17;
    void* vfptr18;
    void* vfptr19;
    void* vfptr20;
    void* vfptr21;
    void* vfptr22;
    void* vfptr23;
    void* vfptr24;
    void* vfptr25;
    void* vfptr26;
    void* vfptr27;
    void* vfptr28;
    void* vfptr29;
    void* vfptr30;
    void* vfptr31;
};

MotorFeatureVtbl* const g_vtbl1 = (MotorFeatureVtbl*)0x00BDBE74;
MotorFeatureVtbl* const g_vtbl2 = (MotorFeatureVtbl*)0x00BDBE6C;
MotorFeatureVtbl* const g_vtbl3 = (MotorFeatureVtbl*)0x00BDBE60;
MotorFeatureVtbl* const g_vtbl4 = (MotorFeatureVtbl*)0x00BDBE54;
MotorFeatureVtbl* const g_vtbl5 = (MotorFeatureVtbl*)0x00BDBE28;

int g_counter = 0;

int __cdecl sub_780a30();

MotorFeature::MotorFeature() {
    __security_cookie_init(-1);
    sub_89abe0(this);
    *(MotorFeatureVtbl**)this = g_vtbl1;
    *(MotorFeatureVtbl**)((char*)this + 4) = g_vtbl2;
    *(MotorFeatureVtbl**)((char*)this + 0x18) = g_vtbl3;
    *(MotorFeatureVtbl**)((char*)this + 0x1C) = g_vtbl4;
    *(MotorFeatureVtbl**)((char*)this + 0x80) = g_vtbl5;
    int result = sub_780a30();
    *(int*)((char*)this + 0x28) = result;
    ++g_counter;
}
