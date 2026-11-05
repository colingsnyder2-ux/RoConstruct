// from server: 100% by atomic.potato
extern "C" void __cdecl func_00401630(void*, void*);
extern "C" void __cdecl func_0051be70(void);
extern "C" void __cdecl func_007f4929(void*);

extern char global_0051bed0;
extern char global_00b7eb60;
extern char global_0097fee0;

void func_0096cb70()
{
    func_00401630(&global_00b7eb60, &global_0051bed0);
    func_0051be70();
    func_007f4929(&global_0097fee0);
}
