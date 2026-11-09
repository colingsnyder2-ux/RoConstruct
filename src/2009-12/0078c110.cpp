// from server: 75% by atomic.potato
extern "C" void __cdecl _invalid_parameter_noinfo();

struct S
{
    int* p;
    int f(int* out);
};

int S::f(int* out)
{
    int* a = p;
    int b = *(int*)((char*)a + 0x80);
    a = (int*)((char*)a + 0x70);
    if (*(int*)((char*)a + 0x0c) <= b)
        _invalid_parameter_noinfo();
    *out = (int)this;
    out[1] = *a;
    out[2] = b;
    return 0;
}
