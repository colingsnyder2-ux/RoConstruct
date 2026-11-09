// from server: 49% by atomic.potato
extern "C" void __cdecl sub_009092d5(int);
extern "C" void __cdecl imported_call(float, float);

struct S_func_00905b42
{
    void f(float, float);
};

void S_func_00905b42::f(float a, float b)
{
    sub_009092d5(1);
    imported_call(b, a);
}
