// from server: 49% by atomic.potato
extern "C" void std_string_copy(void *, const void *);
extern "C" void indirect_call(void *, unsigned int);

struct S
{
    void *vtable;
    char data[12];
    char value[16];

    S(const S &);
};

S::S(const S &other)
{
    void *p = *(void **)this;
    void (*f)(void *, unsigned int) =
        (void (*)(void *, unsigned int))(*(unsigned int *)((char *)p + 0x14));
    f(this, 0);
    std_string_copy((void *)((char *)this + 0xc), (const void *)other.value);
}
