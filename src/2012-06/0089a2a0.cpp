// from server: 29% by atomic.potato
extern "C" void* __cdecl sub_98211a(unsigned int);
extern "C" void __cdecl sub_91eac0(void*);
extern "C" void __cdecl sub_8999f0(void*, void*);
extern "C" void __cdecl sub_8115e0(void*, void*);
extern "C" void __cdecl sub_b22648(void*, const char*);
extern "C" void __cdecl sub_b2263c(void*);

struct VVelocityMotor {
    void ctor();
};

void VVelocityMotor::ctor()
{
    void* p = sub_98211a(0xb0);
    if (p != 0)
        sub_91eac0(p);
    else
        p = 0;
    sub_8999f0(this, p);

    *(int*)((char*)this + 0x00) = 0xbdbf3c;
    *(int*)((char*)this + 0x04) = 0xbdbf34;
    *(int*)((char*)this + 0x18) = 0xbdbf28;
    *(int*)((char*)this + 0x1c) = 0xbdbf1c;
    *(int*)((char*)this + 0x80) = 0xbdbef0;
    *(int*)((char*)this + 0xac) = 0;
    *(int*)((char*)this + 0xb0) = 0;
    *(int*)((char*)this + 0xb4) = 0;

    char buf[0x1c];
    sub_b22648(buf, (const char*)0xbdbb00);
    sub_8115e0(this, buf);
    sub_b2263c(buf);
}
