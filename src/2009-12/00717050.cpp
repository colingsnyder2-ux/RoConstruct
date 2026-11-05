// from server: 36% by atomic.potato
struct VJointInstance {
    void* construct(int);
    char pad0[0x20];
    int field20;
};

extern "C" int __cdecl sub_64fe60();

struct Base {
    void sub_716930(int);
};

extern int dword_B8FED8;

void* VJointInstance::construct(int arg) {
    ((Base*)this)->sub_716930(arg);
    *(int*)((char*)this + 0x00) = 0x9df0ac;
    *(int*)((char*)this + 0x04) = 0x9df0a0;
    *(int*)((char*)this + 0x18) = 0x9df094;
    *(int*)((char*)this + 0x1c) = 0x9df08c;
    *(int*)((char*)this + 0x94) = 0x9df074;
    field20 = sub_64fe60();
    dword_B8FED8++;

    return this;
}
