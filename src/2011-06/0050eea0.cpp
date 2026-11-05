// from server: 56% by atomic.potato
extern "C" char *__stdcall gethostbyname(char *);
extern "C" char *__stdcall inet_ntoa(unsigned long);

struct S_func_0050eea0
{
    int f(char *);
};

int S_func_0050eea0::f(char *arg)
{
    char *p = gethostbyname(arg);
    if (p != 0)
    {
        unsigned long **q = (unsigned long **)(p + 12);
        if (*q != 0)
            return (int)inet_ntoa(**q);
    }
    return 0;
}
