// from server: 34% by atomic.potato
extern "C" void __stdcall func_004c8700();
extern "C" void __stdcall func_008d8870();

struct S {
    char pad0[4];
    char field4;
    int method(int a, int b);
};

int S::method(int a, int b)
{
    int local = 0;
    func_004c8700();
    func_008d8870();
    return a;
}
