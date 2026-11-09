// from server: 100% by king_originala_sol_resume_medium
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_resume_medium_c29d2bf03ef7c18a.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8xml/XmlSerializer.h", "roc_xml_native_legacy_parser_headerb864cade0382cfdc.cpp")
#include "util/ContentProvider.h"
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
typedef char NativeContentIdSize[sizeof(RBX::ContentId)==32?1:-1];
typedef char NativeParserSize[sizeof(TextXmlParser)==72?1:-1];
