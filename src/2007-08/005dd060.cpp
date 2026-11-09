// from server: 100% by colin
struct RefPropDescriptorBase {
    void construct(const char* name);
};

struct RefPropDescriptor : RefPropDescriptorBase {
    RefPropDescriptor* construct(const char* name);
};

RefPropDescriptor* RefPropDescriptor::construct(const char* name)
{
    RefPropDescriptorBase::construct(name);
    *(int*)((char*)this + 0) = 0x7bc804;
    *(int*)((char*)this + 4) = 0x7bc7fc;
    *(int*)((char*)this + 0x10) = 0x7bc7f4;
    *(int*)((char*)this + 0x14) = 0x7bc7e4;
    *(int*)((char*)this + 0x2c) = 0x7bc7d4;
    *(int*)((char*)this + 0x44) = 0x7bc7c4;
    *(int*)((char*)this + 0x5c) = 0x7bc7b4;
    *(int*)((char*)this + 0x74) = 0x7bc7a4;
    *(int*)((char*)this + 0x8c) = 0x7bc794;
    *(int*)((char*)this + 0xe8) = 0x7bc77c;
    return this;
}
