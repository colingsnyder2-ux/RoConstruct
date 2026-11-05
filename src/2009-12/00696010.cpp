// from server: 45% by atomic.potato
struct S {
    int f(int);
};

int S::f(int value)
{
    *(unsigned char *)((char *)this + 520) = 1;
    return value;
}
