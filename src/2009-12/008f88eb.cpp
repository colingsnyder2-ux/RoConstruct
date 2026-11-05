// from server: 52% by atomic.potato
extern "C" void __cdecl func_008fb2b4(int);

extern "C" void __cdecl func_00b6b338(float, float, float);

void __declspec(naked) func_008f88eb(float a, float b, float c)
{
    func_008fb2b4(1);
    func_00b6b338(a, b, c);
}
