// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_workspacepositiveitemsfd18f79fafefab0d.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("util/IRenderable.h", "roc_espeon_renderableindexaccessae7c6fa24fc9f234.cpp")
#pragma include_alias("v8xml/XmlSerializer.h", "roc_ldraw_native_parser_prefix66bda9c32708866c.cpp")
#include "util/ContentProvider.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/SerializerV2.h"
namespace RBX {
ContentProvider* providerFor(Instance*);
void Workspace::insertItems(XmlElement* root, std::vector<boost::shared_ptr<Instance> >& items, InsertMode insertMode, PromptMode promptMode) {
 SerializerV2 serializer;
 serializer.loadInstances(root,items);
 if(items.size()>0) insertInstances(items,this,insertMode,promptMode);
}
void Workspace::insertContent(ContentId contentId, std::vector<boost::shared_ptr<Instance> >& items, InsertMode insertMode, PromptMode promptMode) {
 std::auto_ptr<std::istream> stream=providerFor(this)->getContent(contentId);
 TextXmlParser machine(stream->rdbuf());
 std::auto_ptr<XmlElement> root=machine.parse();
 insertItems(root.get(),items,insertMode,promptMode);
}
}
