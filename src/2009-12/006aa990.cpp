// from server: 87% by atomic.potato
struct S
{
    struct V
    {
        float x;
        float y;
        float z;
    };

    void f(V *result);
};

void S::f(V *result)
{
    result->x = *(float *)((char *)this + 0xec);
    result->y = *(float *)((char *)this + 0xf0);
    result->z = *(float *)((char *)this + 0xf4);
}
