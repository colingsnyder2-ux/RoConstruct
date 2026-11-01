// from server: 100% by colin
struct CSelectionTreeCtrl {
    char pad[0xe4];
    void* m_ptr;
    int GetSelected();
};

extern int __fastcall sub_410d40(void* p);

int CSelectionTreeCtrl::GetSelected()
{
    if (m_ptr)
        return sub_410d40(m_ptr);
    return 0;
}
