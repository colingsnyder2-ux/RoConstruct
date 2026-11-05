// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int* p = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 4);
    int value = *p;
    if (value == 0 || value == reinterpret_cast<int>(p))
        return 1;
    return 0;
}
