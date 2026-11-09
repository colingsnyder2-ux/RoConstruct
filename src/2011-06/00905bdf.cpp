// from server: 51% by atomic.potato
extern "C" void __cdecl sub_009092d5(int);

extern "C" void __cdecl imported_00C9B61C(float, const char*);

void __stdcall func_00905BDF(const char* a, float b)
{
    sub_009092d5(1);
    imported_00C9B61C(b, a);
}
