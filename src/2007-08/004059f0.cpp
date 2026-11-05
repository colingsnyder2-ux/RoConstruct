// from server: 100% by colin
struct S {
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
};

int __stdcall copyField(S* s)
{
    s->m10 = s->m8;
    return 0;
}
