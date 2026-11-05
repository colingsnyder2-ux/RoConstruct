// from server: 100% by tester
struct Descriptor {
    Descriptor(const char*, unsigned int);
};

struct XBoolItem : Descriptor {
    XBoolItem(const char*, unsigned int);
    char pad[0x438030];
};

XBoolItem::XBoolItem(const char* name, unsigned int attributes)
    : Descriptor(name, attributes)
{
    *(void**)this = (void*)0xa08ea4;
    *(void**)((char*)this + 0x20) = (void*)0xa08e44;
    *(void**)((char*)this + 0x118) = (void*)0xa08e3c;
}