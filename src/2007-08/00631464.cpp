// from server: 32% by colin
extern "C" int __stdcall MSVCR80_CIfmod(int, int);
extern int G1;
extern int G2;
extern int G3;

struct S {
    void f();
};

void S::f()
{
    MSVCR80_CIfmod(G1, G2);
    G3 = 0;
}
