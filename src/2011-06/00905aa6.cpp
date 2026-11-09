// from server: 53% by atomic.potato
extern "C" void __stdcall sub_009092d5(int);

extern "C" void __stdcall imported_00c9b614(float, int);

struct S_func_00905aa6 {
    void f(int, float);
};

void S_func_00905aa6::f(int a, float b)
{
    sub_009092d5(1);
    imported_00c9b614(b, a);
}
