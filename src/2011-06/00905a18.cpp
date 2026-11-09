// from server: 59% by atomic.potato
extern "C" void __stdcall helper(int);
extern "C" void __stdcall imported(float, float, float, int);

struct S
{
    void function_00905a18(int value, float a, float b, float c);
};

void S::function_00905a18(int value, float a, float b, float c)
{
    helper(1);
    imported(c, b, a, value);
}
