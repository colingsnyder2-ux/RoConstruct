// from server: 38% by atomic.potato
struct S
{
    void f(int);
};

void S::f(int value)
{
    *(int *)this = value;
    *((char *)this + 4) = 1;
    *(float *)((char *)this + 8) = 0.0f;
    *(float *)((char *)this + 12) = 0.0f;
    *(float *)((char *)this + 16) = 0.0f;
}
