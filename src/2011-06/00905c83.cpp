// from server: 47% by atomic.potato
extern "C" void __stdcall G1_func_009092d5(int);

extern "C" void __stdcall G2_func(const char *, const char *, float);

void __stdcall G1_func_00905c83(const char *a, const char *b, float c)
{
    G1_func_009092d5(1);
    G2_func(a, b, c);
}
