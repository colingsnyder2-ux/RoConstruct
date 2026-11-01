// from server: 100% by colin
struct Backpack {
    Backpack* init();
};

extern void __fastcall base_construct(void*);

Backpack* Backpack::init()
{
    base_construct(this);
    *(int*)((char*)this + 0x00) = 0x7b2f6c;
    *(int*)((char*)this + 0x04) = 0x7b2f60;
    *(int*)((char*)this + 0x10) = 0x7b2f58;
    *(int*)((char*)this + 0x14) = 0x7b2f48;
    *(int*)((char*)this + 0x2c) = 0x7b2f38;
    *(int*)((char*)this + 0x44) = 0x7b2f28;
    *(int*)((char*)this + 0x5c) = 0x7b2f18;
    *(int*)((char*)this + 0x74) = 0x7b2f08;
    *(int*)((char*)this + 0x8c) = 0x7b2ef8;
    *(int*)((char*)this + 0xe8) = 0x7b2ef0;
    return this;
}
