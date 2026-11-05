// from server: 87% by atomic.potato
extern "C" int G1_func_00794240(void *, int);

struct S
{
    int value;
    int f(int);
};

int S::f(int arg)
{
    return !!(G1_func_00794240(this, arg) & value);
}
