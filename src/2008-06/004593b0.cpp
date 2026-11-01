// from server: 100% by king_originala
extern "C" void __cdecl updateState(int enabled, void* handle);

struct S_func_0070bdf0 {
    void f(int a1);
};

struct CRobloxView {
    char padding0[0x54];
    void* handle;
    char padding1[0x58];
    S_func_0070bdf0 state;

    void baseActivate(int active, void* activated, void* deactivated);
    void activate(int active, void* activated, void* deactivated);
};

void CRobloxView::activate(int active, void* activated, void* deactivated)
{
    baseActivate(active, activated, deactivated);
    if (active) {
        updateState(1, handle);
        state.f(1);
    } else if (activated != deactivated) {
        updateState(0, handle);
        state.f(0);
    }
}
