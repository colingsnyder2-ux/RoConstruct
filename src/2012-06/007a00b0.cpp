// from server: 67% by atomic.potato
extern "C" void __stdcall G1_func_00b22648(void*, const char*);

struct S {
    void* __cdecl f(int a, const char* b);
};

void* S::f(int a, const char* b)
{
    void* p = 0;
    if (a == 8)
        G1_func_00b22648(&p, "RBXAuthenticationNegotiation:");
    else
        G1_func_00b22648(&p, "Backspace");
    return p;
}
