// from server: 100% by tester
struct CXTPDockingPaneAutoHidePanel {
    char pad[0xa8];
    void* field_a8;
    void* method_6dae10(int, int);
    void method_6dbb20(void*, int);
    void method_6dbc10(int, int, int);
};

void CXTPDockingPaneAutoHidePanel::method_6dbc10(int a, int b, int c) {
    void* result = method_6dae10(b, c);
    if (result != 0) {
        void* p = field_a8;
        if (p != 0) {
            void* q = *(void**)((char*)p + 0xf8);
            if (*(void**)((char*)q + 0x1a4) == result) {
                void** vt = *(void***)result;
                void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vt[0x58 / 4];
                fn(result);
                return;
            }
        }
        method_6dbb20(result, 1);
    }
}
