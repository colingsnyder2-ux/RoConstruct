// from server: 100% by atomic.potato
typedef char (__cdecl *Predicate)(int);

struct FixedCameraCommand
{
};

int * __cdecl find(int *first, int *last, Predicate predicate)
{
    while (first != last)
    {
        if (predicate(*first))
            break;
        ++first;
    }
    return first;
}
