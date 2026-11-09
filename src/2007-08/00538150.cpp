// from server: 22% by colin
struct S {
    int f();
};

extern "C" int __cdecl sub_534DA0(int, int, int, int);
extern "C" int __cdecl sub_5358E0();
extern "C" int __cdecl sub_5372D0(int);
extern "C" int __cdecl sub_5348C0(int, int, int);
extern "C" int __cdecl sub_411810();
extern "C" int __cdecl sub_537360(int);
extern "C" int __cdecl sub_535900();
extern "C" int __cdecl sub_5373F0(int);
extern "C" int __cdecl sub_535A00(int, int);
extern "C" int __cdecl sub_5366A0(int, int, int);
extern "C" int __cdecl sub_535920();
extern "C" int __cdecl sub_537480(int);
extern "C" int __cdecl sub_4A6C60(int, int);
extern "C" int __cdecl sub_411830();
extern "C" int __cdecl sub_411D40(int);
extern "C" int __cdecl sub_40FAC0(int, int);
extern "C" int __cdecl sub_40FA90(int, int);
extern "C" int __cdecl sub_535940(int, int, int, int, int);
extern "C" int __cdecl sub_5359E0();
extern "C" int __cdecl sub_537B60(int, int);
extern "C" int __cdecl sub_538690(int, int, int, int, int);
extern "C" int __cdecl sub_492360(int);
extern "C" int __cdecl sub_5BDEE0(int, int, int);

int S::f()
{
    int* p;
    int* q;
    int a, b, c, d, e;
    int r;
    int v;

    p = (int*)0;
    q = (int*)0;

    if (sub_5358E0()) {
        sub_5372D0((int)this + 4);
        sub_5348C0(*(int*)0, *(int*)0, *(int*)0);
        return 1;
    }
    if (sub_411810()) {
        sub_537360((int)this + 4);
        goto L_538066;
    }
    if (sub_535900()) {
        sub_5373F0((int)this + 4);
        sub_535A00(*(int*)0, *(int*)0);
        sub_5366A0(*(int*)0, *(int*)0, *(int*)0);
        return 1;
    }
    if (sub_535920()) {
        sub_537480((int)this + 4);
        sub_4A6C60(*(int*)0, *(int*)0);
        sub_5366A0(*(int*)0, *(int*)0, *(int*)0);
        return 1;
    }
    if (sub_411830()) {
        sub_411D40((int)this + 4);
        sub_40FAC0(*(int*)0, *(int*)0);
        sub_40FA90(*(int*)0, *(int*)0);
        sub_535940(*(int*)0, *(int*)0, *(int*)0, *(int*)0, *(int*)0);
        return 1;
    }
    if (sub_5359E0()) {
        sub_537B60((int)this, (int)&p);
        if (p != 0) {
            sub_40FAC0((int)p, (int)&a);
            sub_40FA90((int)p, (int)&b);
            r = sub_538690(*(int*)0, *(int*)0, *(int*)0, *(int*)0, *(int*)0);
            sub_492360((int)&p);
            return r;
        }
        sub_5BDEE0(*(int*)0, 0, 0);
        sub_492360((int)&p);
        return 1;
    }
    return 0;

L_538066:
    sub_534DA0(*(int*)0, *(int*)0, *(int*)0, *(int*)0);
    return 1;
}
