// from server: 100% by atomic.potato
struct S
{
    void f();
};

void g();

void S::f()
{
    *(int*)this = 0x9d6f4c;
    *((int*)this + 1) = 0x9d6f40;
    *((int*)this + 6) = 0x9d6f34;
    *((int*)this + 7) = 0x9d6f2c;
    g();
}
