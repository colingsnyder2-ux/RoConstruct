// from server: 33% by colin
struct Descriptor {
    Descriptor(const char*, unsigned int);
};

struct EnumDescriptor;

struct Item : Descriptor {
    const EnumDescriptor& owner;
    const int value;
    const unsigned int index;
    Item(const char*, unsigned int, int, unsigned int, const EnumDescriptor&);
};

extern "C" void* __cdecl malloc(unsigned int);

struct EnumDescriptor {
    void constructItems(int, Item*);
};

Item::Item(const char* name, unsigned int attributes, int v, unsigned int idx, const EnumDescriptor& own)
    : Descriptor(name, attributes), owner(own), value(v), index(idx)
{
    Item* items = (Item*)malloc(0xe8);
    if (items) {
        items->Item::Item(0, 0, 0, 0, own);
    }
    const_cast<EnumDescriptor&>(this->owner).constructItems(0, items);
}
