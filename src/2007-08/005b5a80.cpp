// from server: 0% by colin
struct DescribedBase;

struct PropertyDescriptor {
    struct Attributes {
        unsigned int bits;
    };
};

struct BoundProp {
    void checkFlags();
};

struct GetSet {
    virtual bool isReadOnly() const;
    virtual bool isWriteOnly() const;
    virtual void getValue(const DescribedBase* object, void* out) const;
    virtual void setValue(DescribedBase* object, const void* value) const;
};

struct TypedPropertyDescriptor {
    GetSet* getset;
    TypedPropertyDescriptor();
    ~TypedPropertyDescriptor();
};

struct BoundPropGetSet : GetSet {
    BoundProp& desc;
    int member;
    int changed;
    BoundPropGetSet(BoundProp& d, int m, int c);
    virtual bool isReadOnly() const;
    virtual bool isWriteOnly() const;
    virtual void getValue(const DescribedBase* object, void* out) const;
    virtual void setValue(DescribedBase* object, const void* value) const;
};

struct Class {
    void raisePropertyChanged(const PropertyDescriptor& desc);
};

struct ShirtGraphic {
    char pad[0x108];
    int field_108;
    char pad2[0x20];
    int field_128;
    char pad3[0x20];
    int field_148;
    char pad4[0x20];
    int field_168;
    char pad5[0x20];
    int field_188;
    char pad6[0x1c];
    unsigned char field_1a8;
    char pad7[3];
    int field_1ac;

    void raisePropertyChanged(const PropertyDescriptor& desc);

    void init();
};

extern "C" {
    void* __stdcall sub_408740();
    void __stdcall sub_457dd0();
    void __stdcall sub_474f70();
    void __stdcall sub_5053c0();
    void __stdcall sub_5067b0();
    void __stdcall sub_544f80();
    void __stdcall sub_548da0();
    void __stdcall sub_5b5800();
    void __stdcall sub_630af7();
    void __stdcall sub_630bdc();
    void __stdcall sub_733cb0();
    void __stdcall sub_734930();
    long __stdcall InterlockedDecrement(long*);
}

void ShirtGraphic::raisePropertyChanged(const PropertyDescriptor& desc) {
}

BoundPropGetSet::BoundPropGetSet(BoundProp& d, int m, int c) : desc(d), member(m), changed(c) {
}

bool BoundPropGetSet::isReadOnly() const {
    return false;
}

bool BoundPropGetSet::isWriteOnly() const {
    return false;
}

void BoundPropGetSet::getValue(const DescribedBase* object, void* out) const {
}

void BoundPropGetSet::setValue(DescribedBase* object, const void* value) const {
}

void ShirtGraphic::init() {
    BoundProp* bp = (BoundProp*)0;
    if (bp) {
        bp->checkFlags();
    }
}
