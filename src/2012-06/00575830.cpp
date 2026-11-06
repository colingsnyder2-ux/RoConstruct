// from server: 100% by tajop
struct Deleter
{
    union
    {
        int v;
        char c;
    };
};

struct Payload
{
    Payload();
    char pad[0xbc];
};

struct Holder
{
    Holder(Payload* p, Deleter d);
    void* px;
    void* pn;
};

Holder makeHolder()
{
    Deleter d;
    d.v = 0;
    d.c = 0;
    return Holder(new Payload(), d);
}
