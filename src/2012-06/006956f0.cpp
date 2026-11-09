// from server: 79% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int G1_func_006952a0(int);
extern "C" int G2_func_0076a190(S *, int *);

int S::f(int value)
{
    int local;
    local = *reinterpret_cast<int *>(G1_func_006952a0(value + 4));
    return G2_func_0076a190(this, &local);
}
