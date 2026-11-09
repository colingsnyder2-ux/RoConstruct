// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct B_0065c270 { virtual void f(); };
struct Pad_0065c270 { virtual void p(); char pad[0x98]; };
struct D_0065c270 : Pad_0065c270, B_0065c270 {};
struct A_0065c270 { char pad[0xe8]; B_0065c270* link; };
struct P_0065c270 { A_0065c270* getAssembly(); };
D_0065c270* get_0065c270(P_0065c270* p)
{
    A_0065c270* a = p->getAssembly();
    if (a)
        return static_cast<D_0065c270*>(a->link);
    return 0;
}
