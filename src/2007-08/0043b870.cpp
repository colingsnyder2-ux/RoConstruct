// from server: 1% by colin
struct EnumDescriptor;

struct Item {
    const EnumDescriptor& owner;
    const int value;
    const unsigned int index;
};

struct EnumDescriptor {
    char pad[0x114 - 0x10];
    void* allItemsBegin;
    void* allItemsEnd;
    void* allItemsCap;
    unsigned int enumCount;
    unsigned int enumCountMSB;

    bool convertToValue(unsigned int index, void* value) const;
    bool convertToString(unsigned int index, void* value) const;
    void addItem(const Item* item);
    void throwListTooLong();
};

struct EnumDesc : public EnumDescriptor {
    void addLegacy(const char* name, int value);
};

struct Descriptor {
    void* vtable;
    void* name;
    void* attributes;
};

struct ItemImpl : public Descriptor {
    const EnumDescriptor& owner;
    const int value;
    const unsigned int index;
};

extern "C" void __stdcall _invalid_parameter_noinfo();

void EnumDescriptor::throwListTooLong() {
    _invalid_parameter_noinfo();
}
