// from server: 100% by atomic.potato
struct S
{
    int a[38];
    void f();
};

extern "C" void S_continuation();

void S::f()
{
    a[0] = 0x00a45474;
    a[1] = 0x00a4546c;
    a[6] = 0x00a45460;
    a[7] = 0x00a45454;
    a[37] = 0x00a4544c;
    S_continuation();
}
