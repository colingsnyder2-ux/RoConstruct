// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// InsertObjectAction | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src a8a2a9b5 | roc native-status --write
#include <afxwin.h>
#include <stdexcept>
#include <G3D/format.h>
#include "InsertObject.h"
#include "CInsertObjectDialog.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/Workspace.h"

using namespace RBX;
namespace RBX {
inline const Name& Verb::getName() const { return name; }
void recordCameraHistory(const char*, const Instance*);
}

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
