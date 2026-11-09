// from server: 100% by atomic.potato
extern "C" void __cdecl func_00401630(const void*, const void*);
extern "C" void __cdecl func_00523b70();
extern "C" void __cdecl func_007f4929(const void*);

extern const char global_00523bd0;
extern const char global_00b7fc70;
extern const char global_0097ff10;

void func_0096cc00()
{
    func_00401630(&global_00b7fc70, &global_00523bd0);
    func_00523b70();
    func_007f4929(&global_0097ff10);
}
