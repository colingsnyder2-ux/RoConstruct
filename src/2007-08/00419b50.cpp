// from server: 42% by colin
struct VDHTMLWindowService_FactoryProduct {
    char pad0[0x28];
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    void construct(int a, int b, int c, int d, int e, int f, int g, int h);
};

extern "C" int __cdecl sub_418710(int, int);
extern "C" int __cdecl sub_570db0();
extern "C" int __cdecl sub_56d7d0();
extern "C" void* __cdecl sub_62fef6(unsigned int);
extern "C" int __cdecl sub_4137e0();

void VDHTMLWindowService_FactoryProduct::construct(int a, int b, int c, int d, int e, int f, int g, int h)
{
    int v1 = sub_418710(e, f);
    sub_570db0();
    this->field28 = g;
    this->field2c = h;
    *(int*)this = 0x787834;
    this->field30 = sub_56d7d0();
    void* p1 = sub_62fef6(8);
    if (p1) {
        *(int*)p1 = 0x787198;
        *(int*)((char*)p1 + 4) = a;
    } else {
        p1 = 0;
    }
    this->field34 = (int)p1;
    this->field38 = sub_56d7d0();
    void* p2 = sub_62fef6(8);
    if (p2) {
        *(int*)p2 = 0x787198;
        *(int*)((char*)p2 + 4) = b;
    } else {
        p2 = 0;
    }
    this->field3c = (int)p2;
    sub_4137e0();
}
