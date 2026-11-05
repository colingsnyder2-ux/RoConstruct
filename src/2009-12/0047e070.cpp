// from server: 93% by atomic.potato
struct S
{
    int pad0;
    int object;
    int pad1;
    int count;
    void f(int a, int b, int c);
};

void S::f(int a, int b, int c)
{
    int* p = *(int**)(object);
    ((void (__thiscall *)(int, int, int))p[0x4f])(object, b, c);
    count += 3;
}
