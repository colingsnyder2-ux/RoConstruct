// from server: 67% by atomic.potato
struct S
{
    void f(int a, int b);
};

void S::f(int a, int b)
{
    *(int*)((char*)this + 0x0c) = 0;
    *(int*)((char*)this + 0x10) = 0;
    *(int*)((char*)this + 0x14) = a;
    *(double*)((char*)this + 0x18) = 0.0;
    *(int*)this = 0x00b76090;
    *(int*)((char*)this + 0x20) = b;
}
