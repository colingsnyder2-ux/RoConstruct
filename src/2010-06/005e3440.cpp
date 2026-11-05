// from server: 64% by atomic.potato
extern "C" void std_string_ctor(const char *, const char *);

struct S
{
    void *vtable;
    void f(void *);
};

void S::f(void *p)
{
    char local[28];
    std_string_ctor((const char *)local, "Duplicate");
    f(p);
    vtable = (void *)0x00a2e48c;
}
