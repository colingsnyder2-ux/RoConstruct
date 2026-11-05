// from server: 100% by tester
struct CControlButtonExpand {
    char pad[0x17c];
    void* field_170;
    void RemoveControl(void*);
    void OnControlRemoved(void*);
};

struct CXTPToolBar {
    void* FindControl(void*);
};

void CControlButtonExpand::OnControlRemoved(void* p)
{
    if (field_170 != 0) {
        void* c = ((CXTPToolBar*)p)->FindControl(field_170);
        if (c != 0) {
            RemoveControl(c);
            field_170 = 0;
            (*(void (__thiscall**)(void*, void*))(*(int*)c + 0x1ec))(c, p);
        }
    }
}
