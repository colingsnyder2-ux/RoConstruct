// from server: 35% by atomic.potato
struct S
{
    void f(char const *s);
};

extern "C" void basic_string_copy(void *, char const *);
extern void *g_98b6f0;

void S::f(char const *s)
{
    char *p = (char *)this;
    basic_string_copy(p, s);
}
