// from server: 86% by atomic.potato
extern "C" void __cdecl sub_7629A0(void *, void *);
extern "C" void __cdecl sub_762DF0(void *, void *, void *);

void f(void *a, void *b, int c)
{
    sub_7629A0(b, (void *)0x00A945A0);
    sub_762DF0(b, (void *)0x00A94594, (void *)(c - 1));
}
