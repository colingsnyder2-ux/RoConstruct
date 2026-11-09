// from server: 100% by atomic.potato
extern "C" void __cdecl func_00401630(void*, void*);
extern "C" void __cdecl func_00505cd0();
extern "C" void __cdecl func_007f4929(void*);

extern char data_00505d30;
extern char data_00b7e3d8;
extern char data_0097fec0;

void func_0096cb10()
{
    func_00401630(&data_00b7e3d8, &data_00505d30);
    func_00505cd0();
    func_007f4929(&data_0097fec0);
}
