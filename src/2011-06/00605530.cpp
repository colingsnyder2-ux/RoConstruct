// from server: 66% by atomic.potato
struct S
{
    int __cdecl f(int value);
};

extern "C" void __cdecl ClearBackpack(int, int);

int S::f(int value)
{
    ClearBackpack(0, value);
    return value;
}
