// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
#include <string>
#include <memory>

struct HWND__; typedef HWND__* HWND; struct tagRECT;
extern "C" __declspec(dllimport) int __stdcall InvalidateRect(HWND, const tagRECT*, int);
struct _GUID;
struct IUnknown {
    virtual long __stdcall QueryInterface(const _GUID&, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

namespace ATL {
inline IUnknown* __stdcall AtlComPtrAssign(IUnknown** pp, IUnknown* lp)
{
    if (pp == 0) return 0;
    if (lp != 0) lp->AddRef();
    if (*pp) (*pp)->Release();
    *pp = lp;
    return lp;
}
template<class T> class CComPtrBase {
protected:
    CComPtrBase() throw() : p(0) {}
public:
    ~CComPtrBase() throw() { if (p) p->Release(); }
    operator T*() const throw() { return p; }
    bool operator!=(T* pT) const { return !operator==(pT); }
    bool operator==(T* pT) const throw() { return p == pT; }
    T* p;
};
template<class T> class CComPtr : public CComPtrBase<T> {
public:
    T* operator=(T* lp) throw()
    {
        if (*this != lp)
            return static_cast<T*>(AtlComPtrAssign((IUnknown**)&p, lp));
        return *this;
    }
};
}

namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
    long use_count_;
    long weak_count_;
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};
}
template<class T> class shared_ptr {
public:
    typedef T* shared_ptr::*unspecified_bool_type;
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    template<class Y> shared_ptr(const shared_ptr<Y>& r) : px(r.px), pn(r.pn) {}
    template<class Y> shared_ptr& operator=(const shared_ptr<Y>& r) { px = r.px; pn = r.pn; return *this; }
    void reset();
    T* operator->() const { return px; }
    T* get() const { return px; }
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};
template<class T> class scoped_ptr {
    T* ptr;
public:
    explicit scoped_ptr(T* p = 0) : ptr(p) {}
    ~scoped_ptr() { delete ptr; }
    void reset(T* p = 0) { scoped_ptr<T>(p).swap(*this); }
    void swap(scoped_ptr& b) { T* tmp = b.ptr; b.ptr = ptr; ptr = tmp; }
    T* get() const { return ptr; }
    T* operator->() const { return ptr; }
};
}

namespace G3D {
class GWindow {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37();
    virtual void reallyMakeCurrent() const;
private:
    static const GWindow* m_current;
public:
    void makeCurrent() const { if (m_current != this) { reallyMakeCurrent(); m_current = this; } }
};
}

class RenderStats;
class CWnd;
namespace RBX {
class Adorn;
class Instance {
public:
    virtual ~Instance();
    virtual void setName(const std::string& name);
    void setParent(Instance* parent);
};
namespace Profiling { class Profiler; }
namespace Stats {
class Item : public Instance {
public:
    Item* createBoundChildItem(Profiling::Profiler* profiler);
};
class StatsService : public Instance {};
}
class UserInputBase {
public:
    virtual void v0();
    char pad[0x24];
    void init(Adorn* adorn);
};
class RunService;
class RunTransition { int a, b; }; class Heartbeat { float a, b; };
template<class C, class E> class Listener {
protected:
    virtual void onEvent(const C*, E) = 0;
public:
    virtual ~Listener() {}
};
class IRunView {
public:
    virtual void InvalidateRunView() = 0;
    virtual void AdjustThrottle(double) = 0;
};
class RunService {
public:
    void addRunView(IRunView* view);
    void removeRunView(IRunView* view);
};
class ControllerService {
public:
    char pad[0x130];
    UserInputBase* hardwareDevice;
};
class DataModel {
public:
    template<class T> T* find() const;
    template<class T> T* create() const;
    class Lock {
        int a, b, c;
    public:
        Lock(boost::shared_ptr<const DataModel> dataModel);
        ~Lock();
    };
};
class ServiceProvider {
public:
    template<class T> static T* find(const DataModel* context) { if (context) return context->find<T>(); return 0; }
    template<class T> static T* create(const DataModel* context) { if (context) return context->create<T>(); return 0; }
};
template<class T> boost::shared_ptr<T> shared_from(T* p);
class GameSettings {
public:
    static GameSettings& singleton();
    void apply(bool b);
};
class ViewBase {
public:
    virtual ~ViewBase();
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual RenderStats& getRenderStats() = 0;
};
class NativeDocument : public IUnknown {
public:
    boost::shared_ptr<DataModel> getDataModel();
};
}

