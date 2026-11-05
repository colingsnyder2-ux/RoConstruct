// from server: 100% by colin
struct CXTPPaintManager {
    void OnSetPaintManager();
};

extern CXTPPaintManager* g_pPaintManager;

void __cdecl SetPaintManager(CXTPPaintManager* p) {
    if (g_pPaintManager != 0) {
        g_pPaintManager->OnSetPaintManager();
    }
    g_pPaintManager = p;
    *(int*)((char*)p + 0x124) = 7;
    CXTPPaintManager* q = g_pPaintManager;
    void (CXTPPaintManager::*pm)() = *(void (CXTPPaintManager::**)())(*(int*)q + 0xa8);
    (q->*pm)();
}
