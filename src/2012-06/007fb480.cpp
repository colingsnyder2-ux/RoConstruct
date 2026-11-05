// from server: 60% by atomic.potato
extern "C" void __cdecl call_4015a0(const char *, const char *, int);
extern "C" void __cdecl call_9831f5(const char *);

extern int global_e4f478;
extern int global_e4f47c;
extern char global_e4f480;

struct S
{
    S();
};

S::S()
{
    int unused;
    int *p = &unused;

    *(int *)this = 0;

    call_4015a0("tUVW", "8csm", 0);

    if (!global_e4f480)
    {
        global_e4f480 |= 1;
        global_e4f478 = 0;
        global_e4f47c = 0;
        call_9831f5("8csm");
    }
}
