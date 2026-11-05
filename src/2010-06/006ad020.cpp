// from server: 77% by atomic.potato
struct S
{
    int value;
    int* base;

    void __thiscall f(int* out, int* p);
};

void __thiscall S::f(int* out, int* p)
{
    if (p != 0)
        *out = *(int*)((char*)p + (int)base - 0x1c);
    else
        *out = *(int*)((char*)this + 8);
}
