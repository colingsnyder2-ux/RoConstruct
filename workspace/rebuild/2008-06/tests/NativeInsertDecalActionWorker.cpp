#pragma include_alias(<atlsimpstr.h>, <roc_espeon_editorcstringheaderfb14fe2507201232.cpp>)
#pragma include_alias(<xstring>, <roc_dom_native_stdstring_cstr_boundary_header3da8e64d105bf835.cpp>)
#include <afxwin.h>
#include <afxdlgs.h>
#include <fstream>
#include "StandardVerbs.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/Decal.h"
#include "util/ContentProvider.h"
#include "v8datamodel/Workspace.h"
using namespace RBX;
namespace RBX { void recordCameraHistory(const char*,const Instance*); inline const Name& Verb::getName() const { return name; } }
namespace RBX { const Name& getMimeType(const char*); ContentId registerImageContent(std::istream&,const Name&); }
static __declspec(noinline) ContentId registerImageFile(const char* path) { std::ifstream f(path,std::ios::in|std::ios::binary); return registerImageContent(f,getMimeType(path)); }
class InsertDecal : public EditSelectionVerb {
 Instance* getTarget() const;
public:
 virtual bool isEnabled() const;
 virtual void doIt(IDataState*);
protected:
 virtual boost::shared_ptr<Decal> createInstance();
 __forceinline const CString& prepareImage(const CString& path) { if (dataModel) ServiceProvider::create<ContentProvider>(static_cast<const ServiceProvider*>(dataModel)); return path; }
};
void InsertDecal::doIt(IDataState*) {
 CString filter; filter.LoadString(132);
 CFileDialog dialog(TRUE,NULL,NULL,0,filter,NULL,0,TRUE);
 if (dialog.DoModal()==IDOK) {
  ContentId content=registerImageFile(prepareImage(dialog.GetPathName()));
  boost::shared_ptr<Decal> instance=createInstance();
  instance->setTexture(content);
  instance->setName(std::string(dialog.GetFileTitle()));
  instance->setParent(getTarget());
  (dataModel ? dataModel->create<Selection>() : 0)->setSelection(instance.get());
  recordCameraHistory(getName().c_str(),workspace.get());
 }
}
