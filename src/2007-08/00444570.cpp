// from server: 100% by colin
struct MergeBinder {
    char pad[0xec];
    int field_0xe8;
    MergeBinder();
};

extern void __fastcall sub_444110(MergeBinder* self);

MergeBinder::MergeBinder()
{
    sub_444110(this);
    *(int*)((char*)this + 0x00) = 0x78f96c;
    *(int*)((char*)this + 0x04) = 0x78f964;
    *(int*)((char*)this + 0x10) = 0x78f95c;
    *(int*)((char*)this + 0x14) = 0x78f94c;
    *(int*)((char*)this + 0x2c) = 0x78f93c;
    *(int*)((char*)this + 0x44) = 0x78f92c;
    *(int*)((char*)this + 0x5c) = 0x78f91c;
    *(int*)((char*)this + 0x74) = 0x78f90c;
    *(int*)((char*)this + 0x8c) = 0x78f8fc;
    *(int*)((char*)this + 0xe8) = 0;
}
