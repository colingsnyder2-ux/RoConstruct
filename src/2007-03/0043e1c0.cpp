// from server: 100% by tester
struct Descriptor {
    Descriptor(const char*, unsigned int);
};

struct XBoolItem : Descriptor {
    XBoolItem(const char*, unsigned int);
    char pad[0x43c2d0];
};

XBoolItem::XBoolItem(const char* name, unsigned int attributes)
    : Descriptor(name, attributes)
{
    *(void**)this = (void*)0x78d664;
    *(void**)((char*)this + 0x20) = (void*)0x78d604;
    *(void**)((char*)this + 0x108) = (void*)0x78d5fc;
}