// from server: 100% by tester
struct CXTPCustomizeSheet_CCustomizeEdit {
    void SetSomething(int* p);
};

void CXTPCustomizeSheet_CCustomizeEdit::SetSomething(int* p)
{
    *(int**)((char*)this + 0xfc) = p;
    if (p == 0) {
        int* q = *(int**)((char*)this + 0x168);
        if (q != 0 && *(int*)((char*)q + 0x20) != 0) {
            (*(void (__thiscall**)(int*))(*(int*)q + 0x68))(q);
        }
    }
}
