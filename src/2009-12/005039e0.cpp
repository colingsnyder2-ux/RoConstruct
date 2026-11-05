// from server: 84% by atomic.potato
extern "C" int __stdcall sub_00500840(int*);

struct S
{
    int f(int, int);
};

int S::f(int a, int b)
{
    int* p = *(int**)((char*)this + 0x1c);
    int* q = (int*)(*p + 0x10);
    int t = sub_00500840(&b);
    return ((int (__thiscall*)(void*, int, int))*(int*)q)(p, a, t);
}
