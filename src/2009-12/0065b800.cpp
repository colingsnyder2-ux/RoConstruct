// from server: 28% by atomic.potato
struct S {
    char pad0[0x20];
    int field20;
    int init();
};

extern "C" void __stdcall sub_637e60();
extern "C" int __stdcall sub_651fa0();

int S::init()
{
    sub_637e60();
    *(int*)((char*)this + 0x00) = 0x9cda0c;
    *(int*)((char*)this + 0x04) = 0x9cda04;
    *(int*)((char*)this + 0x18) = 0x9cd9f8;
    *(int*)((char*)this + 0x1c) = 0x9cd9f0;
    field20 = sub_651fa0();
    ++*(int*)0xb8fdb0;
    return (int)this;
}
