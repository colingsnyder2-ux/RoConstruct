// from server: 63% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    *(int*)this = 0xA53C5C;
    *((int*)this + 2) = 0;
    *((int*)this + 3) = 0;
    *((int*)this + 1) = 0;
    *((int*)this + 4) = 0;
    return 0;
}
