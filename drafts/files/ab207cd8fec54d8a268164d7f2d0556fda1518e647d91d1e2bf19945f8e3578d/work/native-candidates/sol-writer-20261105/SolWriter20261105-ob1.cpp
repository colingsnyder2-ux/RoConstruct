// native-flags: /O2 /Ob1 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string /I{headers}/../../../work/native-candidates/writer-lifetime-20261105/include
#include <afxwin.h>
#include "util/NativeContentProvider.h"
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include "v8xml/XmlSerializer.h"

HRESULT CWorkspace::write(XmlElement* element, std::ostream& stream)
{
    TextXmlWriterWithEmbeddedContent writer(dataModel ? RBX::ServiceProvider::create<RBX::ContentProvider>(dataModel.get()) : 0, stream);
    writer.serialize(element);
    return S_OK;
}
