// from server: 100% by atomic.potato
struct S {
    unsigned char pad[4];
    unsigned char value;
    void f();
};

void S::f()
{
    if (value)
        value = 0;
}
