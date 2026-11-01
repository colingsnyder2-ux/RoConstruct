// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD

struct B { __declspec(dllimport) int m(); };
struct A { int x; B b; };

int sub_0044d6d0(A** a)
{
    return (*a)->b.m();
}
