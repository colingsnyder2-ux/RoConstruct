// from server: 29% by tester
struct Scale9Frame {
    char pad[0x170];
    short field_170;
    short field_172;
    short field_174;
    char pad2[0x190 - 0x176];
    int field_190;
    void method(int);
};

extern "C" void __stdcall sub_7ecf00(int, short*, int*, int*, int*, int, int);

void Scale9Frame::method(int arg)
{
    float f0 = 0.0f;
    float f1 = 0.0f;
    float f2 = 0.0f;
    float f3 = 0.0f;
    short a = field_170;
    short b = field_172;
    int ia = (int)(short)(a * 3);
    int ib = (int)(short)(b * 3);
    f0 = (float)ia;
    f1 = (float)ib;
    sub_7ecf00(arg, &field_174, (int*)&f0, (int*)&f1, (int*)&f2, (int)&field_190, 0);
}
