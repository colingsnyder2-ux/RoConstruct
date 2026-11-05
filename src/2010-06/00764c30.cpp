// from server: 60% by atomic.potato
struct S
{
    int f(float value);
};

int S::f(float value)
{
    *(int *)this = 0xA52414;
    *(float *)((char *)this + 4) = value;
    return 0;
}
