// from server: 42% by Intel
extern int g_00ac14a8;
extern int g_00d0fc50;

extern "C" int __stdcall func_00744650(void*, void*, void*);
extern "C" int __stdcall func_007448b0(void*, void*);
extern "C" void __stdcall func_00983144(void*, void*, void*);

struct ErrorInfoInjector {
    void* clone_impl();
};

void* ErrorInfoInjector::clone_impl()
{
    int r1 = func_00744650(0, 0, 0);
    int r2 = func_007448b0((void*)r1, 0);
    func_00983144(0, (void*)g_00d0fc50, (void*)r2);
    return (void*)0;
}
