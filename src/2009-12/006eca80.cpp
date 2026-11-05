// from server: 100% by atomic.potato
struct Primitive
{
    int f(int);
};

int Primitive::f(int index)
{
    int *values = *(int **)((char *)this + 0xb4);
    return values[index];
}
