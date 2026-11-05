// from server: 36% by atomic.potato
extern "C" void __cdecl sub_00523480();
extern "C" void __cdecl sub_007467C0();
extern "C" void __cdecl sub_00746A70();
extern "C" void __cdecl sub_00746B00();
extern "C" void __cdecl sub_00783BD0();
extern "C" void __cdecl sub_00972D70();
extern "C" void __cdecl sub_00983144();
extern "C" void __cdecl sub_00B2263C();

struct S
{
    void f();
};

void S::f()
{
    char *p = (char *)this;
    char *esi = p + 4;
    void *ebx = *(void **)0x00B229EC;

    if (esi != 0)
    {
        void *eax = *(void **)esi;
        void *ecx;
        if (eax != 0)
            ecx = *(void **)eax;
        else
            ecx = (void *)0x00D60AC8;

        if (ecx != (void *)0x00DB4AF8)
        {
            if (eax != 0)
                eax = *(void **)eax;
            else
                eax = (void *)0x00D60AC8;

            typedef char (__fastcall *Fn)(void *, void *);
            Fn fn = (Fn)ebx;
            if (fn(eax, (void *)0x00DB4AF8) == 0)
                goto Lbf2;
        }

        if (esi + 4 != 0)
            goto Lc5f;
    }

Lbf2:
    {
        void *eax = *(void **)p;
        eax = *(void **)((char *)eax + 0x10);
        if (eax != (void *)0x00D60B50)
        {
            typedef char (__fastcall *Fn)(void *, void *);
            Fn fn = (Fn)ebx;
            if (fn((void *)0x00D60B50, eax) == 0)
                goto Lc71;
        }

        char buf[0x48];
        sub_00523480();
        sub_007467C0();
        *(int *)(buf + 0x4C) = -1;
        sub_00B2263C();
        if (*(char *)&buf[0] == 0)
            goto Lc71;

        sub_00746A70();
        sub_00783BD0();
        *(void **)p = (void *)0;
        sub_00746B00();
    }

Lc5f:
    return;

Lc71:
    sub_00783BD0();
    {
        char *eax = (char *)0;
        eax = *(char **)(eax + 0x14);
        eax += 4;
        char *ecx;
        if (*(unsigned int *)(eax + 0x18) < 0x10)
            ecx = eax + 4;
        else
            ecx = *(char **)(eax + 4);

        char *eax2 = *(char **)p;
        eax2 = *(char **)(eax2 + 0x14);
        eax2 += 4;
        char *eax3;
        if (*(unsigned int *)(eax2 + 0x18) < 0x10)
            eax3 = eax2 + 4;
        else
            eax3 = *(char **)(eax2 + 4);

        sub_00972D70();
        sub_00983144();
    }
}
