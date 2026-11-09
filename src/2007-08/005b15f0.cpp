// from server: 100% by colin
struct Instance {
    Instance(int);
    char pad[0xe8];
};

struct JointInstance : Instance {
    JointInstance(int);
};

JointInstance::JointInstance(int a) : Instance(a)
{
    *(int*)((char*)this + 0x00) = 0x7b67fc;
    *(int*)((char*)this + 0x04) = 0x7b67f4;
    *(int*)((char*)this + 0x10) = 0x7b67ec;
    *(int*)((char*)this + 0x14) = 0x7b67dc;
    *(int*)((char*)this + 0x2c) = 0x7b67cc;
    *(int*)((char*)this + 0x44) = 0x7b67bc;
    *(int*)((char*)this + 0x5c) = 0x7b67ac;
    *(int*)((char*)this + 0x74) = 0x7b679c;
    *(int*)((char*)this + 0x8c) = 0x7b678c;
    *(int*)((char*)this + 0xe8) = 0x7b6774;
}
