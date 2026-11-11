// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// DocumentLoadFile | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 55debcbf | roc native-status --write
#include <afxwin.h>
#include "CRobloxDoc.h"
#include "v8datamodel/DataModel.h"
#include "util/ContentProvider.h"

static RBX::ContentProvider* contentProvider(RBX::DataModel* model)
{
    return model ? model->create<RBX::ContentProvider>() : NULL;
}

int CRobloxDoc::loadFile(std::string path)
{
    if (RBX::ContentProvider::isUrl(path.c_str()))
        path = contentProvider(getDataModel().get())->getFile(RBX::ContentId(path.c_str()));
    CString contents;
    {
        CFile file(path.c_str(), CFile::modeRead);
        char buffer[0x1000];
        unsigned count;
        do {
            count = file.Read(buffer, 0xfff);
            buffer[count] = 0;
            contents += buffer;
        } while (count);
    }
    return loadFromString(std::string((const char*)contents));
}
