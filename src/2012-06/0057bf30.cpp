// from server: 73% by atomic.potato
extern "C" int __cdecl func_0057a050(int);
extern "C" void __cdecl func_0056c980(int, int, int);

void func_0057bf30(int a, int b, int c, int d)
{
    int value = func_0057a050(a + 4);
    func_0056c980(c, b, *(int*)value);
}
