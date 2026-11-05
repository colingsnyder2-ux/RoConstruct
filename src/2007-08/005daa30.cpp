// from server: 100% by colin
struct VelocityMotor {
    void construct();
};

extern void func_005da5b0();

void VelocityMotor::construct()
{
    *(int*)((char*)this + 0x00) = 0x7bc444;
    *(int*)((char*)this + 0x04) = 0x7bc438;
    *(int*)((char*)this + 0x10) = 0x7bc430;
    *(int*)((char*)this + 0x14) = 0x7bc420;
    *(int*)((char*)this + 0x2c) = 0x7bc410;
    *(int*)((char*)this + 0x44) = 0x7bc400;
    *(int*)((char*)this + 0x5c) = 0x7bc3f0;
    *(int*)((char*)this + 0x74) = 0x7bc3e0;
    *(int*)((char*)this + 0x8c) = 0x7bc3d0;
    *(int*)((char*)this + 0xe8) = 0x7bc3b8;
    func_005da5b0();
}
