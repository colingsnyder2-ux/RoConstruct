// from server: 67% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    ((int*)this)[0] = 0;
    ((int*)this)[1] = -1;
    ((int*)this)[2] = 0;
    ((int*)this)[3] = 0;
    ((int*)this)[4] = 0;
    ((int*)this)[5] = 0;
    ((int*)this)[6] = 0;
    ((int*)this)[7] = 0;
    return 0;
}
