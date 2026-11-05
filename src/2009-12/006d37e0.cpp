// from server: 14% by atomic.potato
extern "C" {
    void __stdcall G1_func_0098b6e8();
    void __stdcall G1_func_0098b6e4();
}

void G1_func_00408db0();
void G1_func_00418460();
void G1_func_0063f270();

struct S {
    void f();
};

void S::f()
{
    char buf1[0x44];
    char buf2[0x58];
    G1_func_0098b6e8();
    G1_func_00418460();
    G1_func_0063f270();
    G1_func_00408db0();
    G1_func_0098b6e4();
}
