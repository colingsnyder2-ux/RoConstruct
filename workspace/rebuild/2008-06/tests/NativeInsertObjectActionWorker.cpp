#pragma include_alias(<xstring>, <roc_dom_native_stdstring_cstr_boundary_header3da8e64d105bf835.cpp>)
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
void InsertObject::doIt(IDataState*) {
 if (!target()) { throw std::runtime_error("InsertObject: Target Instance is NULL"); }
 boost::shared_ptr<Instance> parent = shared_from(target());
 CInsertObjectDialog dialog(parent,NULL);
 dialog.title=AfxGetApp()->GetProfileString("InsertObject","ClassName",NULL).GetBuffer();
 if (dialog.DoModal()==IDOK) {
  const char* (CString::*convert)() const = &CString::operator const char*;
  AfxGetApp()->WriteProfileString("InsertObject","ClassName",(dialog.title.*convert)());
  boost::shared_ptr<Instance> instance=dialog.result;
  if (!instance) { CString error; error.Format(133,dialog.title); std::string message((error.*convert)()); throw std::runtime_error(message); }
  if (parent && !parent->canAddChild(instance.get())) { throw std::runtime_error(G3D::format("%s cannot be a child of %s",instance->getClassNameStr().c_str(),parent->getName().c_str())); }
  instance->setParent(parent.get());
  ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel))->setSelection(instance.get());
  recordCameraHistory(getName().c_str(),dataModel);
 }
}

