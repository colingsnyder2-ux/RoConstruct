// from server: 71% by atomic.potato
extern "C" void __cdecl G1_func_0080a058(char *);

extern "C" void __cdecl G1_func_00a404d0();

struct S {
    int unused;
    char *value;
    char flag;
    void f();
};

void S::f()
{
    if (value != 0) {
        if (flag != 0)
            G1_func_00a404d0();
        G1_func_0080a058(value);
    }
}
