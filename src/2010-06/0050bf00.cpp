// from server: 71% by atomic.potato
struct NetworkOwnerJob
{
    int __cdecl f(int *out);
};

extern "C" void __stdcall sub_4dcfa0(int *out, int a, int b, int c);
extern "C" void __stdcall sub_50be10(int *out);

int NetworkOwnerJob::f(int *out)
{
    *out = 0;
    sub_4dcfa0(out, 2, 1, (int)this);
    int v = *out;
    if (v < 1 || v > 3)
        sub_50be10(out);
    return v;
}
