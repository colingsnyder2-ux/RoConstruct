// from server: 100% by king_originala
struct Descriptor {
    bool __thiscall differs(const Descriptor&) const;
};

const Descriptor& __cdecl getDescriptor();

struct Item {
    unsigned char padding[12];
    Descriptor* descriptor;
};

struct CSettingsPropGrid {
    void __thiscall apply(int, Item*);
    void __thiscall f(int, Item*);
};

void CSettingsPropGrid::f(int value, Item* item)
{
    if (item->descriptor->differs(getDescriptor()))
        apply(value, item);
}
