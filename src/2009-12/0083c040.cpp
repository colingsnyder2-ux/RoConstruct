// from server: 100% by atomic.potato
struct S
{
    int padding[4];
    unsigned int field10;
    int f();
};

struct T
{
    unsigned char operator()(int, int);
};

int S::f()
{
    if (field10 >= 2 && ((T*)this)->operator()(6, 0))
        return 1;
    return 0;
}
