// from server: 65% by atomic.potato
extern "C" void G1_func_006073d0(void *, const char *);
extern "C" void G1_basic_string_ctor(void *, const char *);

struct S
{
    int f(const char *);
};

int S::f(const char *p)
{
    char buffer[28];
    G1_basic_string_ctor(buffer, "Gui:JoinCommand");
    G1_func_006073d0(this, p);
    *(int *)this = 0xA933D0;
    return (int)this;
}
