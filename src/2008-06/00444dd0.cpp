// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_e1d1810476b7be09.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <string>
#include <fstream>
#include <memory>
template<class C> class basic_str {
public:
    __declspec(dllimport) unsigned int size() const;
    __declspec(dllimport) const C* c_str() const;
    __declspec(dllimport) ~basic_str();
    int d[7];
};
typedef basic_str<char> rstring;
class XmlElement {
public:
    ~XmlElement();
    int data[10];
};
class TextXmlParser {
public:
    TextXmlParser(std::streambuf* buffer);
    ~TextXmlParser();
    std::auto_ptr<XmlElement> parse();
    char data[0x48];
};
namespace RBX {
namespace Reflection { class ClassDescriptor; }
template<int N> Reflection::ClassDescriptor* descriptorOf();
class IReferenceBinder { public: virtual void announce(); };
class BinderItems {
public:
    ~BinderItems();
    int data[6];
};
class __declspec(novtable) MergeBinder : public IReferenceBinder {
public:
    MergeBinder();
    ~MergeBinder() {}
    void resolveRefs();
    BinderItems items;
};
class ClassList {
public:
    void add(Reflection::ClassDescriptor* d);
};
class Metadata {
public:
    char pad[0x130];
    ClassList* classes;
    void readProperties(const XmlElement* element, IReferenceBinder& binder);
    ClassList* findClasses();
    void load(rstring fileName);
};
void Metadata::load(rstring fileName)
{
    if (fileName.size() == 0)
        return;
    std::ifstream stream(fileName.c_str(), std::ios::in | std::ios::binary);
    TextXmlParser parser(stream.rdbuf());
    std::auto_ptr<XmlElement> root(parser.parse());
    MergeBinder binder;
    readProperties(root.get(), binder);
    binder.resolveRefs();
    classes = findClasses();
    if (classes)
    {
        classes->add(descriptorOf<0>());
        classes->add(descriptorOf<1>());
        classes->add(descriptorOf<2>());
        classes->add(descriptorOf<3>());
        classes->add(descriptorOf<4>());
        classes->add(descriptorOf<5>());
        classes->add(descriptorOf<6>());
        classes->add(descriptorOf<7>());
        classes->add(descriptorOf<8>());
        classes->add(descriptorOf<9>());
    }
}
}
