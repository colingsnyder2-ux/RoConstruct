// from server: 53% by colin
struct MouseCommand {
    char pad0[0xe8];
    void* vtbl_e8;
    int field_ec;
    int field_f0;
    char pad_f4[4];
    int field_f8;
    int field_fc;
    int field_100;
};

struct BoxSelectCommand : MouseCommand {
    BoxSelectCommand();
};

struct std_string {
    char buf[0x1c];
    std_string(const char*);
    ~std_string();
};

extern "C" void __stdcall sub_444E20();
extern "C" void __stdcall sub_541BF0();
extern "C" void* __stdcall sub_77E698();
extern "C" void* __stdcall sub_77E6AC();

BoxSelectCommand::BoxSelectCommand()
{
    sub_444E20();
    this->vtbl_e8 = (void*)0x7a9184;
    *(void**)this = (void*)0x7bd164;
    *(void**)((char*)this + 4) = (void*)0x7bd15c;
    *(void**)((char*)this + 0x10) = (void*)0x7bd154;
    *(void**)((char*)this + 0x14) = (void*)0x7bd144;
    *(void**)((char*)this + 0x2c) = (void*)0x7bd134;
    *(void**)((char*)this + 0x44) = (void*)0x7bd124;
    *(void**)((char*)this + 0x5c) = (void*)0x7bd114;
    *(void**)((char*)this + 0x74) = (void*)0x7bd104;
    *(void**)((char*)this + 0x8c) = (void*)0x7bd0f4;
    this->vtbl_e8 = (void*)0x7bd0ec;
    this->field_ec = 0;
    this->field_f0 = 0;
    this->field_f8 = 0;
    this->field_fc = 0;
    this->field_100 = 0;

    std_string s((const char*)0x7a9210);
    sub_541BF0();
    s.~std_string();
}
