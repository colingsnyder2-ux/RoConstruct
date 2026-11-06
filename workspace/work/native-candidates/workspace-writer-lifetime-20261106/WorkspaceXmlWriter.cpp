// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string
#include <afxwin.h>
#include "util/NativeContentProvider.h"
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include "v8xml/XmlSerializer.h"

// Candidate only: exact lifetime providers; caller EH state is still nonexact.
typedef char NativeWriterBaseSize[sizeof(TextXmlWriter) == 0x28 ? 1 : -1];
typedef char NativeEmbeddedWriterSize[sizeof(TextXmlWriterWithEmbeddedContent) == 0x4c ? 1 : -1];

HRESULT CWorkspace::write(XmlElement* element, std::ostream& stream)
{
    TextXmlWriterWithEmbeddedContent writer(dataModel ? RBX::ServiceProvider::create<RBX::ContentProvider>(dataModel.get()) : 0, stream);
    writer.serialize(element);
    return S_OK;
}
