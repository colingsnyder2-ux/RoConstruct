// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
template<class T> class ImpStr {
    char buf[0x1c];
public:
    __declspec(noinline) const T* c_str() const { return (const T*)buf; }
    __declspec(noinline) ~ImpStr() {}
};
extern template class __declspec(dllimport) ImpStr<char>;

namespace RBX {
ImpStr<char> format(const char*, ...);
class Name {
    ImpStr<char> str;
public:
    const char* c_str() const { return str.c_str(); }
};
namespace Reflection {
class PropertyDescriptor {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual bool hasStringValue() const;
    const Name* name;
    const Name* category;
};
class ConstProperty {
    const PropertyDescriptor* descriptor;
    const void* instance;
public:
    const PropertyDescriptor& getDescriptor() const { return *descriptor; }
    ImpStr<char> getStringValue() const;
};
}
}
class PropertyLogSink { public: void write(int, const char*); };
class PropertyLogProvider { public: virtual PropertyLogSink* get() = 0; };
extern PropertyLogProvider* provider;

__forceinline void writeFormatted(const ImpStr<char>& message) {
    (provider ? provider->get() : 0)->write(0, message.c_str());
}
void logProperty(RBX::Reflection::ConstProperty property) {
    if (property.getDescriptor().hasStringValue()) {
        writeFormatted(RBX::format("\t\t%s.%s: %s", property.getDescriptor().category->c_str(),
            property.getDescriptor().name->c_str(), property.getStringValue().c_str()));
    }
}
