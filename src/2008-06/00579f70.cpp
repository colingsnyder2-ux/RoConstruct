// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_696ed0a6cdbdaf74.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <string>
#include <vector>
#include <memory>
#include <istream>
#include <boost/shared_ptr.hpp>
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
class Instance;
class ContentId {
public:
    std::string id;
    int flags;
};
class ContentProvider {
public:
    std::auto_ptr<std::istream> getContent(ContentId id);
};
class SerializerV2 {
public:
    void loadInstances(XmlElement* root, std::vector<boost::shared_ptr<Instance> >& result);
    int state;
};
class DataModel {
public:
    ContentProvider* createContentProvider();
    boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > get(ContentId contentId);
};
template<class T> inline T* create(DataModel* dm) { return dm ? dm->createContentProvider() : 0; }
boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > DataModel::get(ContentId contentId)
{
    std::auto_ptr<std::istream> stream = create<ContentProvider>(this)->getContent(contentId);

    TextXmlParser machine(stream->rdbuf());
    std::auto_ptr<XmlElement> root = machine.parse();

    boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > result(new std::vector<boost::shared_ptr<Instance> >);

    SerializerV2 serializer;
    serializer.loadInstances(root.get(), *result);

    return result;
}
}
