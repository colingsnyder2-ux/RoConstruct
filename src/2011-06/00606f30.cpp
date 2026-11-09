// from server: 65% by atomic.potato
extern "C" void G1_func_00606b80(void *, void *);
extern "C" void G1_basic_string_ctor(void *, const char *);

struct S
{
    int f(void *);
};

int S::f(void *arg)
{
    char local[28];
    G1_basic_string_ctor(local, "SelectionDown");
    G1_func_00606b80(this, local);
    *(int *)this = 0xA93348;
    return (int)this;
}
