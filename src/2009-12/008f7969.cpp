// from server: 59% by atomic.potato
extern "C" void __stdcall helper(int);

extern "C" void __cdecl target(char*, float, float, float);

void __stdcall func_008f7969(char* a, float b, float c, float d)
{
    helper(1);
    target(a, d, c, b);
}
