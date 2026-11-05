// from server: 100% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <vector>

template <class T> class bstr {
public:
    __declspec(noinline) bstr() { _Mysize = 0; }
    __declspec(noinline) ~bstr() { _Mysize = 0; }
    __declspec(noinline) bstr& operator=(const bstr& r) { _Mysize = r._Mysize; return *this; }
    __declspec(noinline) bstr& operator=(const T* r) { _Mysize = 0; return *this; }
    __declspec(noinline) const T* c_str() const { return _Buf; }
    __declspec(noinline) unsigned int size() const { return _Mysize; }
    void* _Myaux;
    T _Buf[16];
    unsigned int _Mysize;
    unsigned int _Myres;
};
extern template class __declspec(dllimport) bstr<char>;
typedef bstr<char> string_;
__declspec(dllimport) bool operator==(const string_&, const char*);

namespace boost {
struct lock_error { lock_error(); };
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) _InterlockedIncrement(&pi_->use_count_); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    template<class Y> shared_ptr(const shared_ptr<Y>& r) : px(r.px), pn(r.pn) {}
    void reset();
    T* get() const { return px; }
    T* operator->() const { return px; }
    T& operator*() const { return *px; }
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};

}

namespace RBX {
class RunService { public: char pad[0x1b4]; int runState; void setRunState(int s); };
class Visit { public: string_ getUploadUrl() const; };
class ServiceProvider {
public:
    virtual ~ServiceProvider();
    template<class T> T* findServiceT() const;
    template<class T> static T* find(const ServiceProvider* context)
    {
        return context ? context->findServiceT<T>() : 0;
    }
};
class DataModel : public ServiceProvider {};
class ReadRequest {
public:
    ReadRequest(boost::shared_ptr<const DataModel> dm);
    ~ReadRequest();
    void* a; void* b; void* c;
};
}
extern "C" __declspec(dllimport) int __stdcall SetForegroundWindow(void* hWnd);
extern "C" __declspec(dllimport) int __stdcall FlashWindow(void* hWnd, int bInvert);

class CWnd { public: virtual ~CWnd(); char pad[0x1c]; void* m_hWnd; };
class CWinThread { public:
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
    virtual CWnd* GetMainWnd();
};
CWinThread* __stdcall AfxGetThread();
inline CWnd* AfxGetMainWnd()
{
    CWinThread* pThread = AfxGetThread();
    return pThread != 0 ? pThread->GetMainWnd() : 0;
}

class CRobloxView { public: boost::shared_ptr<RBX::DataModel> getDataModel(); };
class CPublishDialog {
public:
    CPublishDialog(CRobloxView* view, CWnd* parent = 0);
    ~CPublishDialog();
    int DoModal();
    char data[0x130];
};

class CDocument {
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
    virtual int IsModified();
    int SaveModified();
};

class CRobloxDoc : public CDocument {
public:
    char pad[0x90];
    CRobloxView* view;
    boost::shared_ptr<RBX::DataModel> getDataModel();
    int SaveModified();
};

int CRobloxDoc::SaveModified()
{
    if (!view || !view->getDataModel())
        return 1;
    if (!IsModified())
        return 1;
    RBX::ReadRequest request(getDataModel());
    bool wasRunning = RBX::ServiceProvider::find<RBX::RunService>(getDataModel().get())->runState == 1;
    RBX::ServiceProvider::find<RBX::RunService>(getDataModel().get())->setRunState(2);
    RBX::Visit* visit = RBX::ServiceProvider::find<RBX::Visit>(getDataModel().get());
    if (!visit || visit->getUploadUrl() == "NoVisit") {
        SetForegroundWindow(AfxGetMainWnd()->m_hWnd);
        return CDocument::SaveModified();
    }
    if (visit->getUploadUrl().size() == 0)
        return 1;
    FlashWindow(AfxGetMainWnd()->m_hWnd, 0);
    CPublishDialog dlg(view, 0);
    int result = dlg.DoModal() == 1;
    if (!result && wasRunning)
        RBX::ServiceProvider::find<RBX::RunService>(view->getDataModel().get())->setRunState(1);
    return result;
}
