// from server: 100% by colin
struct Descriptor {
    Descriptor(const char*, unsigned int);
};

struct VColor3Item : Descriptor {
    char pad[0x124 - 8];
    int field_0x11c;
    int field_0x120;
    int field_0x124;
    VColor3Item(const char*, unsigned int);
};

VColor3Item::VColor3Item(const char* name, unsigned int attrs)
    : Descriptor(name, attrs)
{
    field_0x124 = 0;
    field_0x120 = 0;
    field_0x11c = 0;
    *(int*)this = 0x78e784;
    *(int*)((char*)this + 0x20) = 0x78e724;
    *(int*)((char*)this + 0x100) = 0x78e71c;
}
