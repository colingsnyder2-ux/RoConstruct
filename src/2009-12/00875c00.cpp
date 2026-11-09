// from server: 49% by atomic.potato
struct S
{
    int a;
    int b;
    int c;
    int d;
    void f(int, int, int);
};

void S::f(int x, int y, int z)
{
    a = x;
    b = ((int*)y)[1];
    c = ((int*)y)[2];
    d = ((int*)y)[3];
    ((void (__thiscall *)(void*, int*, int))0x8e0e00)((void*)z, (int*)((char*)this + 0x48), *((int*)((char*)this + 0x6c)));
}
