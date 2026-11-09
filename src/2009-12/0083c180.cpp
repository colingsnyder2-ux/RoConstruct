// from server: 50% by atomic.potato
struct CXTPAccessible
{
    char pad[0x20];
    int field20;
    CXTPAccessible* sub_83c140(int, int);
    CXTPAccessible* f(int, int);
};

CXTPAccessible* CXTPAccessible::f(int a, int b)
{
    if (b != 0)
        return sub_83c140(a, b);
    return sub_83c140(a, field20);
}
