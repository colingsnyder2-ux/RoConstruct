// from server: 100% by colin
namespace ns_ROCX00000c {
// from server: 100% by why2
struct CXTPCommandBar
{
    void f();
};

void CXTPCommandBar::f()
{
    void (__thiscall *fn)(CXTPCommandBar*, int, int);
    fn = *(void (__thiscall **)(CXTPCommandBar*, int, int))((*(char**)this) + 0x150);
    fn(this, -1, 0);
}
}
