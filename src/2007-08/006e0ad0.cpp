// from server: 48% by colin
// roc 2007-08 006e0ad0  unit: CXTPDockingPaneAutoHidePanel  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006e0ad0

extern "C" {
    void __stdcall sub_77ddb8(void*);
    void __stdcall sub_77dd74(void*, void*);
    void __stdcall sub_77ddbc(void*);
}

struct CXTPDockingPaneAutoHidePanel {
    char pad[0x1a0];
    void* field_0x1a0;
    void* GetPaneHwnd(void* param);
};

void* CXTPDockingPaneAutoHidePanel::GetPaneHwnd(void* param) {
    void* local1 = 0;
    void* local2 = 0;
    int flag = 0;
    void* result;

    if (this->field_0x1a0 == 0) {
        void* obj = this->field_0x1a0;
        void** vtable = *(void***)obj;
        void* fn = vtable[0x17];
        ((void (__stdcall*)(void*, void*))fn)(obj, &local1);
        flag = 1;
    } else {
        sub_77ddb8(&local2);
        flag = 2;
    }

    result = param;
    sub_77dd74(param, &local1);
    flag |= 4;

    if (flag & 2) {
        flag &= ~2;
        sub_77ddbc(&local1);
    }
    if (flag & 1) {
        sub_77ddbc(&local2);
    }

    return result;
}
