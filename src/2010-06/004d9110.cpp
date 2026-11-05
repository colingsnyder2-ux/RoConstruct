// from server: 76% by atomic.potato
struct S
{
    int f(int, int);
};

struct T
{
    float value[65];
};

extern "C" T* get_data(S*);
extern "C" void update(S*, int, int, double);

int S::f(int a, int b)
{
    T* p = get_data(this);
    update(this, b, a, (double)p->value[64]);
    return b;
}
