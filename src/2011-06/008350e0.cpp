// from server: 100% by tester
struct CXTPReportControl {
    char pad[0x2a8];
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
        (*(void (__thiscall **)(CXTPReportControl *))(*(int *)this + 0x164))(this);
        m_nLockUpdate = 0;
    }
}
