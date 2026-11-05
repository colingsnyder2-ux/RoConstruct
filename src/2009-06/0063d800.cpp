// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX { class Instance; }
class XmlTag;
class InstanceHandle {
public:
    void* a; void* b;
    InstanceHandle(RBX::Instance* target);
    InstanceHandle(const InstanceHandle& o);
    ~InstanceHandle();
};
class XmlElement {
public:
    static void* operator new(unsigned int size);
    static void operator delete(void* p);
    XmlElement(const XmlTag& tag, InstanceHandle value);
    char pad[0x28];
};
extern const XmlTag& tag_External;
namespace RBX {
class Instance {
public:
    virtual XmlElement* write();
};
class Accoutrement : public Instance {
public:
    static bool writeUnlocked;
    virtual XmlElement* write();
};
XmlElement* Accoutrement::write()
{
    if (!writeUnlocked)
        return new XmlElement(tag_External, InstanceHandle(this));
    else
        return Instance::write();
}
}
