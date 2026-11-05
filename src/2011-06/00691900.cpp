// from server: 81% by atomic.potato
struct S
{
    int f(void* p);
    int* a;
    int b;
};

int S::f(void* p)
{
    int* x = (int*)p;
    if (x)
        x = (int*)((char*)x - 0x1c);
    else
        x = 0;

    return *(int*)((char*)(((int**)x)[0x94 / 4][b]) + (int)a + (int)((char*)x + 0x94));
}
