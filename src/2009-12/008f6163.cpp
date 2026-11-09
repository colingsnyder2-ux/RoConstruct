// from server: 47% by atomic.potato
extern "C" void __cdecl func_008fb2b4(int);

extern "C" void __cdecl func_00b6b380(int, int, int, int, int, int, float);

void __declspec(naked) func_008f6163(int a, int b, int c, int d, int e, int f, float g)
{
    func_008fb2b4(1);
    func_00b6b380(a, b, c, d, e, f, g);
}
