// from server: 54% by atomic.potato
extern "C" void __cdecl func_008fb2b4(int);

extern "C" int __cdecl imported_func(int, int, float);

int __stdcall func_008f7c62(int a, int b, float c)
{
    func_008fb2b4(1);
    return imported_func(a, b, c);
}
