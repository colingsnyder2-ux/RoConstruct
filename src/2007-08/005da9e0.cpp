// from server: 100% by colin
struct VelocityMotor {
    void construct();
};

extern void func_005da5b0();

void VelocityMotor::construct()
{
    *(int*)((char*)this + 0x00) = 0x7bc36c;
    *(int*)((char*)this + 0x04) = 0x7bc364;
    *(int*)((char*)this + 0x10) = 0x7bc35c;
    *(int*)((char*)this + 0x14) = 0x7bc34c;
    *(int*)((char*)this + 0x2c) = 0x7bc33c;
    *(int*)((char*)this + 0x44) = 0x7bc32c;
    *(int*)((char*)this + 0x5c) = 0x7bc31c;
    *(int*)((char*)this + 0x74) = 0x7bc30c;
    *(int*)((char*)this + 0x8c) = 0x7bc2fc;
    *(int*)((char*)this + 0xe8) = 0x7bc2e4;
    func_005da5b0();
}
