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

#include <stdexcept>
#include <G3D/format.h>
#include "InsertObject.h"
#include "CInsertObjectDialog.h"

Instance* InsertObject::target() const {
    Selection* selected = ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
    size_t count = selected->size();
    if (count == 1) return selected->front().get();
    if (count == 0) return dataModel->getWorkspace();
    return NULL;
}
void InsertObject::doIt(IDataState*) {
    if (!target()) throw std::runtime_error("InsertObject: Target Instance is NULL");
    boost::shared_ptr<Instance> parent = shared_from(target());
    CInsertObjectDialog dialog(parent, NULL);
    dialog.className = AfxGetApp()->GetProfileString("InsertObject", "ClassName", NULL).GetBuffer();
    if (dialog.DoModal() == IDOK) {
        const char* (CString::*convert)() const = &CString::operator const char*;
        AfxGetApp()->WriteProfileString("InsertObject", "ClassName", (dialog.className.*convert)());
        boost::shared_ptr<Instance> instance = dialog.selected;
        if (!instance) {
            CString error; error.Format(133, dialog.className);
            std::string message((error.*convert)());
            throw std::runtime_error(message);
        }
        if (parent && !parent->canAddChild(instance.get()))
            throw std::runtime_error(G3D::format("%s cannot be a child of %s", instance->getClassNameStr().c_str(), parent->getName().c_str()));
        instance->setParent(parent.get());
        ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel))->setSelection(instance.get());
        recordCameraHistory(getName().c_str(), dataModel);
    }
}
