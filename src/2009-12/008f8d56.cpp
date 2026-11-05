// from server: 43% by atomic.potato
extern "C" void __stdcall func_008fb2b4(int);

extern "C" int __stdcall func_00b6b350(int, int, int, float, int);

int __stdcall func_008f8d56(int a, int b, int c, float d)
{
    int value;
    func_008fb2b4(1);
    value = func_00b6b350(a, b, c, d, 0);
    return value;
}
