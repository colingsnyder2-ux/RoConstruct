// from server: 100% by tester
struct Inner {
    char pad[0x108];
    int field108;
};

struct Outer {
    char pad[0x168];
    Inner* field168;
};

extern "C" Outer* __cdecl sub_681050();

Outer* __cdecl sub_6813c0()
{
    Outer* p = sub_681050();
    if (p)
        return (Outer*)p->field168->field108;
    return 0;
}
