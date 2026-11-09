// from server: 100% by atomic.potato
struct S
{
};

struct T
{
    int value[37];
};

int __cdecl Get(int value)
{
    T *result = (T *)0;
    result = (T *)Get(value);
    if (result != 0)
        return result->value[37];
    return 0;
}
