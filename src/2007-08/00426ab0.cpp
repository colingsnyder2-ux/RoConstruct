// from server: 34% by colin
// roc 2007-08 00426ab0  unit: RBX::Reflection::Metadata::Item  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00426ab0

extern "C" void* __cdecl malloc(unsigned int size);

struct Descriptor {
    Descriptor(const char* name, int attributes);
};

struct EnumDescriptor;

struct Item : Descriptor {
    const EnumDescriptor& owner;
    const int value;
    const unsigned int index;
    Item(const char* name, int attributes, int value, unsigned int index, const EnumDescriptor& owner);
};

struct EnumDescriptor {
    void addItem(const Item* item, int value) const;
};

Item::Item(const char* name, int attributes, int value, unsigned int index, const EnumDescriptor& owner)
    : Descriptor(name, attributes)
    , owner(owner)
    , value(value)
    , index(index)
{
    Item* p = (Item*)malloc(0xe8);
    if (p) {
        p->Item::Item(name, attributes, value, index, owner);
    }
    this->owner.addItem(p, value);
}
