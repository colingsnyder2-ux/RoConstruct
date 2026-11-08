#include <afxwin.h>
#include <afxdlgs.h>
#include <afxcmn.h>
#include <boost/shared_ptr.hpp>
#include <vector>
#include <stdexcept>
#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"
using namespace RBX;
class CClassImages : public CImageList { public: CClassImages(); virtual ~CClassImages(); };
class CInsertObjectDialog : public CDialog {
public:
    boost::shared_ptr<Instance> selected;
    std::vector<boost::shared_ptr<Instance> > objects;
    CString title;
    boost::shared_ptr<Instance> result;
    CClassImages images;
    CListCtrl list;
    CInsertObjectDialog(boost::shared_ptr<Instance>, CWnd*);
    virtual ~CInsertObjectDialog();
};
class InsertService : public RunStateVerb {
public:
    virtual void doIt(IDataState*);
};
void InsertService::doIt(IDataState*) {
    boost::shared_ptr<Instance> empty;
    CInsertObjectDialog dialog(empty, NULL);
    dialog.title=AfxGetApp()->GetProfileString("InsertService", "ClassName", NULL).GetBuffer();
    if (dialog.DoModal()==IDOK) {
        const char* (CString::*convert)() const = &CString::operator const char*;
        AfxGetApp()->WriteProfileString("InsertService", "ClassName", (dialog.title.*convert)());
        boost::shared_ptr<Instance> instance=dialog.result;
        if (!instance) {
            CString error; error.Format(133, dialog.title);
            std::string message((error.*convert)());
            throw std::runtime_error(message);
        }
        if (!ServiceProvider::create(dataModel, instance->getClassName())) {
            CString error; error.Format(137, dialog.title);
            std::string message((error.*convert)());
            throw std::runtime_error(message);
        }
    }
}
