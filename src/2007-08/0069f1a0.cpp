// from server: 100% by colin
struct CXTPWinThemeWrapper
{
    void construct();
    void init(void*);
    int field0;
    char pad[0x50];
    int field54;
    char pad2[0x54];
    int fieldAC;
    void* method_69f190();
    void method_714da0(void*);
    void* setEditable();
};

void* CXTPWinThemeWrapper::setEditable()
{
    void* p = method_69f190();
    method_714da0(p);
    field0 = 0x7d2ce4;
    field54 = 0x7d2cd4;
    fieldAC = 0;
    return this;
}
