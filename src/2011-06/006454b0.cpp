// from server: 100% by atomic.potato
struct S
{
    void f();
    void g();
    void* pad[78];
};

void S::f()
{
    g();
    *(int*)((char*)pad[78] + 0x40) = 0;
}
