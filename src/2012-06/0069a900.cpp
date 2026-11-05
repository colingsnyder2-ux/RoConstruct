// from server: 73% by atomic.potato
struct S
{
    int pad[32];
    void f(int);
};

extern "C" void __declspec(noreturn) helper(S *, int, int);

void S::f(int v)
{
    if (pad[32] == v)
        return;
    pad[32] = v;
    helper(this, 0xE2D134, 0);
}
