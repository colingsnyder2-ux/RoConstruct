// from server: 48% by atomic.potato
extern "C" void __cdecl func_008fb2b4(int);

extern "C" void (__cdecl *func_00b6b39c)(
    int, int, int, int, float, float);

void __declspec(naked) func_008f6d59(
    int a, int b, int c, int d, float e, float f)
{
    func_008fb2b4(1);
    func_00b6b39c(a, b, c, d, e, f);
}
