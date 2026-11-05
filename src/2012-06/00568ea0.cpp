// from server: 26% by atomic.potato
struct S
{
    unsigned short a;
    unsigned short b;
    int c;
    S* p;
    int f(S* other);
};

struct T
{
    S* p;
    S* find(S* other);
};

int S::f(S* other)
{
    if (b == other->b && a == 2 && c == other->c)
        return 1;
    return 0;
}

S* T::find(S* other)
{
    S* p = this->p;
    if (p != 0)
    {
        do
        {
            S* current = (S*)((char*)p - 0x168);
            if (other->f(current))
                return p;
            p = p->p;
        } while (p != 0);
    }
    return p;
}
