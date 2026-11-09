// from server: 69% by atomic.potato
struct S_func_00553980 {
    int __cdecl f(unsigned short* a);
    struct Inner {
        unsigned short value;
    };
    Inner* member;
};

int S_func_00553980::f(unsigned short* a)
{
    unsigned short limit = member->value;
    unsigned short value = *a;
    if (value < limit)
        return -1;
    return value != limit;
}
