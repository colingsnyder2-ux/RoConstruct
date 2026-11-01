// from server: 100% by colin
struct Inner {
    char pad[0x64];
    int field_64;
};

struct Outer {
    char pad[0x1d8];
    Inner* field_1d8;
};

extern Outer* __cdecl getOuter();

int __cdecl getValue()
{
    Outer* o = getOuter();
    if (o)
        return o->field_1d8->field_64;
    return 0;
}
