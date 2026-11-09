// from server: 31% by atomic.potato
struct S
{
};

void __cdecl f(int, int value, int* result)
{
    if (value == 4)
    {
        result[0] = 0x00DCEC48;
        result[1] = 0;
    }
    else
    {
        f(0, value, result);
    }
}
