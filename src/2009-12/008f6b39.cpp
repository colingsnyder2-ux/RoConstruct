// from server: 41% by atomic.potato
extern "C" void __cdecl func_008fb2b4(int);

extern "C" int __cdecl imported_func(int, int, int, int, int, float);

int func_008f6b39(int a, int b, int c, int d, int e, float f)
{
    func_008fb2b4(1);
    return imported_func(a, b, c, d, e, f);
}
