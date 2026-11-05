// from server: 56% by atomic.potato
typedef unsigned int size_t;

struct S
{
    int f(const char *);
};

extern "C" void sub_5e3300(S *);

extern "C" void basic_string_ctor(void *, const char *);

int S::f(const char *a)
{
    char str[28];
    basic_string_ctor(str, "Copy");
    sub_5e3300(this);
    *(unsigned int *)this = 0x00a02f40;
    return (int)this;
}
