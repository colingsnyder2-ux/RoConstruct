// from server: 100% by colin
struct CXTPDockingPaneSplitterContainer {
    void RemovePane(int);
    void* InsertPane(void*, void*);
    void AddPane(void*, int);
};

void CXTPDockingPaneSplitterContainer::AddPane(void* pane, int index) {
    if (pane == 0) {
        RemovePane(index);
        return;
    }
    void* node = InsertPane(pane, *(void**)pane);
    *(int*)((char*)node + 8) = index;
    int* prev = *(int**)pane;
    if (prev != 0) {
        *(int**)((char*)prev + 4) = (int*)node;
        *(int**)pane = (int*)node;
    } else {
        *(int**)((char*)this + 8) = (int*)node;
        *(int**)pane = (int*)node;
    }
}
