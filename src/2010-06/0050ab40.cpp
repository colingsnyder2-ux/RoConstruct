// from server: 70% by atomic.potato
extern "C" void* sub_004d1b00(void*);

struct S
{
    int f(int, int);
    void* sub_0079bdd0(double, int, int);
};

int S::f(int a, int b)
{
    void* p = sub_004d1b00(this);
    double v = *(float*)((char*)p + 0xd8);
    sub_0079bdd0(v, b, a);
    return b;
}
