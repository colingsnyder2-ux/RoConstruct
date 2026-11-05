// from server: 100% by colin
struct CXTPDockingPaneSplitterContainer {
    void* InsertPane(void*, void*);
    void RemovePane(int);
    void AddPane(void*, int);
};

void CXTPDockingPaneSplitterContainer::AddPane(void* pane, int index) {
    if (pane == 0) {
        RemovePane(index);
        return;
    }
    void* node = InsertPane(*(void**)((char*)pane + 4), pane);
    *(int*)((char*)node + 8) = index;
    int* prev = *(int**)((char*)pane + 4);
    if (prev != 0) {
        *prev = (int)node;
        *(int**)((char*)pane + 4) = (int*)node;
    } else {
        *(int**)((char*)this + 4) = (int*)node;
        *(int**)((char*)pane + 4) = (int*)node;
    }
}
