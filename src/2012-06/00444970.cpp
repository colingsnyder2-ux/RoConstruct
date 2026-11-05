// from server: 89% by atomic.potato
extern "C" void basic_ifstream_destructor(void *);
extern "C" void __cdecl operator_delete(void *);

struct S
{
    int f(unsigned char);
};

int S::f(unsigned char flags)
{
    char *p = reinterpret_cast<char *>(this) - 88;
    basic_ifstream_destructor(p);
    if (flags & 1)
        operator_delete(p);
    return reinterpret_cast<int>(p);
}
