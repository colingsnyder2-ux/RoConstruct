// from server: 100% by Yeetserama
// hypothesis: 00552070 is the same boost stream-buffer area initializer as
// exact 0054c3c0, with the cached position at 0x50 instead of 0x4c.
// Two separate reads of the same field produce the target's "mov edx,eax;
// sub edx,eax" zero idiom.
struct S_func_00552070 {
    char pad0[0x10];
    int* p10;
    char pad1[0x0c];
    int* p20;
    char pad2[0x0c];
    int* p30;
    char pad3[0x1c];
    int value50;
};

void __fastcall f(S_func_00552070* s)
{
    int a = s->value50;
    int b = s->value50;
    *s->p10 = a;
    *s->p20 = a;
    *s->p30 = a - b;
}
