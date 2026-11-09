// from server: 43% by tester
// roc 2007-08 004dd1b0  unit: seg_004d0000  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004dd1b0

extern "C" int __stdcall sub_4f40d0(int, int);

struct T {
    void __thiscall call4(int*, int*, int*);
};

struct S {
    void __cdecl f(int, int, int, int, int);
};

void S::f(int a, int b, int c, int d, int e)
{
    int v0, v1, v2;
    v0 = sub_4f40d0(1, d);
    v1 = sub_4f40d0(1, e);
    v2 = sub_4f40d0(1, a);
    ((T*)((char*)this + 0xc))->call4(&v2, &v1, &v0);
    v0 = sub_4f40d0(1, b);
    v1 = sub_4f40d0(1, c);
    v2 = sub_4f40d0(1, a);
    ((T*)((char*)this + 0xc))->call4(&v2, &v1, &v0);
}
