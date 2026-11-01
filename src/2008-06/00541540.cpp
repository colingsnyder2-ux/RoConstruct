// from server: 100% by king_originala
#pragma optimize("", off)

extern "C" void __cdecl helper(int *, unsigned, int, void *);

struct S {
    int *f(int *first, unsigned count, int value);
};

int *S::f(int *first, unsigned count, int value)
{
    helper(first, count, value, reinterpret_cast<char *>(this) + 8);
    return first + count;
}