class DxUserInput : public RBX::UserInputBase, public RBX::Listener<RBX::RunService, RBX::RunTransition>, public RBX::Listener<RBX::RunService, RBX::Heartbeat> {
    char tail[0x194 - 0x30];
public:
    DxUserInput(CWnd* wnd, RBX::DataModel* dataModel);
    void onEvent(const RBX::RunService*, RBX::RunTransition);
    void onEvent(const RBX::RunService*, RBX::Heartbeat);
};

template<class T> class Ptr { public: T* p; T* get() const { return p; } T* operator->() const { return p; } };
struct CRobloxWndPad { virtual ~CRobloxWndPad(); char pad04[0x1c]; HWND m_hWnd; char pad24[0x30]; };
class CRobloxWnd : public CRobloxWndPad, public RBX::IRunView {
public:
    class RenderStatsItem : public RBX::Stats::Item {};
    void InvalidateRunView();
    void AdjustThrottle(double);
    char pad58[4];
    int graphicsMode;
    char pad60[4];
    boost::shared_ptr<RBX::Stats::Item> stats;
    ATL::CComPtr<RBX::NativeDocument> document;
    boost::shared_ptr<RBX::DataModel> dataModel;
    boost::shared_ptr<RBX::RunService> runService;
    char pad80[4];
    boost::scoped_ptr<DxUserInput> userInput;
    char pad88[0x10];
    RBX::Profiling::Profiler* profiler;
    bool headless;
    char pad9d[7];
    G3D::GWindow* window;
    char pada8[8];
    std::auto_ptr<RBX::ViewBase> view;
    Ptr<RBX::Adorn> adorn;
    void setupOgre();
    void setupLegacy();
    void setupStatsGui();
    void setDocument(RBX::NativeDocument* doc);
};
boost::shared_ptr<CRobloxWnd::RenderStatsItem> createRenderStatsItem(RenderStats& stats);

void CRobloxWnd::setDocument(RBX::NativeDocument* doc)
{
    if (doc != document)
    {
        if (dataModel)
        {
            RBX::DataModel::Lock lock(dataModel);
            if (stats.get())
            {
                stats->setParent(0);
                stats.reset();
            }
            if (RBX::ControllerService* controller = RBX::ServiceProvider::find<RBX::ControllerService>(dataModel.get()))
                controller->hardwareDevice = 0;
            window->makeCurrent();
            view.reset();
            boost::shared_ptr<RBX::RunService>& run = runService;
            run->removeRunView(this);
            userInput.reset();
            run.reset();
        }
        document = doc;
        if (doc)
            dataModel = doc->getDataModel();
        else
            dataModel.reset();
        if (dataModel)
        {
            RBX::DataModel::Lock lock(dataModel);
            if (!headless)
                userInput.reset(new DxUserInput((CWnd*)this, dataModel.get()));
            runService = RBX::shared_from(RBX::ServiceProvider::create<RBX::RunService>(dataModel.get()));
            RBX::GameSettings::singleton().apply(false);
            if (graphicsMode == 2)
                setupOgre();
            else
                setupLegacy();
            userInput->init(adorn.get());
            AdjustThrottle(0.0);
            setupStatsGui();
            RBX::ControllerService* controller = RBX::ServiceProvider::create<RBX::ControllerService>(dataModel.get());
            controller->hardwareDevice = userInput.get();
            RBX::Stats::StatsService* statsService = RBX::ServiceProvider::create<RBX::Stats::StatsService>(dataModel.get());
            stats = createRenderStatsItem(view.get()->getRenderStats());
            stats->setName("Render");
            stats->setParent(statsService);
            RBX::Profiling::Profiler* p = profiler;
            stats->createBoundChildItem(p);
            runService->addRunView(this);
        }
    }
    if (m_hWnd)
        InvalidateRect(m_hWnd, 0, 1);
}
