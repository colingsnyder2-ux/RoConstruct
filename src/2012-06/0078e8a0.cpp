// from server: 60% by atomic.potato
struct S
{
};

void __cdecl f(void *, void *result, int value)
{
    if (value != 4)
        return;

    *(int *)result = 0xdc1670;
    ((char *)result)[4] = 0;
    ((char *)result)[5] = 0;
}
