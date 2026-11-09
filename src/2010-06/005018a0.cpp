// from server: 93% by atomic.potato
struct S_func_005018a0
{
    int __cdecl f(int* a1, S_func_005018a0* a2);
};

int __cdecl S_func_005018a0::f(int* a1, S_func_005018a0* a2)
{
    int value = *a1;
    int limit = *((int*)*(int**)a2 + 9);
    if ((unsigned int)value < (unsigned int)limit)
        return -1;
    return value != limit;
}
