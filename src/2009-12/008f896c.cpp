// from server: 62% by atomic.potato
extern "C" void __cdecl func_008fb2b4(int);

extern "C" void (__cdecl *func_00b6b328)(const char*, float, float, float);

void __declspec(naked) __cdecl func_008f896c(const char* a, float b, float c, float d)
{
    func_008fb2b4(1);
    func_00b6b328(a, b, c, d);
}
