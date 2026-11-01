// from server: 100% by EspClaude
// from server: 70% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
#include <string>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    typedef T* shared_ptr::*unspecified_bool_type;
    T* px;
    shared_count pn;
    template<class Y> shared_ptr(shared_ptr<Y> const& r) : px(r.px), pn(r.pn) {}
    T* operator->() const { return px; }
    T* get() const { return px; }
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};

typedef std::string String;

namespace Ogre {
class __declspec(dllimport) Timer {
public:
    Timer();
    ~Timer();
    void reset();
    unsigned long getMilliseconds();
    char storage[0x30];
};
}

namespace G3D {
class Stopwatch {
public:
    char data[0x58];
    void tick();
    void tock();
};
}
class RenderStats {
public:
    G3D::Stopwatch render2D;
    G3D::Stopwatch swapBuffer;
    G3D::Stopwatch sort;
    G3D::Stopwatch cpuRenderTotal;
};
namespace RBX {
class StopwatchScope {
    G3D::Stopwatch* stopwatch;
public:
    StopwatchScope(G3D::Stopwatch& s) : stopwatch(&s) { s.tick(); }
    ~StopwatchScope() { stopwatch->tock(); }
};
}

class Renderer {
public:
    virtual void v0();
    virtual void v1();
    virtual void beginFrame();
    virtual void endFrame();
};

class HudTarget;
class View {
public:
    virtual void v0();
    virtual void render(HudTarget* hud);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual RenderStats& getRenderStats();
};

class TextLabel {
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
    virtual void setText(const String& text);
};

class FrameHistory {
public:
    unsigned int size() const;
    float& operator[](int i);
};

class HudTarget {
public:
    char pad[0xc];
    TextLabel* label;
    char pad2[0x18 - 0x10];
    FrameHistory history;
    FrameHistory& getHistory() { return history; }
};

class UserInputBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool keyDown(int key) const;
    bool ctrlKeyDown() const;
};
class ControllerService {
public:
    char pad[0x130];
    UserInputBase* hardwareDevice;
};
String getScreenshotFolder(int csidl = 0);
namespace RBX {
class Workspace {
public:
    void visitParts(void (*fn)(void*));
    static Workspace* findWorkspace(const void* context);
};
class DataModel;
template<class T> static T* findService(const DataModel* context);
class DataModel {
public:
    void render(Renderer* renderer, void* rect);
    void renderOverlay(Renderer* renderer);
    template<class T> T* find() const;
    class scoped_lock {
    public:
        scoped_lock(shared_ptr<const DataModel> dm);
        ~scoped_lock();
        int a, b, c;
    };
};
template<class T> static T* findService(const DataModel* context) { if (context) return context->find<T>(); return 0; }
class GameSettings {
public:
    char pad[0x13c];
    int graphicsMode;
    int frameRateMode;
    static GameSettings* singleton();
};
extern bool showBevels;
}

class IRunView;
class Notifier {
public:
    void notify(IRunView* view);
};

void configurePart(void* part);
extern bool g_showFrameRate;

class IRunView {
public:
    virtual void InvalidateRunView() = 0;
    virtual void AdjustThrottle(double) = 0;
};
struct CRobloxWndPad { virtual ~CRobloxWndPad(); char pad[0x50]; };
template<class T> class Ptr { public: T* p; T* get() const { return p; } T* operator->() const { return p; } };
class CRobloxWnd : public CRobloxWndPad, public IRunView {
public:
    void InvalidateRunView(); void AdjustThrottle(double);
    int rect[6];
    shared_ptr<RBX::DataModel> dataModel;
    Notifier* notifier;
    char pad2[0xb0 - 0x7c];
    View* view;
    Ptr<Renderer> renderer;
    HudTarget* hud;
    void doRender(int unused);
};

void CRobloxWnd::doRender(int unused)
{
    int mode = RBX::GameSettings::singleton()->graphicsMode;
    if (mode == 2)
        RBX::showBevels = false;
    Ogre::Timer timer;
    float ms;
    {
        RBX::StopwatchScope scope(view->getRenderStats().cpuRenderTotal);
        timer.reset();
        RBX::DataModel::scoped_lock dmLock(dataModel);
        RBX::Workspace* workspace = RBX::Workspace::findWorkspace(dataModel.get());
        if (!workspace)
            g_showFrameRate = false;
        else {
            g_showFrameRate = RBX::GameSettings::singleton()->frameRateMode != 2;
            workspace->visitParts(configurePart);
        }
        dataModel.get()->render(renderer.p, rect);
        dataModel.get()->renderOverlay(renderer.get());
        renderer->beginFrame();
        view->render(hud);
        renderer->endFrame();
        ms = (float)timer.getMilliseconds();
    }
    if (g_showFrameRate && hud->getHistory().size())
        hud->getHistory()[0] = ms;
    {
        RBX::StopwatchScope scope(view->getRenderStats().render2D);
        if (notifier)
            notifier->notify(this);
        ControllerService* controller = RBX::findService<ControllerService>(dataModel.get());
        if (controller) {
            UserInputBase* input = controller->hardwareDevice;
            if (input && input->keyDown(0x67) && input->ctrlKeyDown() && hud)
            {
                String path = getScreenshotFolder() + "\\Roblox.jpg";
                hud->label->setText(path);
            }
        }
    }
}
