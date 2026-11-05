// from server: 89% by atomic.potato
struct S
{
    int value;
    int count;
    int capacity;
    int data;
    int f(int);
};

int S::f(int x)
{
    int n = (((int*)((char*)this + 0x48))[1] -
             ((int*)((char*)this + 0x48))[0]) >> 5;
    n += x;
    S* p = (S*)((char*)this + 0x44);
    p->f(n);
    return (p->capacity - p->count) >> 5;
}
