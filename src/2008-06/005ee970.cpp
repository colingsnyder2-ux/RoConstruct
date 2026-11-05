// from server: 100% by king_originala
struct EnumItem;

struct EnumDesc {
    static EnumDesc* singleton();
    bool convertToItem(int value, const EnumItem** out) const;
};

struct DescribedBase;

struct EnumPropertyDescriptor {
    virtual bool isReadOnly() const;
    virtual bool isWriteOnly() const;
    virtual void get(const DescribedBase* instance, void* value) const;
    virtual void set(DescribedBase* instance, const void* value) const;
    virtual void getVariant(const DescribedBase* instance, void* value) const;
    virtual void setVariant(DescribedBase* instance, const void* value) const;
    virtual void copyValue(const DescribedBase* source, DescribedBase* destination) const;
    virtual const EnumItem* getEnumItem(const DescribedBase* instance) const;
    virtual bool equalValues(const DescribedBase* a, const DescribedBase* b) const;
    int pad[6];
};

struct GetSet {
    virtual bool isReadOnly() const;
    virtual bool isWriteOnly() const;
    virtual int getValue(const DescribedBase* instance) const;
    virtual void setValue(DescribedBase* instance, const EnumItem* const& value) const;
};

struct SurfaceEnumPropDescriptor : EnumPropertyDescriptor {
    GetSet* getset;
    bool equalValues(const DescribedBase* a, const DescribedBase* b) const;
};

extern "C" void __cdecl sub_557330(void* a, void* b);
extern "C" EnumDesc* __cdecl sub_5ed630();

bool SurfaceEnumPropDescriptor::equalValues(const DescribedBase* a, const DescribedBase* b) const
{
    sub_557330((void*)0x5ed690, (void*)0x97b120);
    EnumDesc* desc = sub_5ed630();
    const EnumItem* item;
    if (desc->convertToItem((int)b, &item)) {
        getset->setValue((DescribedBase*)a, item);
        return true;
    }
    return false;
}
