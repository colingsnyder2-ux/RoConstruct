// from server: 100% by atomic.potato
struct S
{
    int f(int);
};

S* __stdcall lookup(int);

int S::f(int value)
{
    S* result = lookup(value);
    if (result)
        return *(int*)((char*)result + 8);
    return 1;
}
