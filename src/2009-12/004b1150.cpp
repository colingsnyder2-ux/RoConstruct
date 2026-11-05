// from server: 83% by atomic.potato
extern "C" void __cdecl sym(char *);

struct S_func_004b1150
{
    void f(char *, char *);
};

void S_func_004b1150::f(char *begin, char *end)
{
    while (begin != end)
    {
        sym(begin);
        begin += 0x40;
    }
}
