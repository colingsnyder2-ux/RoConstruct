// from server: 4% by colin
struct EnumDescriptor;

struct Descriptor {
    int dummy;
};

struct Item : Descriptor {
    const EnumDescriptor& owner;
    const int value;
    const unsigned int index;
};

struct EnumDescriptor {
    char pad[0x104];
    int allItems_begin;
    int allItems_end;
    int allItems_cap;
    unsigned int enumCount;
    unsigned int enumCountMSB;

    bool convertToValue(unsigned int index, void* value) const;
    bool convertToString(unsigned int index, void* value) const;
    void addLegacyName(const char* name, int value);
    void addLegacy(int value, const char* name);
};

extern "C" void __stdcall _invalid_parameter_noinfo(void);
extern "C" void* __stdcall sub_77DDB8(void*, const char*);

void EnumDescriptor::addLegacyName(const char* name, int value)
{
    void* p = sub_77DDB8(0, name);
    (void)p;
}
