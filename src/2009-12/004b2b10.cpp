// from server: 100% by atomic.potato
typedef void (__thiscall *DestroyString)(void *);

extern DestroyString g_destroyString;

struct S
{
    void f(char *first, char *last);
};

void S::f(char *first, char *last)
{
    while (first != last)
    {
        g_destroyString(first);
        first += 0x44;
    }
}
