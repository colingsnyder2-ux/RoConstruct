// from server: 100% by colin
struct CXTPPropertyGrid {
    void sub_683E20();
    void func_684550();
};

void CXTPPropertyGrid::func_684550()
{
    int* p = *(int**)((char*)this + 0x13c);
    int* q = *(int**)((char*)p + 0x34);
    void (__thiscall *f1)(void*) = *(void (__thiscall **)(void*))((char*)*(int**)q + 0x58);
    f1(q);
    int* r = *(int**)((char*)this + 0x13c);
    void (__thiscall *f2)(void*) = *(void (__thiscall **)(void*))((char*)*(int**)r + 0x34);
    f2(r);
    sub_683E20();
}
