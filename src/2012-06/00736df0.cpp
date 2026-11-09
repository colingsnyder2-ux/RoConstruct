// from server: 48% by colin
struct EnumDescriptor {
    void addItem(const char* name, int value);
};

struct EnumDesc {
    bool addPair(const char* name, int value);
};

bool EnumDesc::addPair(const char* name, int value)
{
    EnumDescriptor* desc = *(EnumDescriptor**)((char*)this + 12);
    desc->addItem(name, value);
    return true;
}
