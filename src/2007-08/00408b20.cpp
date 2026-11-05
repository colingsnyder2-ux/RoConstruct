// from server: 100% by colin
struct Target {
    void Call();
};

extern "C" Target* __cdecl CreateTarget();

int __stdcall Wrapper(int unused) {
    Target* t = CreateTarget();
    t->Call();
    return 0;
}
