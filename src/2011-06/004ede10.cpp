// from server: 79% by atomic.potato
struct Guid
{
    int value;
};

struct MatchGuidObject
{
    int MatchGuid(Guid *);
};

struct S
{
    Guid *f(Guid **, Guid *);
};

Guid *S::f(Guid **list, Guid *key)
{
    Guid *p = *list;
    while (p != 0)
    {
        if (((MatchGuidObject *)((char *)p - 328))->MatchGuid(key))
            break;
        p = *(Guid **)p;
    }
    return p;
}
