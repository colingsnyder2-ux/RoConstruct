// from server: 45% by atomic.potato
struct Inner
{
    virtual void g0();
    virtual void g1();
    virtual int g2();
};

struct S
{
    char pad0[0x38];
    char (__thiscall *fn38)(int);
    int off3c;
    int off40;
    int off44;
    Inner *off48;
    void method(int, int);
};

extern "C" void *__stdcall sub_7A8BEA(int, int, int, int, int);
extern "C" void __stdcall sub_7A89B2(void *, void *);
extern "C" void *__stdcall sub_9EA89C();
extern "C" void __stdcall sub_409CC0(void *, void *);
extern "C" void *__stdcall sub_66E380(void *);

void S::method(int a, int b)
{
    int local0;
    int local4;
    int local8;
    int localC;
    int local10;
    int local14;
    int local18;
    int local1C;

    local0 = off44;
    if (off48)
        local4 = off48->g2();
    else
        local4 = 0;

    int *p = (int *)a;
    int (__thiscall *fn)(void *, int *, int) = (int (__thiscall *)(void *, int *, int))p[1];
    local18 = 0;
    fn(p, &local0, 1);

    void *r = sub_7A8BEA(local18, 0, (int)0xB79040, (int)0xB87D34, 0);
    if (!r)
    {
        sub_9EA89C();
        sub_7A89B2(&local0, (void *)0xB12290);
    }

    int *q = (int *)sub_66E380(&local0);
    int v = *(int *)((char *)r + 0x148);
    int idx = off40;
    int edx = *(int *)(v + idx);
    edx += off3c;
    char (__thiscall *eax)(int) = fn38;
    int ecx = edx + (int)r + 0x148;
    char res = eax(ecx);

    char tmp;
    sub_409CC0((char *)a + 4, &tmp);
    tmp = res;

    if (local4)
    {
        int *vt = (int *)local4;
        int (__thiscall *fn2)(void *, int) = (int (__thiscall *)(void *, int))vt[0];
        fn2((void *)local4, 1);
    }
}
