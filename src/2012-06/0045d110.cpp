// from server: 100% by tester
struct Descriptor {
    Descriptor(const char*, unsigned int);
};

struct XBoolItem : Descriptor {
    XBoolItem(const char*, unsigned int);
    char pad[0x458f40];
};

XBoolItem::XBoolItem(const char* name, unsigned int attributes)
    : Descriptor(name, attributes)
{
    *(void**)this = (void*)0xb555d4;
    *(void**)((char*)this + 0x20) = (void*)0xb55574;
    *(void**)((char*)this + 0x118) = (void*)0xb5556c;
}