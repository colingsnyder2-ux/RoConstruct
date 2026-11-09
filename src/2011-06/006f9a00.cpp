// from server: 36% by atomic.potato
struct RBX_Motor {
    char pad0[0x90];
    int field90;
    int sub_58a310();
    int sub_5980d0();
    RBX_Motor();
};

RBX_Motor::RBX_Motor()
{
    *(int*)((char*)this + 0x00) = 0x00aaaa64;
    *(int*)((char*)this + 0x04) = 0x00aaaa5c;
    *(int*)((char*)this + 0x18) = 0x00aaaa50;
    *(int*)((char*)this + 0x1c) = 0x00aaaa44;
    *(int*)((char*)this + 0x90) = 0x00aaaa1c;
    sub_58a310();
    sub_5980d0();
}
