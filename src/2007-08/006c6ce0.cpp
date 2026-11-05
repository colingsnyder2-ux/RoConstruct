// from server: 100% by colin
struct CXTPCustomizeSheet_CCustomizeEdit
{
    void func_00636a50(int);
    void func_006c6ce0(int);
};

void CXTPCustomizeSheet_CCustomizeEdit::func_006c6ce0(int a)
{
    func_00636a50(a);
    (*(void (***)(void))(*((char**)this + 0x5c / 4)))[0x148 / 4]();
}
