// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RakNet { class BitStream; }
namespace RBX {
namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); };
class PropertyDescriptor {
public:
    virtual ~PropertyDescriptor();
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual std::string getStringValue(const DescribedBase* instance) const = 0;
};
class ConstProperty {
public:
    const PropertyDescriptor* descriptor;
    const DescribedBase* instance;
    const DescribedBase* getInstance() const { return instance; }
    const PropertyDescriptor& getDescriptor() const { return *descriptor; }
};
}
class InstanceBase { public: virtual ~InstanceBase(); char pad[0x14]; };
class Instance : public InstanceBase, public Reflection::DescribedBase { };
namespace Network {
class StringSender {
public:
    void serializeString(const Reflection::ConstProperty& property, RakNet::BitStream& bitStream);
    void send(RakNet::BitStream& stream, const std::string& value);
};
void StringSender::serializeString(const Reflection::ConstProperty& property, RakNet::BitStream& bitStream)
{
    const Instance* instance = static_cast<const Instance*>(property.getInstance());
    const Reflection::PropertyDescriptor& desc = property.getDescriptor();
    std::string value = desc.getStringValue(instance);
    send(bitStream, value);
}
}
}
