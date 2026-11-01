// from server: 100% by colin
struct S {
    int field0;
    void (__thiscall *field4)(int);
    void f(int);
};

extern "C" int __fastcall sub_573890(int);

void S::f(int a)
{
    int v;
    if (a != 0) {
        v = sub_573890(a - 4);
    } else {
        v = sub_573890(0);
    }
    field4(v + 0x18);
}
