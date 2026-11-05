// from server: 100% by tester
struct CXTPTabPaintManager_CAppearanceSetFlat
{
    char pad[0xc0];
    int m_fieldC0;
    int m_fieldC4;
    int m_fieldC8;
    int m_fieldCC;
    char pad2[0xfc - 0xd0];
    int m_fieldFC;

    void sub_6ad860();
};

extern "C" void __cdecl sub_6ad7f0(int, int*);

void CXTPTabPaintManager_CAppearanceSetFlat::sub_6ad860()
{
    int local[4];
    local[0] = m_fieldC0;
    local[1] = m_fieldC4;
    local[2] = m_fieldC8;
    local[3] = m_fieldCC;
    sub_6ad7f0(m_fieldFC, local);
}
