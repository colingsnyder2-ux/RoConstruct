// from server: 56% by atomic.potato
extern "C" void G1_func_006073d0(void *);
extern "C" void G1_basic_string_ctor(void *, const char *);

struct S
{
    int f(const char *);
};

int S::f(const char *s)
{
    char local[28];
    G1_basic_string_ctor(local, "Gui:JoinCommand");
    G1_func_006073d0(this);
    *(void **)this = (void *)0xA933AC;
    return (int)this;
}
