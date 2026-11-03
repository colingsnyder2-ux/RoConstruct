// from server: 100% by EspClaude
// roc 2007-08 005e7580  unit: RBX::Flag  size: 170 bytes
// Most-derived constructor shape (virtual base at +0x168 via vbtable); vftable/vbtable
// symbols are the exe's data addresses (relocated references).
extern const void* const vbtable_7bb71c;
extern const void* const vbase_vftable_7a4ccc;
extern const void* const vft_7bd754, *const vft_7bd748, *const vft_7bd740, *const vft_7bd730;
extern const void* const vft_7bd720, *const vft_7bd710, *const vft_7bd700, *const vft_7bd6f0;
extern const void* const vft_7bd6e0, *const vft_7bd6d8, *const vft_7bd6c0, *const vft_7bd6b8;

struct Flag {
    char pad[0x168];
    const void* vbptr;
    char pad2[0x220 - 0x16c];
    const void* vbase_vfptr;
    Flag* construct(int);
    void baseConstruct(int);
};

Flag* Flag::construct(int most_derived) {
    if (most_derived != 0) {
        vbptr = &vbtable_7bb71c;
        vbase_vfptr = &vbase_vftable_7a4ccc;
    }
    baseConstruct(0);
    const void* p = vbptr;
    *(const void**)((char*)this + 0x00) = &vft_7bd754;
    *(const void**)((char*)this + 0x04) = &vft_7bd748;
    *(const void**)((char*)this + 0x10) = &vft_7bd740;
    *(const void**)((char*)this + 0x14) = &vft_7bd730;
    *(const void**)((char*)this + 0x2c) = &vft_7bd720;
    *(const void**)((char*)this + 0x44) = &vft_7bd710;
    *(const void**)((char*)this + 0x5c) = &vft_7bd700;
    *(const void**)((char*)this + 0x74) = &vft_7bd6f0;
    *(const void**)((char*)this + 0x8c) = &vft_7bd6e0;
    *(const void**)((char*)this + 0xe8) = &vft_7bd6d8;
    *(const void**)((char*)this + 0x158) = &vft_7bd6c0;
    int* q = *(int**)((char*)p + 4);
    *(const void**)((char*)q + (int)this + 0x168) = &vft_7bd6b8;
    const void* r = vbptr;
    int* s = *(int**)((char*)r + 4);
    int t = (int)s - 0xb8;
    *(int*)((char*)s + (int)this + 0x164) = t;
    return this;
}
