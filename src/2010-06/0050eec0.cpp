// from server: 57% by atomic.potato
struct S
{
    int f(int value);
};

extern "C" void __cdecl G1_func_004d97c0(int *, int);
extern "C" int G1_func_0050eb10(S *);

int S::f(int value)
{
    int local;
    G1_func_004d97c0(&local, value);
    return G1_func_0050eb10(this);
}
