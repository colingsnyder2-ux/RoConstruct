// from server: 100% by king_originala
struct Link;

struct Primitive
{
    Link *first();
    Link *next(Link *);
};

struct Link
{
    char padding[0x0c];
    Primitive *a;
    Primitive *b;
};

struct S
{
    char padding[0x1e8];
    unsigned char flags;

    char *getA();
    char *getB();
    void reset(float);
    void f();
};

void S::f()
{
    char *a = getA();
    if (a)
    {
        Primitive *first = (Primitive *)(a + 0x228);
        if (first)
        {
            char *b = getB();
            if (b)
            {
                Primitive *second = (Primitive *)(b + 0x228);
                if (second)
                {
                    Link *link = first->first();
                    while (link)
                    {
                        Primitive *other = link->a;
                        if (first == other)
                            other = link->b;
                        if (other == second)
                        {
                            flags |= 4;
                            return;
                        }
                        link = first->next(link);
                    }
                }
            }
        }
    }

    if (flags & 4)
        reset(0.0f);
}
