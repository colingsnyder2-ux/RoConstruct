// from server: 100% by coldek
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <string>
#include <vector>
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* operator->() const { return px; }
};
}

namespace RakNet { class BitStream { public: void readCompressed(unsigned int& value, unsigned int max, bool b); }; }
struct SystemAddress { const char* ToString(bool writePort) const; char data[6]; };
namespace RBX {
enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR };
class StandardOut {
public:
    static boost::shared_ptr<StandardOut> singleton();
    void __cdecl print(MessageType type, const char* format, ...);
};
class Name { public: int index; std::string str; const char* c_str() const { return str.c_str(); } };
class Guid { public: std::string readableString(int scope) const; int a, b; };
namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); };
class PropertyDescriptor { public: void* vptr; const Name& name; };
class Property {
public:
    const PropertyDescriptor* descriptor;
    DescribedBase* instance;
    Property(const PropertyDescriptor& d, DescribedBase* i) : descriptor(&d), instance(i) {}
};
}
class PadI0 { public: virtual ~PadI0(); char pad[0xc]; };
class Described { public: virtual ~Described(); virtual const Name& getClassName() const; };
class Instance : public PadI0, public Described, public Reflection::DescribedBase {};
class NetworkSettings { public: static NetworkSettings& singleton(); char pad[0x132]; bool printProperties; };
namespace Network {
class Replicator {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual bool canChangeProperty(Instance* instance);
    char pad0[0x2c18 - 4];
    std::vector<const Reflection::PropertyDescriptor*> propDictionary;
    unsigned int propDictionarySize;
    char pad1[0x2d54 - 0x2c34];
    SystemAddress remotePlayerId;
    char pad2[0x2d60 - 0x2d5a];
    const Name* lastPropertyName;
    void deserializeInstanceRef(RakNet::BitStream& bs, Instance*& instance, Guid& id);
    void deserializeValue(RakNet::BitStream& bs, const Reflection::Property& prop);
    void readChangedProperty(RakNet::BitStream& bitStream);
};

void Replicator::readChangedProperty(RakNet::BitStream& bitStream)
{
    Instance* instance;
    Guid id;
    deserializeInstanceRef(bitStream, instance, id);
    unsigned int index = 0;
    bitStream.readCompressed(index, propDictionarySize, true);
    const Reflection::PropertyDescriptor* desc = propDictionary[index];
    if (NetworkSettings::singleton().printProperties) {
        StandardOut::singleton()->print(MESSAGE_INFO, "Replication: %s-%s.%s << %s", instance ? instance->getClassName().c_str() : "?", id.readableString(4).c_str(), desc->name.c_str(), remotePlayerId.ToString(true));
    }
    if (!canChangeProperty(instance)) {
        StandardOut::singleton()->print(MESSAGE_WARNING, "Replication rejected property: %s-%s.%s << %s", instance ? instance->getClassName().c_str() : "?", id.readableString(4).c_str(), desc->name.c_str(), remotePlayerId.ToString(true));
        instance = 0;
    }
    Reflection::Property prop(*desc, instance);
    deserializeValue(bitStream, prop);
    lastPropertyName = &desc->name;
}
}
}
