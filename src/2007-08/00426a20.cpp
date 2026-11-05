// from server: 41% by colin
struct Descriptor {
    Descriptor(const char*, unsigned int);
};

struct Item : Descriptor {
    const void* owner;
    const int value;
    const unsigned int index;
    Item(const char* name, unsigned int attributes, int value, unsigned int index, const void* owner);
};

extern "C" void* __cdecl malloc(unsigned int);

void* __fastcall sub_426670(void* self);
void __fastcall sub_424870(Item* self, void* a, void* b);

Item::Item(const char* name, unsigned int attributes, int value, unsigned int index, const void* owner)
    : Descriptor(name, attributes), owner(owner), value(value), index(index)
{
    void* mem = malloc(0xe8);
    void* obj = 0;
    if (mem) {
        obj = sub_426670(mem);
    }
    sub_424870(this, obj, 0);
}
