// from server: 50% by atomic.potato
extern "C" void __stdcall sub_00499fe0();
extern "C" void __stdcall sub_00759de0(double, const char*, double, void*);

struct TypedPercentItem {
    char pad[0xa8];
    int field_a8;
    void func();
};

void TypedPercentItem::func()
{
    sub_00499fe0();
    double d = *(double*)0x00b507e0;
    double v = d * *(double*)0x00b507e0;
    sub_00759de0(v, (const char*)0x00b626f4, d, this);
}
