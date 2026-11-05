// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose()=0;
    virtual void destroy(){delete this;}
    long use_count_,weak_count_;
    void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
    void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count():pi_(0){}
    shared_count& operator=(const shared_count& r){sp_counted_base* tmp=r.pi_;if(tmp!=pi_){if(tmp)_InterlockedIncrement(&tmp->use_count_);if(pi_)pi_->release();pi_=tmp;}return *this;}
    void swap(shared_count& r){sp_counted_base* tmp=r.pi_;r.pi_=pi_;pi_=tmp;}
    shared_count(const shared_count& r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}
    ~shared_count(){if(pi_)pi_->release();}
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr():px(0),pn(){}
    shared_ptr& operator=(const shared_ptr& r){px=r.px;pn=r.pn;return *this;}
    void swap(shared_ptr& r){T* tmp=r.px;r.px=px;px=tmp;pn.swap(r.pn);}
    void reset();
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type()const{return px==0?0:&shared_ptr::px;}
    shared_ptr(const shared_ptr& r):px(r.px),pn(r.pn){}
    template<class Y> shared_ptr(const shared_ptr<Y>& r):px(r.px),pn(r.pn){}
    T* get()const{return px;}
    T* operator->()const{return px;}
};
template<class T,class U> bool operator==(const shared_ptr<T>& a,const shared_ptr<U>& b){return a.get()==b.get();}
}

typedef void* HWND;
typedef unsigned int UINT_PTR;
extern "C" __declspec(dllimport) UINT_PTR __stdcall SetTimer(HWND,UINT_PTR,unsigned int,void(__stdcall*)(HWND,unsigned int,UINT_PTR,unsigned long));
extern "C" __declspec(dllimport) int __stdcall KillTimer(HWND,UINT_PTR);

namespace RBX {
class Instance;
struct ChildAdded {};
struct ChildRemoved {};
template<typename Class, typename Event>
class __declspec(novtable) Listener
{
protected:
    virtual void onEvent(const Class*, Event) = 0;
    virtual ~Listener() {}
};
template<typename Class, typename Event>
class Notifier
{
public:
    void addListener(Listener<Class, Event>* listener) const;
    void removeListener(Listener<Class, Event>* listener) const;
};
class Instance
{
public:
    char pad0[0x24];
    Notifier<Instance, ChildAdded> childAddedNotifier;
    char pad1[0x44 - 0x25];
    Notifier<Instance, ChildRemoved> childRemovedNotifier;
};
boost::shared_ptr<Instance> shared_from(Instance* p);
class Stats;
class DataModel
{
public:
    void stopStats();
    Instance* getStats();
    void startStats();
    class scoped_write_request
    {
        void* a; void* b; void* c;
    public:
        scoped_write_request(boost::shared_ptr<DataModel> dataModel);
        ~scoped_write_request();
    };
};
}

class CXTPReportRecords { public: void RemoveAll(); };
class CXTPReportControl {
public:
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void r24();
    virtual void r25();
    virtual void r26();
    virtual void r27();
    virtual void r28();
    virtual void r29();
    virtual void r30();
    virtual void r31();
    virtual void r32();
    virtual void r33();
    virtual void r34();
    virtual void r35();
    virtual void r36();
    virtual void r37();
    virtual void r38();
    virtual void r39();
    virtual void r40();
    virtual void r41();
    virtual void r42();
    virtual void r43();
    virtual void r44();
    virtual void r45();
    virtual void r46();
    virtual void r47();
    virtual void r48();
    virtual void r49();
    virtual void r50();
    virtual void r51();
    virtual void r52();
    virtual void r53();
    virtual void r54();
    virtual void r55();
    virtual void r56();
    virtual void r57();
    virtual void r58();
    virtual void r59();
    virtual void r60();
    virtual void r61();
    virtual void r62();
    virtual void r63();
    virtual void r64();
    virtual void r65();
    virtual void r66();
    virtual void r67();
    virtual void r68();
    virtual void r69();
    virtual void r70();
    virtual void r71();
    virtual void r72();
    virtual void r73();
    virtual void r74();
    virtual void r75();
    virtual void r76();
    virtual void r77();
    virtual void r78();
    virtual void r79();
    virtual void r80();
    virtual void r81();
    virtual void r82();
    virtual void r83();
    virtual void r84();
    virtual void r85();
    virtual void r86();
    virtual void r87();
    virtual void Populate();
    char pad[0xe8 - 4];
    CXTPReportRecords* m_pRecords;
    CXTPReportRecords* GetRecords() const { return m_pRecords; }
};

template<class Event>
class StatsListener : public RBX::Listener<RBX::Instance, Event>
{
public:
    void onEvent(const RBX::Instance*, Event);
    void detach();
    char pad[0x24 - 4];
};

class CRobloxReportView
{
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual CXTPReportControl& GetReportCtrl();
    char pad0[0x20 - 4];
    HWND m_hWnd;
    char pad1[0x378 - 0x24];
    StatsListener<RBX::ChildAdded> childAddedListener;
    StatsListener<RBX::ChildRemoved> childRemovedListener;
    UINT_PTR timer;
    boost::shared_ptr<RBX::DataModel> dataModel;
    boost::shared_ptr<RBX::Instance> stats;
    void setDataModel(boost::shared_ptr<RBX::DataModel> dataModel);
};

void CRobloxReportView::setDataModel(boost::shared_ptr<RBX::DataModel> dataModel)
{
    if (dataModel == this->dataModel)
        return;

    if (this->dataModel)
    {
        RBX::DataModel::scoped_write_request request(this->dataModel);
        if (this->dataModel.get())
            this->dataModel->stopStats();
        StatsListener<RBX::ChildAdded>* added = &childAddedListener;
        if (stats)
            stats->childAddedNotifier.removeListener(added);
        StatsListener<RBX::ChildRemoved>* removed = &childRemovedListener;
        if (stats)
            stats->childRemovedNotifier.removeListener(removed);
        added->detach();
        removed->detach();
        GetReportCtrl().GetRecords()->RemoveAll();
    }
    GetReportCtrl().Populate();

    stats.reset();
    this->dataModel = dataModel;

    if (this->dataModel)
    {
        RBX::DataModel::scoped_write_request request(dataModel);
        stats = RBX::shared_from(this->dataModel.get() ? this->dataModel->getStats() : NULL);
        timer = ::SetTimer(m_hWnd, 1, 333, NULL);
        RBX::Instance* removedSource=stats.get();
        StatsListener<RBX::ChildRemoved>* removed=&childRemovedListener;
        if (removedSource)
            removedSource->childRemovedNotifier.addListener(removed);
        RBX::Instance* addedSource=stats.get();
        StatsListener<RBX::ChildAdded>* added=&childAddedListener;
        if (addedSource)
            addedSource->childAddedNotifier.addListener(added);
        if (this->dataModel.get())
            this->dataModel->startStats();
    }
    else if (m_hWnd)
    {
        UINT_PTR activeTimer=timer;
        ::KillTimer(m_hWnd, activeTimer);
    }
}
