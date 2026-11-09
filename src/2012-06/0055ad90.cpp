// from server: 83% by atomic.potato
struct S_func_0055ad90 {
    char f();
};

extern "C" void* __cdecl func_0055ad10();
extern "C" int __cdecl func_005a0f50();

char S_func_0055ad90::f()
{
    void* p = func_0055ad10();
    if (p) {
        return (char)func_005a0f50();
    }
    return 0;
}
