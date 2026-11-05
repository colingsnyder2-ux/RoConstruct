// from server: 100% by tajop
extern "C" __declspec(dllimport) void* __stdcall GetFocus();

struct CNode {
    CNode* pNext;
    CNode* pPrev;
    void* data;
};

inline void* GetNext(CNode*& rPosition)
{
    CNode* pNode = rPosition;
    rPosition = pNode->pNext;
    return pNode->data;
}

struct CXTPDockingPaneManager {
    char pad[0x138];
    void* field_138;
    void* getActivePane();
    void update();
};

void CXTPDockingPaneManager::update() {
    void* focus = GetFocus();
    if (field_138 == focus)
        return;
    field_138 = focus;
    void* pane = getActivePane();
    CNode* pos = *(CNode**)((char*)pane + 4);
    while (pos) {
        void* obj = GetNext(pos);
        int type = *(int*)((char*)obj + 0x18);
        if (type == 1 || type == 3) {
            void* vtable = *(void**)obj;
            void (__thiscall *fn)(void*) = *(void (__thiscall**)(void*))((char*)vtable + 0x28);
            fn(obj);
        }
    }
}
