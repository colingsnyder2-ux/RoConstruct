// from server: 56% by atomic.potato
extern "C" void __cdecl helper(int);
extern "C" void __cdecl imported(const char*, float, float, float);

void __stdcall func_00a7e0a4(const char* text, float a, float b, float c)
{
    helper(1);
    imported(text, a, b, c);
}
