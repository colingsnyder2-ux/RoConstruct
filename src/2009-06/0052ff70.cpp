// from server: 100% by atomic.potato
struct RBX_BeveledBlockBuilder {
    char pad0[0x48];
    RBX_BeveledBlockBuilder* copyFrom(RBX_BeveledBlockBuilder* other);
};

RBX_BeveledBlockBuilder* RBX_BeveledBlockBuilder::copyFrom(RBX_BeveledBlockBuilder* other) {
    *(float*)((char*)this + 0x00) = *(float*)((char*)other + 0x00);
    *(float*)((char*)this + 0x04) = *(float*)((char*)other + 0x04);
    *(float*)((char*)this + 0x08) = *(float*)((char*)other + 0x08);
    *(int*)((char*)this + 0x0c) = *(int*)((char*)other + 0x0c);
    *(float*)((char*)this + 0x10) = *(float*)((char*)other + 0x10);
    *(float*)((char*)this + 0x14) = *(float*)((char*)other + 0x14);
    *(float*)((char*)this + 0x18) = *(float*)((char*)other + 0x18);
    *(float*)((char*)this + 0x1c) = *(float*)((char*)other + 0x1c);
    *(float*)((char*)this + 0x20) = *(float*)((char*)other + 0x20);
    *(float*)((char*)this + 0x24) = *(float*)((char*)other + 0x24);
    *(float*)((char*)this + 0x28) = *(float*)((char*)other + 0x28);
    *(float*)((char*)this + 0x2c) = *(float*)((char*)other + 0x2c);
    *(float*)((char*)this + 0x30) = *(float*)((char*)other + 0x30);
    *(int*)((char*)this + 0x34) = *(int*)((char*)other + 0x34);
    *(int*)((char*)this + 0x38) = *(int*)((char*)other + 0x38);
    *(float*)((char*)this + 0x3c) = *(float*)((char*)other + 0x3c);
    *(float*)((char*)this + 0x40) = *(float*)((char*)other + 0x40);
    *(float*)((char*)this + 0x44) = *(float*)((char*)other + 0x44);
    return this;
}
