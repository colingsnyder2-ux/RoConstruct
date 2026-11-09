// from server: 49% by atomic.potato
extern "C" void __cdecl func_008fb2b4(int);

extern "C" void __cdecl func_00b6b398(
    int, int, int, int, int, float);

void __declspec(naked) func_008f6c38(
    int a, int b, int c, int d, int e, float f)
{
    func_008fb2b4(1);
    func_00b6b398(a, b, c, d, e, f);
}
