// from server: 51% by colin
struct S {
    int f();
};

extern "C" int __cdecl sub_489940(int);
extern "C" int __cdecl sub_48a7a0(int, int);
extern "C" int __cdecl sub_4893c0(int, int, int, int, int);
extern "C" void __cdecl sub_62fc62(int);

int S::f()
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    int q;
    int r;
    int s;
    int t;
    int u;
    int v;
    int w;
    int x;
    int y;
    int z;

    a = 0;
    sub_489940(a);
    b = *(int*)((char*)&a + 0x3c);
    c = *(int*)((char*)&a + 0x34);
    d = sub_48a7a0(c, b);
    e = *(int*)((char*)&a + 0x34);
    f = *(int*)((char*)&a + 0x38);
    g = d;
    *(int*)(e + 4) = g;
    h = *(int*)((char*)&a + 0x38);
    i = *(int*)h;
    j = h;
    k = (int)&a + 0x38;
    l = i;
    m = k;
    n = (int)&a + 0x34;
    o = 0xffffffff;
    sub_4893c0(m, n, l, j, k);
    p = *(int*)((char*)&a + 0x38);
    sub_62fc62(p);
    return e;
}
