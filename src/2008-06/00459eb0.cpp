// from server: 100% by king_originala
extern "C" void *(__stdcall *LoadMenuA)(void *, const char *);
extern "C" void *__stdcall resourceModule(unsigned int, const char *);

struct ViewBase {
    virtual ~ViewBase();
    char storage[0x74];
    ViewBase();
};

struct Interface1 {
    virtual void method1();
};

struct Interface2 {
    virtual void method2();
};

struct Interface3 {
    virtual void method3();
};

struct CommandBase {
    virtual ~CommandBase();
    char storage[0x24];
};

struct Command : CommandBase, Interface1, Interface2, Interface3 {
    unsigned int reserved;
    Command(int);
    ~Command();
};

struct Pane {
    char storage[0xC0];
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

    CRobloxView();
    virtual ~CRobloxView();
    virtual void method1();
    virtual void method2();
    virtual void method3();
};

CRobloxView::CRobloxView()
    : ViewBase(),
      Command(0),
      pane(0),
      owner(),
      menu(),
      reflector(),
      p0(),
      p1(),
      p2(),
      p3(),
      p4()
{
    menu.attach(LoadMenuA(
        resourceModule(0x67, reinterpret_cast<const char *>(4)),
        reinterpret_cast<const char *>(0x67)));
}
