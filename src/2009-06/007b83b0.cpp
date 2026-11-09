// from server: 100% by why2
// roc 2009-06 007b83b0  unit: CXTPRibbonBar  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b83b0

struct CXTPRibbonBar {
    void* GetSomething(int, int);
};

void* CXTPRibbonBar::GetSomething(int a, int b) {
    void** vtbl = *(void***)this;
    void* fn = vtbl[0x1dc / 4];
    return ((void* (__thiscall*)(void*, int, int))fn)(this, a, 0);
}
