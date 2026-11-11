// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/slingshot-load
#include "util/NativeContentProvider.h"
#include "v8xml/XmlSerializer.h"
#include "v8xml/SerializerV2.h"
#include <boost/scoped_ptr.hpp>
#include <istream>
namespace RBX {
void ContentProvider::load(ContentId id, std::vector<boost::shared_ptr<Instance> >& instances)
{
    boost::scoped_ptr<std::istream> stream(getContent(id));
    TextXmlParser machine(stream->rdbuf());
    boost::scoped_ptr<XmlElement> root(machine.parse());
    SerializerV2().loadInstances(root.get(), instances);
}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::scoped_ptr<XmlElement>;
template class boost::scoped_ptr<std::basic_istream<char,std::char_traits<char> > >;
template class std::auto_ptr<std::basic_istream<char,std::char_traits<char> > >;
