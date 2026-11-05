// from server: 50% by atomic.potato
struct P_func_008375e0 { void g(); };
struct S_func_008375e0 {
    char pad[252];
    P_func_008375e0* m_p;
    void f();
};
void S_func_008375e0::f()
{
    m_p->g();
}

struct CXTPMenuBarMDIMenuInfo {
    char pad0[0x2c];
    int m_nCount;
    int GetStartPosition();
    void GetNextAssoc(int* p, int* q);
};

struct CXTPMenuBar {
    char pad0[0x1bc];
    CXTPMenuBarMDIMenuInfo* m_pInfo;
    void f(int);
};

void CXTPMenuBar::f(int arg)
{
    char pad[4];
    int local1;
    int local2;
    m_pInfo->GetStartPosition();
    local1 = m_pInfo->GetStartPosition();
    if (local1 != 0) {
        do {
            m_pInfo->GetNextAssoc(&local2, &local1);
            ((void (__thiscall*)(void*, int))0x835ba0)((void*)local2, arg);
        } while (local1 != 0);
    }
}
