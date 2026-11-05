// from server: 100% by tajop
struct type_info {
    __declspec(dllimport) bool operator==(const type_info&) const;
};

extern type_info type_info_0xdeb9d8;
extern "C" type_info* __cdecl sub_00983B6A(void*);

struct Target {
    void* sub_00495F40();
};

struct Owner {
    char pad[0xac4];
    Target* target;
};

struct TToolVerb
{
    int pad0;
    int pad1;
    int pad2;
    Owner* owner;
    bool f();
};

bool TToolVerb::f()
{
    void* value = owner->target->sub_00495F40();
    if (value)
        return type_info_0xdeb9d8 == *sub_00983B6A(value);
    return false;
}
