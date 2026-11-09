// from server: 24% by atomic.potato
struct S {
    char pad0[0x28];
    int field28;
    int field2c;
    int field30;
    int f(int, int, int, int, int, int, int, int, int, int);
};

extern "C" void __cdecl sub_4015a0(int, int);
extern "C" int __cdecl sub_67b5b0();
extern "C" int __cdecl sub_67c5c0();
extern "C" int __cdecl sub_6cb9e0(int, int, int, int, int, int, int, int);
extern "C" int* __cdecl sub_6799b0(int*);
extern "C" void __cdecl sub_982114(int);
extern "C" int __cdecl sub_972290(int, int);
extern "C" int __cdecl sub_b229ec(int);

int S::f(int a, int b, int c, int d, int e, int g, int h, int i, int j, int k)
{
    sub_4015a0(0xe28d84, 0x67b610);
    int edi = sub_67b5b0();
    sub_67c5c0();
    int v1 = a;
    int v2 = b;
    int v3 = c;
    sub_6cb9e0(edi, v1, v2, v3, d, e, g, h);
    field28 = edi;
    int tmp = 0;
    field2c = *sub_6799b0(&tmp);
    sub_982114(i);
    sub_4015a0(0xe28d84, 0x67b610);
    field30 = sub_67b5b0();
    if (*(char*)0xe580b3 != 0) {
        if (sub_b229ec(0xd96fc4) == 0) {
            int p = *(int*)0xe5809c;
            if (p != 0) {
                if (((char(__cdecl*)(int,int,int))p)(0xb44978, 0xb58618, 0xd4) != 0)
                    goto done;
            }
            sub_972290(*(unsigned char*)0xe580b3, 0xb587b8);
        }
    }
done:
    return (int)this;
}
