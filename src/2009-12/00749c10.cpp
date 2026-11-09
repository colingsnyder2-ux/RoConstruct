// from server: 33% by atomic.potato
struct EventDesc
{
    int f(float, float);
};

int EventDesc::f(float a, float b)
{
    int x = *(int *)((char *)this + 4);
    int y = *(int *)((char *)this + 8);
    int (*p)(int, float, float);
    p = *(int (**)(int, float, float))this;
    return p(x + y, b, a);
}
