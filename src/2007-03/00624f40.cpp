// from server: 100% by tester
struct CXTPCommandBar
{
    int field0;
    int field4;
    int field8;
    int fieldC;
    CXTPCommandBar* assign(const CXTPCommandBar* other);
};

CXTPCommandBar* CXTPCommandBar::assign(const CXTPCommandBar* other)
{
    field0 = other->field0;
    field4 = other->field4;
    fieldC = 0;
    field8 = 0;
    return this;
}
