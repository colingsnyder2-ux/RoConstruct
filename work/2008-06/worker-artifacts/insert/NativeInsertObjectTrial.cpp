#include <afxwin.h>
#include <afxdlgs.h>
#include <boost/shared_ptr.hpp>
#include <vector>
#include <stdexcept>
#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"
using namespace RBX;
class CInsertObjectDialog : public CDialog {
public:
    boost::shared_ptr<Instance> selected;
    std::vector<boost::shared_ptr<Instance> > objects;
    CString title;
    boost::shared_ptr<Instance> result;
    unsigned char unknown[0x5c];
    CInsertObjectDialog(boost::shared_ptr<Instance>, CWnd*);
    virtual ~CInsertObjectDialog();
};
namespace RBX { std::string format(const char*, ...); void recordInsertHistory(const char*, DataModel*); }
#include "v8datamodel/Selection.h"
class InsertObject : public RunStateVerb {
    Instance* target();
public:
    virtual void doIt(IDataState*);
};
void InsertObject::doIt(IDataState*) {
    if (!target()) throw std::runtime_error("InsertObject: Target Instance is NULL");
    boost::shared_ptr<Instance> parent=shared_from(target());
    CInsertObjectDialog dialog(parent, NULL);
    dialog.title=AfxGetApp()->GetProfileString("InsertObject", "ClassName", NULL).GetBuffer();
    if (dialog.DoModal()==IDOK) {
        const char* (CString::*convert)() const = &CString::operator const char*;
        AfxGetApp()->WriteProfileString("InsertObject", "ClassName", (dialog.title.*convert)());
        boost::shared_ptr<Instance> instance=dialog.result;
        if (!instance) {
            CString error; error.Format(133, dialog.title);
            std::string message((error.*convert)());
            throw std::runtime_error(message);
        }
        if (parent && !parent->canAddChild(instance.get()))
            throw std::runtime_error(format("%s cannot be a child of %s", instance->getClassNameStr().c_str(), parent->getName().c_str()));
        instance->setParent(parent.get());
        ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel))->setSelection(instance.get());
        recordInsertHistory(getName().c_str(), dataModel);
    }
}
