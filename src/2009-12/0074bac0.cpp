// from server: 70% by atomic.potato
struct S
{
    int f(int);
    int *vtable;
    int *object;
};

extern "C" int __stdcall sub_6a3a20(int, int);

int S::f(int value)
{
    int result;
    int *p = *(int **)((char *)this + 0x1c);
    result = ((int (__thiscall *)(int *, int *))(*(int ***)p)[3])(p, &value);
    return sub_6a3a20(result, value);
}
