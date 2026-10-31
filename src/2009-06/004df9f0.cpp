// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RakNet { class BitStream; }
namespace RBX {
namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); };
class PropertyDescriptor {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
};
class RefPropertyDescriptor : public PropertyDescriptor {
public:
    virtual DescribedBase* getRefValue(const DescribedBase* instance) const;
};
class ConstProperty {
public:
    const PropertyDescriptor* descriptor;
    const DescribedBase* instance;
    const PropertyDescriptor& getDescriptor() const { return *descriptor; }
    const DescribedBase* getInstance() const { return instance; }
};
}
class InstanceBase { char d[0x14]; public: virtual ~InstanceBase(); };
class Instance : public InstanceBase, public Reflection::DescribedBase {};
namespace Network {
class IdSerializer {
public:
    void serializeId(RakNet::BitStream& stream, const Instance* instance);
    void serializeRef(const Reflection::ConstProperty& property, RakNet::BitStream& bitStream);
};
void IdSerializer::serializeRef(const Reflection::ConstProperty& property, RakNet::BitStream& bitStream)
{
    const Reflection::RefPropertyDescriptor& prop = static_cast<const Reflection::RefPropertyDescriptor&>(property.getDescriptor());
    serializeId(bitStream, static_cast<Instance*>(prop.getRefValue(property.getInstance())));
}
}
}
