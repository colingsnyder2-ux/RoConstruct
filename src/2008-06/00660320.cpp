// from server: 100% by king_originala
struct Owner
{
    bool contains(Owner* other);
};

struct PartInstance
{
    char padding[0x104];
    Owner* owner;
    bool excluded();
};

struct GetSetImpl
{
    static PartInstance* get(PartInstance* p);
};

struct FilterStairs
{
    int reserved;
    Owner* owner;
    int filter(PartInstance* p);
};

int FilterStairs::filter(PartInstance* p)
{
    if (owner != 0)
    {
        PartInstance* part = GetSetImpl::get(p);
        if (owner == part->owner ||
            (part->owner != 0 && part->owner->contains(owner)) ||
            !part->excluded())
            return 1;
    }
    return 2;
}
