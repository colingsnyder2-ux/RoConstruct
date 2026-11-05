// from server: 58% by atomic.potato
extern "C" int __stdcall sub_754A90(int *);

struct S {
    int *vtable;
    int pad[9];
    int *data;
    int f(int, int);
};

int S::f(int a, int b)
{
    int *p = data;
    int *q = p + 3;
    int t = sub_754A90(&b);
    return ((int (__thiscall *)(int *, int, int))q[0])(p, a, t);
}
