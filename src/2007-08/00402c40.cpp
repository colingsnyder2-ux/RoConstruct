// from server: 100% by colin
struct S {
    char pad[0x30];
    int value30;
};

int __stdcall f(S* s)
{
    s->value30 = s->value30 + 1;
    return s->value30;
}
