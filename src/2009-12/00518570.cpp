// from server: 53% by atomic.potato
struct S;

extern "C" void sub_516a40(S *, int, int);

struct S
{
};

void __cdecl f(S *p)
{
    int a = *reinterpret_cast<int *>(p);
    char b = 0;
    sub_516a40(reinterpret_cast<S *>(a + 8), b, 0);
}
