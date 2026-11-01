// from server: 100% by colin
struct DescribedBase {
    char pad[0x108];
    int memberOffset;
};

struct GetSet {
    char pad0[8];
    int offset;
    char pad1[4];
    int index;
};

struct BoundPropGetSet {
    float getValue(DescribedBase* object) const;
};

float BoundPropGetSet::getValue(DescribedBase* object) const
{
    DescribedBase* base = object ? (DescribedBase*)((char*)object - 4) : 0;
    int* table = *(int**)((char*)base + 0x108);
    int idx = *(int*)((char*)this + 0xc);
    int off = *(int*)((char*)table + idx) + *(int*)((char*)this + 8);
    return *(float*)((char*)base + off + 0x108);
}
