// from server: 41% by atomic.potato
extern "C" void __cdecl helper(int);

extern "C" int __cdecl imported(int, int, int, int, int, float);

int func_008f63e7(int a, int b, int c, int d, int e, float f)
{
    helper(1);
    return imported(a, b, c, d, e, f);
}
