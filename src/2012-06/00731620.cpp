// from server: 63% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int sub_7311F0(void *, int);
extern "C" int sub_76A190(void *, int *);

int S::f(int value)
{
    int *v = reinterpret_cast<int *>(sub_7311F0(this, value + 4));
    return sub_76A190(this, v);
}
