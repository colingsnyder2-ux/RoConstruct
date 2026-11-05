// from server: 96% by colin
struct S {
    char pad[0x100];
    void ctor();
};

void S::ctor()
{
    *(int*)((char*)this + 0x00) = 0x7b2d9c;
    *(int*)((char*)this + 0x04) = 0x7b2d90;
    *(int*)((char*)this + 0x10) = 0x7b2d88;
    *(int*)((char*)this + 0x14) = 0x7b2d78;
    *(int*)((char*)this + 0x2c) = 0x7b2d68;
    *(int*)((char*)this + 0x44) = 0x7b2d58;
    *(int*)((char*)this + 0x5c) = 0x7b2d48;
    *(int*)((char*)this + 0x74) = 0x7b2d38;
    *(int*)((char*)this + 0x8c) = 0x7b2d28;
    *(int*)((char*)this + 0xe8) = 0x7b2d20;
    extern void base_ctor();
    base_ctor();
}
