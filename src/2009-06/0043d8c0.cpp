// from server: 100% by colin
struct CSelectionPropGrid {
    void* m_vtable;
    int m_field4;
    int m_field8;
    int m_fieldC;
    int m_field10;
    int m_field14;
    int m_field18;
    char m_field1C;
    char m_field1D;
    int m_field20;
    int m_field24;
    int m_field28;
    int m_field2C;
    CSelectionPropGrid* construct();
};

CSelectionPropGrid* CSelectionPropGrid::construct()
{
    m_vtable = (void*)0x8b5dec;
    m_field4 = 0;
    m_field8 = 0;
    m_fieldC = 0;
    m_field10 = 0;
    m_field14 = 0;
    m_field18 = 0;
    m_field1C = 0;
    m_field1D = 0;
    m_field20 = -1;
    m_field24 = 0;
    m_field28 = 0;
    m_field2C = 0;
    return this;
}
