// from server: 91% by atomic.potato
struct Inner
{
    char pad[0x108];
    int field108;
};

struct Outer
{
    char pad[0x168];
    Inner* field168;
};

struct Result
{
    char pad[0x30];
    int field30;
};

extern "C" Outer* __cdecl sub_681050();

Result* __cdecl sub_6813e0()
{
    Outer* p = sub_681050();
    Result* r = 0;

    if (p)
        r = (Result*)p->field168->field108;

    if (r)
        return (Result*)r->field30;

    return 0;
}
