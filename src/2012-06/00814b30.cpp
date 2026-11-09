// from server: 40% by Intel
struct VWeldFactoryProduct {
    VWeldFactoryProduct(void* a1);
};

extern "C" void __stdcall sub_8141e0(void* thisptr, void* a1);
extern "C" int __stdcall sub_972290(const char* str, int flag);
extern "C" int __stdcall sub_E5809C(int code, const char* fmt, const char* file);

VWeldFactoryProduct::VWeldFactoryProduct(void* a1) {
    sub_8141e0(this, a1);
    *(int*)this = 0x00BC7224;
    *(int*)((char*)this + 4) = 0x00BC7218;
    *(int*)((char*)this + 0x18) = 0x00BC720C;
    *(int*)((char*)this + 0x1C) = 0x00BC7200;
    *(int*)((char*)this + 0x80) = 0x00BC71D4;

    if (*(char*)0x00E580B3) {
        int vtable = *(int*)a1;
        int (__stdcall* getJointType)(void*) = *(int (__stdcall**)(void*))(vtable + 0x18);
        int jointType = getJointType(a1);
        if (jointType == 9) {
            int logger = *(int*)0x00E5809C;
            if (logger) {
                if (sub_E5809C(0x221, (const char*)0x00BC6258, (const char*)0x00BC71A4)) {
                    return;
                }
            }
            int flag = *(unsigned char*)0x00E580B3;
            sub_972290((const char*)0x00BC7110, flag);
        }
    }
}
