#include <afxwin.h>
#define NATIVE_CONTENT_PROVIDER_TYPES_ONLY
#include "NativeContentProviderTrial.cpp"
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include "v8xml/XmlSerializer.h"

TextXmlWriterWithEmbeddedContent::TextXmlWriterWithEmbeddedContent(RBX::ContentProvider* provider, std::ostream& stream)
    : TextXmlWriter(stream), contentProvider(provider) {}

TextXmlWriterWithEmbeddedContent::~TextXmlWriterWithEmbeddedContent() {}

HRESULT CWorkspace::write(XmlElement* element, std::ostream& stream) {
    TextXmlWriterWithEmbeddedContent writer(dataModel ? RBX::ServiceProvider::create<RBX::ContentProvider>(dataModel.get()) : 0, stream);
    writer.serialize(element);
    return S_OK;
}
