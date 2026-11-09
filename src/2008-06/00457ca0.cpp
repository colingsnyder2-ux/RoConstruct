// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
#include <vector>
namespace boost {namespace detail {
struct sp_counted_base {
 virtual ~sp_counted_base(){}virtual void dispose()=0;virtual void destroy(){delete this;}
 long use_count_,weak_count_;
 void add_ref_copy(){_InterlockedIncrement(&use_count_);}void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
 void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
struct shared_count {sp_counted_base*pi_;shared_count():pi_(0){}shared_count(const shared_count&r):pi_(r.pi_){if(pi_)pi_->add_ref_copy();}~shared_count(){if(pi_)pi_->release();}};
}
template<class T>struct shared_ptr {
 T*px;detail::shared_count pn;
 shared_ptr():px(0),pn(){}shared_ptr(const shared_ptr&r):px(r.px),pn(r.pn){}
 template<class U>shared_ptr(const shared_ptr<U>&r):px(r.px),pn(r.pn){}
 T*get()const{return px;}T*operator->()const{return px;}
};
}
namespace RBX {
struct Instance;
struct ChildAdded {boost::shared_ptr<Instance>child;};struct ChildRemoved {boost::shared_ptr<Instance>child;};
struct DataModel {struct Lock {char opaque[12];Lock(boost::shared_ptr<const DataModel>);~Lock();};};
namespace Stats {struct Item;}
template<class C,class E>struct Listener {virtual void onEvent(const C*,E)=0;virtual ~Listener(){}};
template<class C,class E,class Source=C,class SourceEvent=E>struct MarshaledListener:Listener<C,E> {
 std::vector<E>pending;unsigned long threadId;void*context;
 MarshaledListener();virtual ~MarshaledListener();virtual void onEvent(const C*,E);
 virtual void handleMarshaled(const C*,E)=0;virtual void queueEvent(const C*,E);
};
template<class E>struct NotifierOffset;
template<>struct NotifierOffset<ChildAdded>{enum{value=0x24};};template<>struct NotifierOffset<ChildRemoved>{enum{value=0x44};};
template<class C,class E>struct Notifier {
 virtual ~Notifier();char opaque[28];void addListener(Listener<C,E>*)const;
 template<class T>static void connect(const boost::shared_ptr<T>&p,Listener<C,E>*listener){
  if(p.get())reinterpret_cast<const Notifier*>(reinterpret_cast<const char*>(p.get())+NotifierOffset<E>::value)->addListener(listener);
 }
};
}
struct MutexRef {char opaque[8];MutexRef(boost::shared_ptr<RBX::DataModel>);~MutexRef();};
struct CRuntimeClass;struct CArchive;struct CDumpContext;
struct CObject {virtual CRuntimeClass*GetRuntimeClass()const;virtual ~CObject();virtual void Serialize(CArchive&);virtual void AssertValid()const;virtual void Dump(CDumpContext&)const;};
struct CCmdTarget:CObject {char opaque[0x20-4];};
struct CXTPReportDataAllocator;
template<class T,class Allocator>struct CXTPHeapObjectT:T {static void*__stdcall operator new(unsigned);static void __stdcall operator delete(void*);};
struct CXTPReportRecordItem:CXTPHeapObjectT<CCmdTarget,CXTPReportDataAllocator> {char opaque[0x7c-0x20];virtual ~CXTPReportRecordItem();};
struct XTP_REPORTRECORDITEM_DRAWARGS;struct XTP_REPORTRECORDITEM_METRICS;struct CXTPPropExchange;
struct CXTPReportRecord:CXTPHeapObjectT<CCmdTarget,CXTPReportDataAllocator> {
 char opaque[0x54-0x20];CXTPReportRecord();virtual ~CXTPReportRecord();
 virtual void GetItemMetrics(XTP_REPORTRECORDITEM_DRAWARGS*,XTP_REPORTRECORDITEM_METRICS*);virtual int IsFiltered()const;virtual void DoPropExchange(CXTPPropExchange*);
 CXTPReportRecordItem*AddItem(CXTPReportRecordItem*);
};
struct CRobloxReportView {
 struct CStatsItemRecord:CXTPReportRecord,MutexRef,RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded>,RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved> {
  // The constructor leaves this measured four-byte region unobserved.
  char opaqueA4[4];boost::shared_ptr<RBX::Stats::Item>item;
  CStatsItemRecord(boost::shared_ptr<RBX::Stats::Item>,boost::shared_ptr<RBX::DataModel>);
  virtual ~CStatsItemRecord();virtual void handleMarshaled(const RBX::Instance*,RBX::ChildAdded);virtual void handleMarshaled(const RBX::Instance*,RBX::ChildRemoved);
  struct CNameItem:MutexRef,CXTPReportRecordItem {RBX::Stats::Item*item;CNameItem(RBX::Stats::Item*,boost::shared_ptr<RBX::DataModel>);virtual ~CNameItem();};
  struct CValueItem:MutexRef,CXTPReportRecordItem {RBX::Stats::Item*item;CValueItem(RBX::Stats::Item*,boost::shared_ptr<RBX::DataModel>);virtual ~CValueItem();};
 };
};
typedef char VerifiedExtents[(sizeof(MutexRef)==8&&sizeof(CXTPReportRecord)==0x54&&sizeof(RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded>)==0x24&&sizeof(CRobloxReportView::CStatsItemRecord::CNameItem)==0x88&&sizeof(CRobloxReportView::CStatsItemRecord)==0xb0)?1:-1];
CRobloxReportView::CStatsItemRecord::CStatsItemRecord(boost::shared_ptr<RBX::Stats::Item>stats,boost::shared_ptr<RBX::DataModel>dm)
 :CXTPReportRecord(),MutexRef(dm),RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded>(),RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved>(),item(stats){
 AddItem(new CNameItem(stats.get(),dm));
 AddItem(new CValueItem(stats.get(),dm));
 RBX::DataModel::Lock lock(dm);
 RBX::Notifier<RBX::Instance,RBX::ChildAdded>::connect(stats,this);
 RBX::Notifier<RBX::Instance,RBX::ChildRemoved>::connect(stats,this);
}
