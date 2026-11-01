// from server: 100% by colin
struct CXTPReportControl {
    char pad[0x220];
    int m_nLockUpdate;
    void LockUpdate(int, int, int);
    void RecalcLayout();
    void OnUpdate();
};

void CXTPReportControl::LockUpdate(int, int, int)
{
    if (m_nLockUpdate == 0)
    {
        m_nLockUpdate = 1;
        OnUpdate();
        RecalcLayout();
        (*(void (__thiscall **)(CXTPReportControl *))(*(int *)this + 0x154))(this);
        m_nLockUpdate = 0;
    }
}
