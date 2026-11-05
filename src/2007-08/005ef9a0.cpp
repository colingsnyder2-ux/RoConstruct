// from server: 100% by colin
struct BodyMover {
    BodyMover* construct(int);
};

extern "C" void __stdcall sub_5426B0(int);

BodyMover* BodyMover::construct(int a) {
    sub_5426B0(a);
    *(int*)((char*)this + 0x00) = 0x7af85c;
    *(int*)((char*)this + 0x04) = 0x7af854;
    *(int*)((char*)this + 0x10) = 0x7af84c;
    *(int*)((char*)this + 0x14) = 0x7af83c;
    *(int*)((char*)this + 0x2c) = 0x7af82c;
    *(int*)((char*)this + 0x44) = 0x7af81c;
    *(int*)((char*)this + 0x5c) = 0x7af80c;
    *(int*)((char*)this + 0x74) = 0x7af7fc;
    *(int*)((char*)this + 0x8c) = 0x7af7ec;
    return this;
}
