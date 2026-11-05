// from server: 53% by atomic.potato
extern "C" void __cdecl func_008fb2b4(int);

extern "C" void __stdcall func_00b6b344(float, int);

void __stdcall func_008f7bbe(float a, float b)
{
    func_008fb2b4(1);
    func_00b6b344(a, *(int*)&b);
}
