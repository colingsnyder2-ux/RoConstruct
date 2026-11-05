// from server: 63% by atomic.potato
struct S533750Result
{
    int value[3];
};

extern "C" void __cdecl sub_533750(void *, S533750Result *);
extern "C" void __cdecl sub_53a1e0(S533750Result *);

void __cdecl sub_53b930(void *a, void *b)
{
    S533750Result result;
    sub_533750(b, &result);
    if (*((int *)b + 1) != 0)
        sub_53a1e0(&result);
}
