// from server: 39% by atomic.potato
struct CXTPAccessible
{
    char pad[0x20];
    int field20;
    CXTPAccessible* sub_83c240(int);
    CXTPAccessible* f(int, int);
};

CXTPAccessible* CXTPAccessible::f(int, int a)
{
    CXTPAccessible* p = this;
    if (a == 0)
        return sub_83c240(0);
    return sub_83c240(field20);
}
