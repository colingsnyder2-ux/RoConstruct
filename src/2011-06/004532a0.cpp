// from server: 35% by atomic.potato
struct S
{
    int f(void*, void*);
};

int S::f(void* a, void* b)
{
    int* p = (int*)b;
    int* q = 0;

    if ((void*)p != (void*)((char*)this + 0x2eb0470))
    {
        q = (int*)*p;
        *p = 0;
    }

    if (q != 0)
    {
        int* v = (int*)*q;
        ((void (__thiscall *)(int*, int))(*(int**)v))(v, 1);
    }

    return (int)(unsigned char)*(char*)this;
}
