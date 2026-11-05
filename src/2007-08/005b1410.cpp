// from server: 100% by colin
struct JointInstance {
    char pad[0x100];
    JointInstance(const char*);
};

struct Base {
    void init(const char*);
};

JointInstance::JointInstance(const char* name)
{
    ((Base*)this)->init(name);
    *(int*)((char*)this + 0x00) = 0x7b63ec;
    *(int*)((char*)this + 0x04) = 0x7b63e4;
    *(int*)((char*)this + 0x10) = 0x7b63dc;
    *(int*)((char*)this + 0x14) = 0x7b63cc;
    *(int*)((char*)this + 0x2c) = 0x7b63bc;
    *(int*)((char*)this + 0x44) = 0x7b63ac;
    *(int*)((char*)this + 0x5c) = 0x7b639c;
    *(int*)((char*)this + 0x74) = 0x7b638c;
    *(int*)((char*)this + 0x8c) = 0x7b637c;
    *(int*)((char*)this + 0xe8) = 0x7b6364;
}
