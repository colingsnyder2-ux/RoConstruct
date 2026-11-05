// from server: 86% by atomic.potato
struct S_func_005d87b0 {
    void f(void* a, int b);
};

extern "C" void __stdcall S_func_005d8740(void*, int);

void S_func_005d87b0::f(void* a, int b)
{
    if (b != 4) {
        S_func_005d8740(a, b);
        return;
    }

    *(int*)a = 0x00d95f44;
    ((char*)a)[4] = 0;
    ((char*)a)[5] = 0;
}
