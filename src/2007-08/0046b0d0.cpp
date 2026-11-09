// from server: 43% by colin
struct LuaObjectWriter {
    void* vtable;
    int field4;
    int field8;
    int fieldC;
    double d10;
    double d18;
    double d20;
    double d28;
    double d30;
    double d38;
    double d40;
    double d48;
    double d50;
    double d58;
    double d60;
    double d68;
    char pad70[0x30];
    void ctor(int arg);
};

extern "C" {
    void __stdcall sub_77e6a4();
    void __stdcall sub_77e698();
    void __stdcall sub_77e6ac();
    void __cdecl sub_630a1e();
}

void LuaObjectWriter::ctor(int arg)
{
    this->vtable = (void*)0x7961b4;
    this->field4 = arg;
    sub_77e6a4();
    this->d10 = 0.0;
    this->d18 = 0.0;
    this->d20 = 0.0;
    this->d28 = 0.0;
    this->d30 = 0.0;
    this->d38 = 0.0;
    this->d40 = 0.0;
    this->d48 = 0.0;
    this->d50 = 0.0;
    this->d58 = 0.0;
    this->d60 = 0.0;
    this->d68 = 0.0;
    this->field8 = 0;
    this->fieldC = 0;
    sub_77e698();
    sub_77e6ac();
}
