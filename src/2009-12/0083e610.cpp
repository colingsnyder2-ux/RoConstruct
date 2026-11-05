// from server: 60% by atomic.potato
extern "C" void* __stdcall UnhookWindowsHookEx(void*);

struct CXTPCustomizeSheet_CCustomizeEdit
{
    void* field0;
    char pad0[8];
    void* fieldC;
    char pad1[8];
    void* field18;
    void Clear();
};

void CXTPCustomizeSheet_CCustomizeEdit::Clear()
{
    void* (__stdcall *fn)(void*) = UnhookWindowsHookEx;
    if (this->field0 != 0)
    {
        fn(this->field0);
        this->field0 = 0;
    }
    if (this->fieldC != 0)
    {
        fn(this->fieldC);
        this->fieldC = 0;
    }
    if (this->field18 != 0)
    {
        fn(this->field18);
        this->field18 = 0;
    }
    *(int*)0xb9b630 = 0;
    if (this->field18 != 0)
    {
        fn(this->field18);
        this->field18 = 0;
    }
    if (this->fieldC != 0)
    {
        fn(this->fieldC);
        this->fieldC = 0;
    }
    if (this->field0 != 0)
    {
        fn(this->field0);
        this->field0 = 0;
    }
}
