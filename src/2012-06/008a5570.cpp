// from server: 70% by atomic.potato
struct S
{
    int f(const char *p);
    char data[0xa4];
};

extern "C" void __stdcall string_copy(void *, const void *);

int S::f(const char *p)
{
    string_copy(data + 0xa4, p);
    return (int)p;
}
