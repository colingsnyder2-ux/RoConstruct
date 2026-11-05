// from server: 30% by atomic.potato
struct S
{
    unsigned char value;
    void f();
};

void S::f()
{
    --value;
}
