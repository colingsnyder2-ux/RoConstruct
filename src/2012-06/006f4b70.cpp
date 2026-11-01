// from server: 40% by Intel
struct VPVInstance {
    void* vftable;
    char pad4[0x80];
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;

    void* FilteredSelection();
};

extern "C" void __stdcall sub_6861B0(VPVInstance* thisptr);
extern "C" void __stdcall sub_684840(VPVInstance* thisptr, void* arg);
extern "C" void __stdcall MSVCP90_basic_string_ctor(void* thisptr, const char* str);
extern "C" void __stdcall MSVCP90_basic_string_dtor(void* thisptr);

void* VPVInstance::FilteredSelection() {
    sub_6861B0(this);
    field_84 = 1;
    vftable = (void*)0xB9C4A4;
    *(int*)((char*)this + 4) = 0xB9C49C;
    *(int*)((char*)this + 0x18) = 0xB9C490;
    *(int*)((char*)this + 0x1C) = 0xB9C484;
    *(int*)((char*)this + 0x80) = 0xB9C47C;
    field_88 = 0;
    field_8C = 0;
    field_94 = 0;
    field_98 = 0;
    field_9C = 0;

    char str_buf[0x1C];
    MSVCP90_basic_string_ctor(str_buf, "FilteredSelection");
    sub_684840(this, str_buf);
    MSVCP90_basic_string_dtor(str_buf);

    return this;
}
