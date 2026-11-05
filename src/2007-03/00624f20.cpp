// from server: 100% by tester
struct CXTPCommandBar {
    int field0;
    int field4;
    int field8;
    int fieldC;
    CXTPCommandBar* construct(int arg);
};

CXTPCommandBar* CXTPCommandBar::construct(int arg)
{
    field0 = 0;
    field4 = arg;
    field8 = 0;
    fieldC = 0;
    return this;
}
