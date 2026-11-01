// from server: 100% by colin
struct CXTPDockingPaneMiniWnd {
    char pad[0xe8];
    int m_field;
    int GetSomething();
};

extern "C" int __fastcall sub_6e0540(int);

int CXTPDockingPaneMiniWnd::GetSomething()
{
    return sub_6e0540(m_field + 0x54);
}
