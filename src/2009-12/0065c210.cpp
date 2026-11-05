// from server: 100% by atomic.potato
struct S
{
    int f();
};

S* g();

int S::f()
{
    *(int*)this = 0x9cdcb4;
    *((int*)this + 1) = 0x9cdcac;
    *((int*)this + 6) = 0x9cdca0;
    *((int*)this + 7) = 0x9cdc98;
    return (int)g();
}
