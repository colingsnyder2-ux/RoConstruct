// from server: 52% by atomic.potato
extern "C" int __cdecl GeometryLower(int);

struct S
{
    int f(int);
};

int S::f(int value)
{
    int result = 2;
    do
    {
        int lowered = GeometryLower(value);
        (void)lowered;
        result -= 1;
    }
    while (result != 0);
    return 0;
}
