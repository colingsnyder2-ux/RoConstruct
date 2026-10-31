// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class XmlElement {
public:
    const XmlElement* nextSibling() const { return next; }
    const XmlElement* firstChild() const { return first; }
private:
    XmlElement* next;
    XmlElement* first;
};
namespace RBX {
class IReferenceBinder;
class Instance {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual void readProperty(const XmlElement* element, IReferenceBinder& binder);
    void readProperties(const XmlElement* container, IReferenceBinder& binder);
};
void Instance::readProperties(const XmlElement* container, IReferenceBinder& binder)
{
    for (const XmlElement* i = container->firstChild(); i != 0; i = i->nextSibling())
        readProperty(i, binder);
}
}
