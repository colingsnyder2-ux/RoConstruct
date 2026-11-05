// from server: 73% by atomic.potato
struct S
{
    int value;
    int offset;
    void f(int* out, int* base);
};

void __thiscall S::f(int* out, int* base)
{
    if (base != 0)
        *out = *(int*)((char*)base + offset - 0x1c);
    else
        *out = *(int*)offset;
}
