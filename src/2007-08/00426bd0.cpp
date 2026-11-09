// from server: 23% by colin
// roc 2007-08 00426bd0  unit: RBX::Reflection::Metadata::Item  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00426bd0

extern "C" void* __cdecl malloc(unsigned int size);

struct Descriptor {
    Descriptor(const char* name, int attributes);
};

struct Item : Descriptor {
    const int value;
    const unsigned int index;
    const void* owner;
    Item(const char* name, int attributes, int value, unsigned int index, const void* owner);
};

Item::Item(const char* name, int attributes, int value, unsigned int index, const void* owner)
    : Descriptor(name, attributes), value(value), index(index), owner(owner)
{
}
