// from server: 100% by tester
struct CXTPDockingPaneBase {
    char pad[0xc];
    int m_count;
    void* m_head;
    void Insert(void* node);
    void RemoveAll();
};

void CXTPDockingPaneBase::Insert(void* node) {
    *(void**)node = m_head;
    m_head = node;
    if (--m_count == 0)
        RemoveAll();
}
