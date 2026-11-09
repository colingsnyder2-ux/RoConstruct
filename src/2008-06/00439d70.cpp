// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
#include <stddef.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
namespace boost {namespace detail {
struct sp_counted_base {virtual ~sp_counted_base(){}virtual void dispose()=0;virtual void destroy(){delete this;}long use_count_,weak_count_;void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}};
struct shared_count {sp_counted_base*pi_;shared_count():pi_(0){}shared_count(const shared_count&r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}~shared_count(){if(pi_)pi_->release();}};
}
template<class T>struct shared_ptr {T*px;detail::shared_count pn;shared_ptr():px(0),pn(){}shared_ptr(const shared_ptr&r):px(r.px),pn(r.pn){}};
struct recursive_mutex {char opaque[12];void lock();void unlock();struct scoped_lock {recursive_mutex&mutex;bool locked;scoped_lock(recursive_mutex&m):mutex(m){mutex.lock();locked=true;}~scoped_lock(){if(locked)mutex.unlock();}};};
}
namespace RBX {
struct Instance;struct PropertyChanged;struct Selection;struct SelectionChanged;
namespace Reflection {struct ClassDescriptor;}
template<class C,class E>struct Listener {virtual void onEvent(const C*,E)=0;virtual ~Listener(){}};
struct DataModel {struct Lock {boost::shared_ptr<boost::recursive_mutex>mutex;void*lock;void doLock(const DataModel*);Lock(const DataModel*dm):mutex(),lock(0){doLock(dm);}~Lock();};};
}
struct CRuntimeClass;struct CArchive;struct CDumpContext;
struct CObject {virtual CRuntimeClass*GetRuntimeClass()const;virtual ~CObject();virtual void Serialize(CArchive&);virtual void AssertValid()const;virtual void Dump(CDumpContext&)const;};
struct CCmdTarget:CObject {char opaque[0x20-4];};
struct CXTPCmdTarget:CCmdTarget {};
struct CXTPPropertyGridUpdateContext:CXTPCmdTarget {char opaque[40];CXTPPropertyGridUpdateContext();virtual ~CXTPPropertyGridUpdateContext();};
struct CXTPPropertyGridItem;
struct CXTPPropertyGridItems:CObject {char opaque[0x28-4];int count;long GetCount()const{return count;}CXTPPropertyGridItem*GetAt(int)const;};
struct CXTPPropertyGridItem:CObject {char opaque[0xc0-4];CXTPPropertyGridItems*children;CXTPPropertyGridItems*GetChilds()const{return children;}int IsHidden()const;void SetHidden(int);};
struct CXTPPropertyGrid:CObject {char opaque[0x188-4];void BeginUpdate(CXTPPropertyGridUpdateContext&);void EndUpdate(CXTPPropertyGridUpdateContext&);CXTPPropertyGridItems*GetCategories()const;void RedrawControl();};
void*getRebuildSource();
struct CPropGrid:CXTPPropertyGrid,RBX::Listener<RBX::Instance,RBX::PropertyChanged> {
 typedef std::vector<boost::shared_ptr<RBX::Instance> >Instances;
 typedef std::map<const RBX::Reflection::ClassDescriptor*,Instances>Selection;
 struct Item {virtual void update(Selection*)=0;};
 boost::recursive_mutex mutex;RBX::DataModel*dataModel;std::vector<Item*>allItems;char opaque1b4[0x1f4-0x1b4];bool refreshQueued,updateAll;char opaque1f6[2];std::set<Item*>pendingItems;Selection selection;
 void rebuild(void*);
};
struct CSelectionPropGrid:CPropGrid,RBX::Listener<RBX::Selection,RBX::SelectionChanged> {long refresh(unsigned,unsigned);};
long CSelectionPropGrid::refresh(unsigned,unsigned){
 if(allItems.size()==0){CXTPPropertyGridUpdateContext context;BeginUpdate(context);rebuild(getRebuildSource());EndUpdate(context);}
 std::vector<Item*>items;std::set<Item*>pending;
 {boost::recursive_mutex::scoped_lock guard(mutex);
  if(updateAll){items=allItems;updateAll=false;}else{pending=pendingItems;pendingItems.clear();}
  refreshQueued=false;
 }
 {RBX::DataModel::Lock lock(dataModel);
  std::for_each(items.begin(),items.end(),std::bind2nd(std::mem_fun(&Item::update),&selection));
  std::for_each(pending.begin(),pending.end(),std::bind2nd(std::mem_fun(&Item::update),&selection));
 }
 for(int i=0;i<GetCategories()->GetCount();++i){
  CXTPPropertyGridItem*category=GetCategories()->GetAt(i);CXTPPropertyGridItems*children=category->GetChilds();
  bool allHidden=true;
  for(int j=0;j<children->GetCount();++j){if(!children->GetAt(j)->IsHidden()){allHidden=false;break;}}
  category->SetHidden(allHidden);
 }
 RedrawControl();
 return 0;
}

typedef char context_size[sizeof(CXTPPropertyGridUpdateContext)==72?1:-1];
typedef char scoped_lock_size[sizeof(boost::recursive_mutex::scoped_lock)==8?1:-1];
typedef char data_model_lock_size[sizeof(RBX::DataModel::Lock)==12?1:-1];
typedef char item_vector_size[sizeof(std::vector<CPropGrid::Item*>)==24?1:-1];
typedef char item_set_size[sizeof(std::set<CPropGrid::Item*>)==32?1:-1];
typedef char selection_size[sizeof(CPropGrid::Selection)==32?1:-1];
typedef char prop_grid_size[sizeof(CPropGrid)==0x238?1:-1];
typedef char mutex_offset[offsetof(CPropGrid,mutex)==0x18c?1:-1];
typedef char data_model_offset[offsetof(CPropGrid,dataModel)==0x198?1:-1];
typedef char all_items_offset[offsetof(CPropGrid,allItems)==0x19c?1:-1];
typedef char pending_items_offset[offsetof(CPropGrid,pendingItems)==0x1f8?1:-1];
typedef char selection_offset[offsetof(CPropGrid,selection)==0x218?1:-1];
