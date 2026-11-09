// from server: 50% by atomic.potato
struct S
{
    int* p8;
    int f(int);
};

int S::f(int a)
{
    if (a == 3)
        return *(int*)((char*)this + 36);

    int* p = (int*)*p8;
    return ((int (__thiscall*)(int*, int))(*(int**)p + 20))(p, a);
}
