// from server: 67% by EspClaude
// from server: 50% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.34.1 roc_claude_712ed5778db8768e.cpp

// Candidate translation unit (score above; library headers required).
// Codegen analog: property-grid XItem reads an enum/int value from an instance under the DataModel lock.
// Offsets read off the target: grid at this+0x11c, descriptor at this+0x120, grid->dataModel at +0x188,
// descriptor vtable slot 11 (+0x2c), Lock local 12 bytes (ctor 00439850 / dtor 005595a0 out of line),
// argument upcast to a base at +4 of Instance.
// Target needs the wrapper settings  // roc-cl: 50727  and  // roc-flags: /O2 /GS /EHsc /MD
namespace RBX {
class DataModel;
namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); };
class EnumPropertyDescriptor {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02(); virtual void slot03();
    virtual void slot04(); virtual void slot05(); virtual void slot06(); virtual void slot07();
    virtual void slot08(); virtual void slot09(); virtual void slot10();
    virtual int getEnumValue(const DescribedBase* object) const;
};
}
class InstanceBase0 { public: virtual void slot00(); };
class Instance : public InstanceBase0, public Reflection::DescribedBase { };
}

class DataModelLock {
public:
    DataModelLock(RBX::DataModel* dataModel);
    ~DataModelLock();
private:
    void* p0; void* p1; void* p2;
};

class CPropGrid {
    char before_[0x188];
public:
    RBX::DataModel* dataModel;
};

class EnumItem {
    char before_[0x11c];
public:
    CPropGrid* grid;
    const RBX::Reflection::EnumPropertyDescriptor* descriptor;
    int readInstanceValue(RBX::Instance* instance);
};

int EnumItem::readInstanceValue(RBX::Instance* instance)
{
    DataModelLock lock(grid->dataModel);
    return descriptor->getEnumValue(instance);
}
