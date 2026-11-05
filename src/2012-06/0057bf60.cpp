// from server: 73% by atomic.potato
extern "C" int* __cdecl func_00522770(int p);
extern "C" void __cdecl func_0056b9d0(int a, int b, int c);

void func_0057bf60(int a, int b, int c, int d)
{
    int* p = func_00522770(a + 4);
    func_0056b9d0(c, b, *p);
}
