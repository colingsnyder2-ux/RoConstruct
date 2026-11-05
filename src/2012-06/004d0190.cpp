// from server: 82% by atomic.potato
extern "C" void destroy_string(char *);

struct S
{
    void f(char *, char *);
};

void S::f(char *first, char *last)
{
    while (first != last)
    {
        destroy_string(first);
        first += 0x20;
    }
}
