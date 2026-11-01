// from server: 100% by colin
struct RBX_AutoJoint {
    char pad[0xec];
    void sub_005b0e40(int);
    RBX_AutoJoint* sub_005b1050(int);
};

RBX_AutoJoint* RBX_AutoJoint::sub_005b1050(int a)
{
    sub_005b0e40(a);
    *(int*)((char*)this + 0x00) = 0x7b6ac4;
    *(int*)((char*)this + 0x04) = 0x7b6abc;
    *(int*)((char*)this + 0x10) = 0x7b6ab4;
    *(int*)((char*)this + 0x14) = 0x7b6aa4;
    *(int*)((char*)this + 0x2c) = 0x7b6a94;
    *(int*)((char*)this + 0x44) = 0x7b6a84;
    *(int*)((char*)this + 0x5c) = 0x7b6a74;
    *(int*)((char*)this + 0x74) = 0x7b6a64;
    *(int*)((char*)this + 0x8c) = 0x7b6a54;
    *(int*)((char*)this + 0xe8) = 0x7b6a3c;
    return this;
}
