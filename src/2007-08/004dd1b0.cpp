// from server: 68% by EspClaude
// from server: 43% by tester
// roc 2007-08 004dd1b0  unit: seg_004d0000  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004dd1b0

// Target takes one value in edi (whole-program/LTCG register argument, not reproducible
// without /GL); here it is modelled as the last stack argument e.
extern "C" int __cdecl sub_4f40d0(int, int);

struct T {
    void __thiscall call4(int*, int*, int*);
};

struct S {
    char pad[0xc];
    T t;
};

void __cdecl f(S* obj, int b, int c, int d, int e)
{
    int x = sub_4f40d0(e, 1);
    int y = sub_4f40d0(c, 1);
    int z = sub_4f40d0(b, 1);
    obj->t.call4(&z, &y, &x);
    x = sub_4f40d0(d, 1);
    y = sub_4f40d0(e, 1);
    z = sub_4f40d0(b, 1);
    obj->t.call4(&z, &y, &x);
}
