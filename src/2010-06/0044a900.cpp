// from server: 74% by atomic.potato
struct S
{
    int f(int, int);
};

extern "C" int sub_449830(int, int*);

int S::f(int a, int b)
{
    int* p = *(int**)((char*)this + 0x1c);
    int* q = (int*)((char*)*p + 0x10);
    int t = sub_449830(b, &b);
    return ((int (__thiscall *)(int*, int, int))(*(int**)q))(p, a, t);
}
