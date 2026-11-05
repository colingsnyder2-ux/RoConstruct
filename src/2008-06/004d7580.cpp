// from server: 100% by colin
// from server: 68% by colin
extern "C" void __stdcall G1_func_006a165b(void*, int, int, void*);
extern "C" void func_00502a70();

struct S {
    void f();
};

void S::f()
{
    G1_func_006a165b(this, 4, 4, (void*)func_00502a70);
}
