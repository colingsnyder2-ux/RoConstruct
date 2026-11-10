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
#include "v8datamodel/Selection.h"
#include "v8datamodel/Workspace.h"
#include <G3D/format.h>
extern template const char* std::basic_string<char>::c_str() const;
namespace RBX { inline const Name& Verb::getName() const { return name; } }
namespace RBX { void recordCameraHistory(const char*, const Instance*); }
class InsertObject : public RunStateVerb {
 Instance* target() const;
public: virtual void doIt(IDataState*);
};
Instance* InsertObject::target() const {
 Selection* selected=ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
 size_t count=selected->size();
 if (count==1) return selected->front().get();
 if (count==0) return dataModel->getWorkspace();
 return NULL;
}
