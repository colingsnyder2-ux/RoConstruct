// from server: 100% by tester
struct Descriptor {
    Descriptor(const char*, unsigned int);
};

struct XBoolItem : Descriptor {
    XBoolItem(const char*, unsigned int);
    char pad[0x446a80];
};

XBoolItem::XBoolItem(const char* name, unsigned int attributes)
    : Descriptor(name, attributes)
{
    *(void**)this = (void*)0xa6a92c;
    *(void**)((char*)this + 0x20) = (void*)0xa6a8cc;
    *(void**)((char*)this + 0x118) = (void*)0xa6a8c4;
}