// from server: 47% by colin
struct EnumDesc {
    void* construct(int a, int b, int c, int d, int e, int f, int g, int h, int i);
};

extern "C" int __cdecl sub_577100(int, int);
extern "C" void __cdecl sub_574F50(int);
extern "C" void __cdecl sub_62FC62(int);

void* EnumDesc::construct(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    int* p = (int*)a;
    *p = 0;
    *(int*)(this) = b;
    int r = sub_577100(c, d);
    sub_574F50(r);
    sub_62FC62(i);
    *(int*)(this) = 0x7aaca4;

    return this;
}
