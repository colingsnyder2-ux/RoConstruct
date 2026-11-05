// from server: 58% by atomic.potato
extern "C" void __cdecl func_008fb2b4(int);

extern "C" void __cdecl func_00b6b364(const char *, float, float, float);

void __declspec(naked) func_008f7e83(const char *a, float b, float c, float d)
{
    func_008fb2b4(1);
    func_00b6b364(a, b, c, d);
}
