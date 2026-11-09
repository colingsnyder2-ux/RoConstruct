// from server: 65% by atomic.potato
struct HeadBuilder {
    void* vtable;
    char pad[0x58];
    void assign(const HeadBuilder& other);
};

void HeadBuilder::assign(const HeadBuilder& other) {
    vtable = (void*)0xa1f244;
    *(int*)((char*)this + 4) = *(int*)((char*)&other + 4);
    *(float*)((char*)this + 8) = *(float*)((char*)&other + 8);
    *(float*)((char*)this + 0xc) = *(float*)((char*)&other + 0xc);
    *(float*)((char*)this + 0x10) = *(float*)((char*)&other + 0x10);
    *(int*)((char*)this + 0x14) = *(int*)((char*)&other + 0x14);
    *(float*)((char*)this + 0x18) = *(float*)((char*)&other + 0x18);
    *(float*)((char*)this + 0x1c) = *(float*)((char*)&other + 0x1c);
    *(float*)((char*)this + 0x20) = *(float*)((char*)&other + 0x20);
    *(float*)((char*)this + 0x24) = *(float*)((char*)&other + 0x24);
    *(float*)((char*)this + 0x28) = *(float*)((char*)&other + 0x28);
    *(float*)((char*)this + 0x2c) = *(float*)((char*)&other + 0x2c);
    vtable = (void*)0xa8c41c;
    *(float*)((char*)this + 0x30) = *(float*)((char*)&other + 0x30);
    *(float*)((char*)this + 0x34) = *(float*)((char*)&other + 0x34);
    *(float*)((char*)this + 0x38) = *(float*)((char*)&other + 0x38);
    *(int*)((char*)this + 0x3c) = *(int*)((char*)&other + 0x3c);
    *(float*)((char*)this + 0x40) = *(float*)((char*)&other + 0x40);
    *(float*)((char*)this + 0x44) = *(float*)((char*)&other + 0x44);
    *(float*)((char*)this + 0x48) = *(float*)((char*)&other + 0x48);
    *(float*)((char*)this + 0x4c) = *(float*)((char*)&other + 0x4c);
    *(float*)((char*)this + 0x50) = *(float*)((char*)&other + 0x50);
    *(float*)((char*)this + 0x54) = *(float*)((char*)&other + 0x54);
    *(float*)((char*)this + 0x58) = *(float*)((char*)&other + 0x58);
    *(float*)((char*)this + 0x5c) = *(float*)((char*)&other + 0x5c);
}
