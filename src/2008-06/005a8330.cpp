// from server: 100% by king_originala
struct S
{
    int first;
    int second;
};

extern "C" int __cdecl compare(int, int);

int __cdecl f(const S* a, const S* b)
{
    int x = a ? a->first : 0;
    int y = b ? b->first : 0;

    switch (compare(x, y))
    {
    case -1:
        return -1;

    case 0:
        x = a ? a->second : 0;
        y = b ? b->second : 0;
        if (x > y)
            return 1;
        return x < y ? -1 : 0;

    case 1:
        return 1;

    default:
        return 0;
    }
}
