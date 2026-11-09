// from server: 32% by atomic.potato
int __cdecl f(int* result, int value)
{
    volatile int flags = 0;
    *result = value;
    flags |= 1;
    return *result;
}
