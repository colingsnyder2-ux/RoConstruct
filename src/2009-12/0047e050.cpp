// from server: 59% by atomic.potato
struct S
{
    void f(int&);
};

void S::f(int& a)
{
    int* p = *(int**)((char*)this + 4);
    a += *(int*)((char*)this + 12);
    ((void (__thiscall *)(int*, int&))(*(int**)(*p + 240)))(p, a);
}
