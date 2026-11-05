// from server: 100% by atomic.potato
struct S
{
    void f(double value);
};

void S::f(double value)
{
    double temp = value;
    *(int *)((char *)this + 0x1ef8) = ((int *)&temp)[0];
    *(int *)((char *)this + 0x1efc) = ((int *)&temp)[1];
}
