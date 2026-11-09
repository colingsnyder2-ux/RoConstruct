// from server: 36% by atomic.potato
// roc 2012-06 0081ab80  unit: RBX::VTouchTransmitter::?$FactoryProduct  size: 216 bytes

extern "C" {
    void __stdcall sub_97C270(void*);
    void* __cdecl sub_98211A(unsigned int);
    void __cdecl sub_684840(void*, void*);
    void __cdecl sub_81AAB0(void*);
    void __stdcall sub_B22648(void*);
    void __stdcall sub_B2263C(void*);
}

struct VTouchTransmitter {
    void ctor();
};

void VTouchTransmitter::ctor()
{
    char pad[0x80];
    void* p;
    char str[0x10];

    sub_81AAB0(this);
    *(int*)((char*)this + 0) = 0xbc84c4;
    *(int*)((char*)this + 4) = 0xbc84bc;
    *(int*)((char*)this + 0x18) = 0xbc84b0;
    *(int*)((char*)this + 0x1c) = 0xbc84a4;

    sub_97C270((void*)0xe507c0);

    *(int*)((char*)this + 0) = 0xbc844c;
    *(int*)((char*)this + 4) = 0xbc8444;
    *(int*)((char*)this + 0x18) = 0xbc8438;
    *(int*)((char*)this + 0x1c) = 0xbc842c;

    p = sub_98211A(0x10);
    if (p != 0) {
        *(int*)((char*)p + 4) = 0;
        *(int*)((char*)p + 8) = 0;
        *(int*)((char*)p + 0xc) = 0;
    } else {
        p = 0;
    }
    *(void**)((char*)this + 0x80) = p;

    sub_B22648((void*)0xbc8518);
    sub_684840(this, str);
    sub_B2263C(str);
}
