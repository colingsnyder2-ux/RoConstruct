// from server: 100% by tester
struct CXTPControlSelector {
    void m();
    int field_0;
    int field_4;
    int field_8;
    int field_c;
};

void CXTPControlSelector::m()
{
    if (field_4 != 0 && field_c != -1) {
        (*(void (__thiscall **)(int, int))(*(int *)field_4 + 0x38))(field_4, field_c);
        field_c = -1;
    }
}
