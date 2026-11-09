// from server: 41% by atomic.potato
extern "C" void __stdcall func_008af41a(int);

extern "C" void __stdcall func_00bec14c(
    int, int, int, int, int, float, int);

void __declspec(naked) func_008aac9f(
    int a, int b, int c, int d, int e, float f)
{
    func_008af41a(1);
    func_00bec14c(a, b, c, d, e, f, 0);
}
