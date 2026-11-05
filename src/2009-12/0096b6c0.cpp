// from server: 70% by atomic.potato
extern "C" void func_007b7350(void*);
extern "C" void __cdecl func_007f4929(const char*);

struct S
{
    void f();
};

extern char global_00b7dc40;
extern char global_0097f1b0;

void S::f()
{
    func_007b7350(&global_00b7dc40);
    func_007f4929(&global_0097f1b0);
}
