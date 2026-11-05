// from server: 59% by atomic.potato
struct S {
    int f(int* p);
};

int S::f(int* p)
{
    int* q = *(int**)((char*)p + 4);
    return ((int (__thiscall *)(int*))(*(int**)q))(q);
}
