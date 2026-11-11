// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-metadata
// >>> native-status (generated) -- do not edit >>>
// MetadataReflectionSingleton | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src a79de32a | roc native-status --write
#include <afxwin.h>
#include <afxpriv.h>
#include <shlwapi.h>
#include "reflection/Metadata.h"
namespace RBX { namespace Metadata {
boost::shared_ptr<Reflection> Reflection::singleton()
{
    static boost::shared_ptr<Reflection> cached;
    if (!cached) {
        cached = Creatable<Instance>::create<Reflection>();
        CString filename;
        AfxGetModuleShortFileName(AfxGetApp()->m_hInstance, filename);
        CString directory((const char*)filename);
        PathRemoveFileSpecA(directory.GetBuffer(directory.GetLength()));
        directory.ReleaseBuffer();
        cached->load((const char*)(directory + "\\ReflectionMetadata.xml"));
    }
    return cached;
}
}}
