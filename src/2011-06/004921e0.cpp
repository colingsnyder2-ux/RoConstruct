// from server: 89% by atomic.potato
struct S
{
    char f(int);
};

char S::f(int value)
{
    int* p = *(int**)((char*)this + 0xf0);
    unsigned char same;
    if (p)
    {
        int (**vtable)(int*) = *(int (***)(int*))p;
        (*vtable[1])(p);
    }
    same = p == (int*)value;
    if (p)
    {
        int (**vtable)(int*) = *(int (***)(int*))p;
        (*vtable[2])(p);
    }
    return same;
}
