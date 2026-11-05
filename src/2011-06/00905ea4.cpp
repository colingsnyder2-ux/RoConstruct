// from server: 59% by atomic.potato
extern "C" void __stdcall helper(int);
extern "C" void __stdcall imported(int, float, float, float);

struct S
{
    void function_00905ea4(int, float, float, float);
};

void S::function_00905ea4(int a, float b, float c, float d)
{
    helper(1);
    imported(a, b, c, d);
}
