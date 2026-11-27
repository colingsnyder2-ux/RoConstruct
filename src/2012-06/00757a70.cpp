// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct Signal { void fire(); };
struct VBase { int x; };
struct A { char pad[0x1c]; };
struct I { int i; };
struct Mid : A, I { char pad2[0x84 - 0x20]; };
struct D : Mid, virtual VBase { Signal sig; };
struct EventDesc
{
    char pad[0x30];
    Signal D::* member;
    void f(I* arg);
};
void EventDesc::f(I* arg)
{
    D* d = static_cast<D*>(arg);
    (d->*member).fire();
}
