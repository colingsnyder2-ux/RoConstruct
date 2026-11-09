// from server: 36% by colin
struct EnumItem;

struct EnumDescriptor {
    EnumItem* convertToItem(int value) const;
};

struct Variant {
    Variant();
    ~Variant();
    Variant& operator=(int value);
    int get() const;
};

struct DescribedBase;

struct GetSet {
    virtual bool isReadOnly() const;
    virtual bool isWriteOnly() const;
    virtual int getValue(const DescribedBase* object) const;
    virtual void setValue(DescribedBase* object, int value) const;
};

struct PropertyDescriptor {
    void* vtable;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    void* field14;
    void* field18;
    void* field1C;
};

struct EnumPropertyDescriptor : PropertyDescriptor {
    bool isReadOnly() const;
    bool isWriteOnly() const;
    void get(const DescribedBase* instance, Variant& value) const;
    void set(DescribedBase* instance, const Variant& value) const;
    int getValue(const DescribedBase* object) const;
    void getVariant(const DescribedBase* instance, Variant& value) const;
    void setVariant(DescribedBase* instance, const Variant& value) const;
    void setValue(DescribedBase* object, int value) const;
    void copyValue(const DescribedBase* source, DescribedBase* destination) const;
    const EnumItem* getEnumItem(const DescribedBase* instance) const;
    bool equalValues(const DescribedBase* a, const DescribedBase* b) const;
};

struct SurfaceEnumPropDescriptor : EnumPropertyDescriptor {
    GetSet* getset;
    void copyValue(const DescribedBase* source, DescribedBase* destination) const;
};

void SurfaceEnumPropDescriptor::copyValue(const DescribedBase* source, DescribedBase* destination) const {
    Variant v;
    v = getset->getValue(source);
    getset->setValue(destination, v.get());
}
