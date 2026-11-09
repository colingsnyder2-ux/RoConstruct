// from server: 38% by colin
struct CMarshalWindow {
    void* vtable;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
    int field_20;
    int field_24;
    int field_28;
    char field_2c[1];
    void construct(int);
    void init(int);
};

extern "C" void __stdcall sub_4330B0(char*);
extern "C" void __stdcall sub_4336F0(CMarshalWindow*, int, int, int, int, int, int, int);

void CMarshalWindow::construct(int arg)
{
    this->field_4 = 0;
    this->field_14 = 0;
    this->field_18 = 0;
    this->field_1c = 0;
    this->field_20 = *(int*)0x77ec2c;
    this->vtable = (void*)0x78bae0;
    this->field_24 = 0;
    sub_4330B0(this->field_2c);
    this->field_28 = arg;
    sub_4336F0(this, arg, 0, 0x80000000, 0, 0, 0, 0);
}
