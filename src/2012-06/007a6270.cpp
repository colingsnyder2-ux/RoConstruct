// from server: 30% by Intel
struct VPoseFactoryProduct {
    void* vftable;
    void* f_4;
    char pad_8[0x78];
    void* f_80;
    char pad_84[0x2C];
    float f_b0;
    float f_b4;
};

extern "C" void __stdcall sub_62D950(void* thisptr);
extern "C" void __stdcall sub_684840(void* thisptr, void* arg);
extern "C" void __stdcall sub_7A6030(void* thisptr);
extern "C" void __stdcall MSVCP90_basic_string_ctor(void* thisptr, const char* str);
extern "C" void __stdcall MSVCP90_basic_string_dtor(void* thisptr);

VPoseFactoryProduct* VPoseFactoryProduct_ctor(VPoseFactoryProduct* thisptr) {
    sub_7A6030(thisptr);
    sub_62D950(&thisptr->f_80);
    thisptr->f_b0 = *reinterpret_cast<float*>(0xB4C440);
    thisptr->f_b4 = 0.0f;

    char str_buf[28];
    MSVCP90_basic_string_ctor(str_buf, reinterpret_cast<const char*>(0xBB6260));

    thisptr->vftable = reinterpret_cast<void*>(0xBB63EC);
    thisptr->f_4 = reinterpret_cast<void*>(0xBB63E0);
    thisptr->f_80 = reinterpret_cast<void*>(0xBB63D4);
    *reinterpret_cast<void**>(reinterpret_cast<char*>(thisptr) + 0x1C) = reinterpret_cast<void*>(0xBB63C8);

    sub_684840(thisptr, str_buf);

    MSVCP90_basic_string_dtor(str_buf);
    return thisptr;
}
