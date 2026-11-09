// from server: 41% by atomic.potato
extern "C" void __cdecl sub_008fb2b4(int);

extern "C" int __cdecl imported_call(int, int, int, int, int, float);

int func_008f8e67(int a, int b, int c, int d, int e, float f)
{
    sub_008fb2b4(1);
    return imported_call(a, b, c, d, e, f);
}
