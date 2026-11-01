// from server: 100% by tester
struct Descriptor {
    Descriptor(const char*, unsigned int);
};

struct XBoolItem : Descriptor {
    XBoolItem(const char*, unsigned int);
    char pad[0x43b400];
};

XBoolItem::XBoolItem(const char* name, unsigned int attributes)
    : Descriptor(name, attributes)
{
    *(void**)this = (void*)0x81480c;
    *(void**)((char*)this + 0x20) = (void*)0x8147ac;
    *(void**)((char*)this + 0x118) = (void*)0x8147a4;
}