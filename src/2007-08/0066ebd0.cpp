// from server: 100% by colin
struct CXTPDockingPaneManager {
    void f();
};

extern "C" void* __stdcall func_0066e160();
extern "C" void __fastcall func_0068fc90(void*);

void CXTPDockingPaneManager::f()
{
    void* p = func_0066e160();
    void* node = *(void**)((char*)p + 4);
    while (node != 0) {
        void* cur = node;
        void* arg = *(void**)((char*)cur + 8);
        node = *(void**)cur;
        func_0068fc90(arg);
    }
}
