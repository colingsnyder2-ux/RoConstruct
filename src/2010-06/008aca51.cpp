// from server: 47% by atomic.potato
extern "C" void __cdecl sub_008af41a(int);

extern "C" void __stdcall imported_call(float, const char*, const char*);

void __stdcall func_008aca51(const char* a, const char* b, float c)
{
    sub_008af41a(1);
    imported_call(c, b, a);
}
