// from server: 100% by colin
struct DescribedBase {
    char pad[0xec];
};

struct GetSet {
    int pad0;
    int pad4;
    int offset8;
    int offsetc;
    char getValue(const DescribedBase* object) const;
};

char GetSet::getValue(const DescribedBase* object) const {
    const DescribedBase* c = object ? (const DescribedBase*)((const char*)object - 4) : 0;
    int idx = *(int*)((const char*)c + 0xec);
    int off = *(int*)((const char*)this + 0xc);
    int val = *(int*)((const char*)idx + off);
    val += *(int*)((const char*)this + 8);
    return *(char*)((const char*)c + 0xec + val);
}
