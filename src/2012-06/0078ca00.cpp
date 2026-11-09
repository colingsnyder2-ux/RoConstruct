// from server: 13% by Intel
struct std_string {
    char _pad[28];
};

extern "C" void __stdcall __security_cookie_init(int);
extern "C" void __stdcall std_string_ctor(std_string* this_, const std_string& src);
extern "C" void __stdcall std_string_dtor(std_string* this_);

struct VRunService_EventDesc {
    char _pad[0x84];
    std_string field_84;
    char _pad2[0x14];
    int field_98;
    char field_a0;

    void __thiscall func_78ca00(VRunService_EventDesc* this_, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
};

void __thiscall VRunService_EventDesc::func_78ca00(VRunService_EventDesc* this_, int a2, int a3, int a4, int a5, int a6, int a7, int a8) {
    __security_cookie_init(0);
    std_string_ctor(&this_->field_84, *reinterpret_cast<const std_string*>(&a2));
    if (this_->field_98 == 0) {
        this_->field_a0 = 1;
    }
    std_string_dtor(&this_->field_84);
}
