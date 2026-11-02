// from server: 100% by tajop
struct GetSet {
    virtual void slot0();
    virtual void slot1();
    virtual int getValue(const void* instance) const;
};

struct TypedPropertyDescriptor {
    char pad[0x28];
    GetSet* getset;
    bool equalValue(const void* a, const void* b) const;
};

bool TypedPropertyDescriptor::equalValue(const void* a, const void* b) const {
    int va = getset->getValue(a);
    return va == getset->getValue(b);
}
