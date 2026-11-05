// from server: 100% by colin
struct DescribedBase {
    char pad[0x168];
    int memberTable;
};

struct GetSet {
    char pad0[8];
    int offset;
    char pad1[4];
    int index;
};

struct BoundPropGetSet {
    char pad0[8];
    int offset;
    char pad1[4];
    int index;
    unsigned char getValue(const DescribedBase* object) const;
};

unsigned char BoundPropGetSet::getValue(const DescribedBase* object) const {
    const DescribedBase* c = object;
    if (c) {
        c = (const DescribedBase*)((const char*)c - 4);
    } else {
        c = 0;
    }
    int table = *(int*)((const char*)c + 0x168);
    int idx = *(int*)((const char*)this + 0xc);
    int off = *(int*)(table + idx);
    off += *(int*)((const char*)this + 8);
    return *(unsigned char*)((const char*)c + off + 0x168);
}
