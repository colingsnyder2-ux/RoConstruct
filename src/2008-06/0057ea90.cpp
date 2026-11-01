// from server: 100% by king_originala
struct S;

struct Shared
{
    S* px;
    void* pn;
    ~Shared();
};

struct Owner
{
    char padding[16];
    Shared* end;
};

struct Iterator
{
    Owner** owner;
    Shared* position;
};

extern "C" void (__cdecl *invalid_parameter_noinfo)();
Shared __cdecl makeShared();

struct S
{
    void setParent(S*);
    Shared f(Iterator first, Iterator last);
};

Shared S::f(Iterator first, Iterator last)
{
    Shared result = makeShared();
    result.px->setParent(this);

    void (__cdecl *invalid)() = invalid_parameter_noinfo;

    for (;;)
    {
        if (!first.owner || first.owner != last.owner)
            invalid();

        if (first.position == last.position)
            break;

        S* parent = result.px;

        if (!first.owner)
            invalid();

        Owner* owner = first.owner ? *first.owner : 0;
        if (first.position >= owner->end)
            invalid();

        first.position->px->setParent(parent);

        if (!first.owner)
            invalid();

        owner = first.owner ? *first.owner : 0;
        if (first.position >= owner->end)
            invalid();

        ++first.position;
    }

    return result;
}
