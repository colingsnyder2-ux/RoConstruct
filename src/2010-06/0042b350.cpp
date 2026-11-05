// from server: 100% by atomic.potato
struct CMainFrame {
    void* field0;
    void SetSomething(void* p);
};

struct Helper {
    void Release();
};

extern "C" void __cdecl sub_7A799A(void* p);

void CMainFrame::SetSomething(void* p) {
    void* old = field0;
    field0 = p;
    if (old) {
        ((Helper*)old)->Release();
        sub_7A799A(old);
    }
}
