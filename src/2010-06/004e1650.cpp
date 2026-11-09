// from server: 100% by atomic.potato
typedef char Vec;
extern "C" void __cdecl sub_4e15b0(Vec *, Vec *);

Vec *sub_4e1650(Vec *a, Vec *b)
{
    sub_4e15b0(a, b);
    sub_4e15b0(a, b + 8);
    return a;
}
