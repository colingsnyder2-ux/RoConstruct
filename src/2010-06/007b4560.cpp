// from server: 100% by tester
struct CXTPControlComboBoxList {
    char pad[0x180];
    void* m_pList;
    void OnSelectionChanged(int, int, int);
};

void CXTPControlComboBoxList::OnSelectionChanged(int a, int b, int c) {
    void* p = m_pList;
    void** vt = *(void***)p;
    ((void (__thiscall*)(void*))vt[0x164 / 4])(p);
    vt = *(void***)p;
    ((void (__thiscall*)(void*))vt[0x98 / 4])(p);
}
