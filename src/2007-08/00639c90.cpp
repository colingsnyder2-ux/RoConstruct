// from server: 100% by colin
struct CXTPControlComboBoxAutoCompleteWnd
{
    char m_pad0[0x84];
    int m_nUnknown84;
    int m_nUnknown88;
    int m_nUnknown8c;
    int m_nUnknown90;
    char m_pad1[0x158 - 0x94];
    void* m_pUnknown158;
    int GetValue();
};

int CXTPControlComboBoxAutoCompleteWnd::GetValue()
{
    int result = m_nUnknown90;
    if (result == 0)
    {
        result = m_nUnknown88;
        if (result <= 0)
        {
            void* p = m_pUnknown158;
            if (p != 0)
            {
                result = *(int*)((char*)p + 0x2c);
                if (result <= 0)
                {
                    result = *(int*)((char*)p + 0x28);
                }
            }
            else
            {
                result = m_nUnknown84;
            }
        }
    }
    return result;
}
