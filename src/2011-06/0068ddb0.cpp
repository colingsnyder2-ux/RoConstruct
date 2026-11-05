// from server: 65% by atomic.potato
extern "C" int G1_func_0068dce0(int, int*);

struct S
{
    int f(int, int);
};

int S::f(int a, int b)
{
    int* p = *(int**)((char*)this + 0x1c);
    int* v = (int*)*p + 3;
    int x;
    int y = G1_func_0068dce0(b, &x);
    return ((int (__fastcall *)(int*, int, int))(*v))(p, a, y);
}
