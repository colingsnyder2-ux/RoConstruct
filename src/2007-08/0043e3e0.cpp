// from server: 100% by colin
struct Descriptor {
    Descriptor(const char*, unsigned int);
};

struct XBoolItem : Descriptor {
    XBoolItem(const char*, unsigned int);
    char pad[0x110];
};

XBoolItem::XBoolItem(const char* name, unsigned int attributes)
    : Descriptor(name, attributes)
{
    *(void**)this = (void*)0x78e614;
    *(void**)((char*)this + 0x20) = (void*)0x78e5b4;
    *(void**)((char*)this + 0x10c) = (void*)0x78e5ac;
}
