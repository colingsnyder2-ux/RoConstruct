// from server: 17% by atomic.potato
struct S
{
    void f(const char *value);
};

void S::f(const char *value)
{
    if (value != 0 && value[0] != 0)
    {
        char *p = const_cast<char *>(value);
        (void)p;
    }
}
