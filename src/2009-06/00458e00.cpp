// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" void *(__stdcall *LoadMenuA)(void *, const char *);
extern "C" void *__stdcall resourceModule(unsigned int, const char *);

struct ViewBase {
    virtual ~ViewBase();
    char storage[0x74];
    ViewBase();
};

struct Command {
    virtual ~Command();
    virtual void method1();
    char storage[0x24];
    Command(int);
};

struct Pane {
    char storage[0x104];
    Pane(int);
    ~Pane();
};

struct PointerPair {
    void *pointer;
    void *control;
    PointerPair();
    ~PointerPair();
};

inline PointerPair::PointerPair() : pointer(0), control(0)
{
}

struct Menu {
    virtual ~Menu();
    void *handle;
    Menu();
    int attach(void *);
};

inline Menu::Menu() : handle(0)
{
}

struct Reflector {
    char storage[0x58];
    Reflector();
    ~Reflector();
};

struct Pointer {
    void *value;
    Pointer();
    ~Pointer();
};

inline Pointer::Pointer() : value(0)
{
}

namespace RBX {
template<class T> class Countable {
    static long count;
public:
    Countable() { InterlockedIncrement(&count); }
    ~Countable() { InterlockedDecrement(&count); }
};
}
namespace rbx { namespace signals {
class connection : RBX::Countable<connection> {
public:
    void* px;
    void* pn;
    connection() : px(0), pn(0) {}
    ~connection();
};
} }

struct CRobloxView : ViewBase, Command {
    Pane pane;
    PointerPair owner;
    Menu menu;
    Reflector reflector;
    Pointer p0;
    Pointer p1;
    Pointer p2;
    Pointer p3;
    PointerPair p4;
    rbx::signals::connection c0;
    rbx::signals::connection c1;
    rbx::signals::connection c2;

    CRobloxView();
    virtual ~CRobloxView();
    virtual void method1();
};

CRobloxView::CRobloxView()
    : ViewBase(),
      Command(0),
      pane(0)
{
    menu.attach(LoadMenuA(
        resourceModule(0x67, reinterpret_cast<const char *>(4)),
        reinterpret_cast<const char *>(0x67)));
}
