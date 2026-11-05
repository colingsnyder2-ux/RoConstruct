// from server: 100% by colin
struct CXTPPropertyGridInplaceList {
    int field0;
    char pad[0x50];
    int field54;
    void f();
};

extern "C" void __cdecl sub_682740(int);

void CXTPPropertyGridInplaceList::f()
{
    field54 = 0;
    sub_682740(0);
    (*(void (__thiscall **)(CXTPPropertyGridInplaceList *))(*(int *)this + 0x68))(this);
}
