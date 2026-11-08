// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// InsertDecalAction | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 1d93be19 | roc native-status --write
#include <afxwin.h>
#include <afxdlgs.h>
#include <fstream>
#include "InsertDecal.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/Decal.h"
#include "util/ContentProvider.h"
#include "util/ImageContent.h"
#include "v8datamodel/Workspace.h"

using namespace RBX;
namespace RBX {
inline const Name& Verb::getName() const { return name; }
void recordCameraHistory(const char*, const Instance*);
}

static __declspec(noinline) ContentId registerImageFile(const char* path)
{
    std::ifstream file(path, std::ios::in | std::ios::binary);
    return registerImageContent(file, getMimeType(path));
}

__forceinline const CString& InsertDecal::prepareImage(const CString& path)
{
    if (dataModel) ServiceProvider::create<ContentProvider>(static_cast<const ServiceProvider*>(dataModel));
    return path;
}

void InsertDecal::doIt(IDataState*)
{
    CString filter;
    filter.LoadString(132);
    CFileDialog dialog(TRUE, NULL, NULL, 0, filter, NULL, 0, TRUE);
    if (dialog.DoModal() == IDOK) {
        ContentId content = registerImageFile(prepareImage(dialog.GetPathName()));
        boost::shared_ptr<Decal> instance = createInstance();
        instance->setTexture(content);
        instance->setName(std::string(dialog.GetFileTitle()));
        instance->setParent(getTarget());
        (dataModel ? dataModel->create<Selection>() : 0)->setSelection(instance.get());
        recordCameraHistory(getName().c_str(), workspace.get());
    }
}
