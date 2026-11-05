// from server: 100% by EspClaude
// from server: 95% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_f8ab8247c52ec0b7.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct String {
    unsigned char storage[28];
    const char* c_str() const;
    ~String();
};

extern const char* (__thiscall *string_c_str)(const String*);
extern void (__thiscall *string_destroy)(String*);

inline const char* String::c_str() const {
    return string_c_str(this);
}

inline String::~String() {
    string_destroy(this);
}

String __cdecl formatText(const char*, const char*);

struct Stream {
    Stream& write(int, const char*);
};

struct StreamSource {
    virtual Stream* getStream() = 0;
};

extern StreamSource* streamSource;

#include <vector>
#include <iterator>
namespace RBX { namespace Reflection {
class DescribedBase;
class PropertyDescriptor;
class Property { public: Property(const PropertyDescriptor*, DescribedBase*); };
class Descriptor { public: virtual ~Descriptor() {} const void* name; };
template <class T>
class MemberDescriptorContainer
{
public:
    typedef std::vector<T*> Collection;
    class Iterator : public std::iterator<std::forward_iterator_tag, Property, void, Property, Property&>
    {
    public:
        Iterator(DescribedBase* instance, typename Collection::const_iterator iter) : instance(instance), iter(iter) {}
    private:
        DescribedBase* instance;
        typename Collection::const_iterator iter;
    };
    Iterator begin(DescribedBase* instance) const { return Iterator(instance, descriptors.begin()); }
    Iterator end(DescribedBase* instance) const { return Iterator(instance, descriptors.end()); }
    Collection descriptors;
};
class ClassDescriptor : public Descriptor, public MemberDescriptorContainer<PropertyDescriptor> {};
typedef MemberDescriptorContainer<PropertyDescriptor>::Iterator PropertyIterator;
class DescribedBase {
public:
    virtual ~DescribedBase() {}
    void* signalSource;
    const ClassDescriptor* descriptor;
    const ClassDescriptor& getDescriptor() const { return *descriptor; }
    PropertyIterator properties_begin() { return getDescriptor().MemberDescriptorContainer<PropertyDescriptor>::begin(this); }
    PropertyIterator properties_end() { return getDescriptor().MemberDescriptorContainer<PropertyDescriptor>::end(this); }
};
}}
struct Object {
    unsigned char padding[0x14];
    RBX::Reflection::DescribedBase range;
    unsigned char padding2[0x110 - 0x14 - sizeof(RBX::Reflection::DescribedBase)];
    String text;
};

typedef boost::shared_ptr<Object> Shared;

void __cdecl visitElement(RBX::Reflection::Property);
void __cdecl visitRange(RBX::Reflection::PropertyIterator, RBX::Reflection::PropertyIterator, void (__cdecl *)(RBX::Reflection::Property));

inline void print(int type, const String& message) {
    Stream* stream = streamSource ? streamSource->getStream() : 0;
    stream->write(type, message.c_str());
}

void __cdecl process(Shared value) {
    print(0, formatText("\t%s",
            value->text.c_str()));
    visitRange(value->range.properties_begin(), value->range.properties_end(), visitElement);
}
