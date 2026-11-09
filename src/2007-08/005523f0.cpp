// from server: 100% by colin
extern "C" unsigned char __cdecl sub_00552120(int, int);

unsigned int __cdecl sub_005523f0(int a, int b)
{
    unsigned char b0 = sub_00552120(a, b);
    unsigned char b1 = sub_00552120(a, b);
    unsigned char b2 = sub_00552120(a, b);
    unsigned char b3 = sub_00552120(a, b);

    unsigned int v = b3;
    v = (v << 8) + b2;
    v = (v << 8) + b1;
    v = (v << 8) + b0;
    return v;
}
