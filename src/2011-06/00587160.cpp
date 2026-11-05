// from server: 35% by atomic.potato
struct S
{
    double f();
};

extern "C" void helper(void *, int, void *);

double S::f()
{
    double value;
    helper((char *)this + 0x218, -1, &value);
    return *(double *)((char *)&value + 8);
}
