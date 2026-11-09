// from server: 100% by tester
struct Descriptor {
    Descriptor(const char*, unsigned int);
};

struct XBoolItem : Descriptor {
    XBoolItem(const char*, unsigned int);
    char pad[0x4355e0];
};

XBoolItem::XBoolItem(const char* name, unsigned int attributes)
    : Descriptor(name, attributes)
{
    *(void**)this = (void*)0x8b4dec;
    *(void**)((char*)this + 0x20) = (void*)0x8b4d8c;
    *(void**)((char*)this + 0x118) = (void*)0x8b4d84;
}