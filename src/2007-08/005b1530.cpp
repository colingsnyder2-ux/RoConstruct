// from server: 100% by colin
struct Instance {
    Instance(const char*);
};

struct JointInstance : Instance {
    JointInstance(const char*);
};

JointInstance::JointInstance(const char* name)
    : Instance(name)
{
    *(int*)((char*)this + 0x00) = 0x7b665c;
    *(int*)((char*)this + 0x04) = 0x7b6654;
    *(int*)((char*)this + 0x10) = 0x7b664c;
    *(int*)((char*)this + 0x14) = 0x7b663c;
    *(int*)((char*)this + 0x2c) = 0x7b662c;
    *(int*)((char*)this + 0x44) = 0x7b661c;
    *(int*)((char*)this + 0x5c) = 0x7b660c;
    *(int*)((char*)this + 0x74) = 0x7b65fc;
    *(int*)((char*)this + 0x8c) = 0x7b65ec;
    *(int*)((char*)this + 0xe8) = 0x7b65d4;
}
