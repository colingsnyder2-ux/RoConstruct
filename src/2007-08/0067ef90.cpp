// from server: 100% by colin
struct CXTPControlCheckBox {
    void* Create(int);
};

extern void* __fastcall sub_67EF20(CXTPControlCheckBox*);

void* __thiscall CXTPControlCheckBox::Create(int arg)
{
    CXTPControlCheckBox* p = (CXTPControlCheckBox*)sub_67EF20(this);
    void** vt = *(void***)p;
    void (__thiscall *fn)(void*, CXTPControlCheckBox*, int) = *(void (__thiscall **)(void*, CXTPControlCheckBox*, int))((char*)vt + 0xe0);
    fn(p, this, arg);
    return p;
}
