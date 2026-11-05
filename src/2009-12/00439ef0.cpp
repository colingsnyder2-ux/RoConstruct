// from server: 74% by atomic.potato
struct S
{
    int v0;
    int v20;
    int v118;
    int f(const void*, const void*);
};

extern "C" void Call(S*, const void*, const void*);

int S::f(const void* a, const void* b)
{
    Call(this, a, b);
    v0 = 0x9a8104;
    v20 = 0x9a80a4;
    v118 = 0x9a809c;
    return (int)this;
}
