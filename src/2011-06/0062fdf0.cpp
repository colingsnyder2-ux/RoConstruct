// from server: 44% by colin
struct HopperBin {
    char pad0[4];
    int field4;
    int method_62f840(int, int);
    int method_62fdf0(int, int);
};

extern "C" int __stdcall sub_4c1670(int, int);

int HopperBin::method_62fdf0(int a, int b)
{
    field4 = 0;
    sub_4c1670(1, (int)&field4);
    return method_62f840(a, b);
}
