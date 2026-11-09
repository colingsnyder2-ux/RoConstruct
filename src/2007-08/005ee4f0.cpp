// from server: 100% by colin
struct S_005ee4f0 {
    void* ctor(int);
};

extern "C" void __stdcall sub_005ed950(int);

void* S_005ee4f0::ctor(int a)
{
    sub_005ed950(a);
    *(int*)((char*)this + 0x00) = 0x7bf304;
    *(int*)((char*)this + 0x04) = 0x7bf2fc;
    *(int*)((char*)this + 0x10) = 0x7bf2f4;
    *(int*)((char*)this + 0x14) = 0x7bf2e4;
    *(int*)((char*)this + 0x2c) = 0x7bf2d4;
    *(int*)((char*)this + 0x44) = 0x7bf2c4;
    *(int*)((char*)this + 0x5c) = 0x7bf2b4;
    *(int*)((char*)this + 0x74) = 0x7bf2a4;
    *(int*)((char*)this + 0x8c) = 0x7bf294;
    *(int*)((char*)this + 0xe8) = 0x7bf27c;
    *(int*)((char*)this + 0xf0) = 0x7bf270;
    return this;
}
