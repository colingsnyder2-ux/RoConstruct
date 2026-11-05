// from server: 15% by colin
struct RBXName;

struct EnumDescriptor;

struct Item {
    const char* name;
    int attributes;
    const EnumDescriptor* owner;
    int value;
    unsigned int index;
};

struct EnumDescriptor {
    char pad0[0x100];
    void* vtable;
    char pad1[0x4];
    Item** itemsBegin;
    Item** itemsEnd;
    Item** itemsCap;
    unsigned int enumCount;
    unsigned int enumCountMSB;
    char pad2[0x4];
    void* nameTable;
    char pad3[0x4];
    bool convertToValue(unsigned int index, void* variant) const;
    bool convertToString(unsigned int index, void* str) const;
    void* findItem(const RBXName* name) const;
    void* getItemValue(const RBXName* name, void* out) const;
};

struct Variant {
    char pad[0x100];
};

struct String {
    char pad[0x100];
};

extern "C" void __stdcall _invalid_parameter_noinfo(void);
extern "C" void* __stdcall memcpy_s(void*, unsigned int, const void*, unsigned int);
extern "C" void __stdcall std_string_ctor(void*, const char*);
extern "C" void __stdcall std_string_dtor(void*);
extern "C" void __stdcall throw_list_too_long(void*);

bool EnumDescriptor::convertToValue(unsigned int index, void* variant) const
{
    return false;
}

bool EnumDescriptor::convertToString(unsigned int index, void* str) const
{
    return false;
}

void* EnumDescriptor::findItem(const RBXName* name) const
{
    return 0;
}

void* EnumDescriptor::getItemValue(const RBXName* name, void* out) const
{
    return 0;
}

bool EnumDescriptor_convertToValue(const EnumDescriptor* self, const RBXName* name, Variant* variant)
{
    Item** it = self->itemsBegin;
    Item** end = self->itemsEnd;
    bool found = false;
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    while (it != end) {
        Item* item = *it;
        if (item->name == (const char*)name) {
            if (!found) {
                self->convertToValue(item->index, variant);
                found = true;
            } else {
                String str;
                std_string_ctor(&str, "list<T> too long");
                throw_list_too_long(&str);
                std_string_dtor(&str);
            }
        }
        ++it;
    }

    return !found;
}
