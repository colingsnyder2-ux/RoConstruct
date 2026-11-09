// from server: 100% by atomic.potato
extern "C" void __cdecl func_00401630(void*, void*);
extern "C" void __cdecl func_00523b00();
extern "C" void __cdecl func_007f4929(void*);

extern char global_00b7fc6c;
extern char global_00523b60;
extern char global_0097ff00;

void func_0096cbd0()
{
    func_00401630(&global_00b7fc6c, &global_00523b60);
    func_00523b00();
    func_007f4929(&global_0097ff00);
}
