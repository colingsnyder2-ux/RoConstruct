// from server: 100% by king_originala
typedef unsigned long DWORD;
typedef long (__stdcall *WindowProc)(void*, unsigned int, unsigned int, long);

struct WindowClass {
    unsigned int style;
    WindowProc procedure;
    int classExtra;
    int windowExtra;
    void* instance;
    void* icon;
    void* cursor;
    void* background;
    const char* menuName;
    const char* className;
};

extern WindowProc DefWindowProcA;
extern void* (__stdcall *LoadIconA)(void*, const char*);
extern void* (__stdcall *LoadCursorA)(void*, const char*);
extern unsigned short (__stdcall *RegisterClassA)(const WindowClass*);

struct Context {
    char reserved[8];
    void* instance;
};

struct Window;
struct WindowTable {
    void* reserved[81];
    void (__thiscall *create)(Window*, const char*, const char*, DWORD,
                             void*, int, int, int, int);
};

struct Window {
    WindowTable* table;
};

struct Manager {
    Window* getWindow();
};

extern Context* __cdecl getContext();
extern Manager* __cdecl getManager();
extern void* creationParameter;

void initializeWindow()
{
    WindowClass wc;
    wc.style = 3;
    wc.procedure = DefWindowProcA;
    wc.classExtra = 0;
    wc.windowExtra = 0;
    wc.instance = getContext()->instance;
    wc.icon = LoadIconA(0, reinterpret_cast<const char*>(0x7f00));
    wc.cursor = LoadCursorA(0, reinterpret_cast<const char*>(0x7f00));
    wc.background = 0;
    wc.menuName = "Menu";
    wc.className = "ROBLOX-ATOM";
    RegisterClassA(&wc);

    Window* window = getManager()->getWindow();
    window->table->create(window, wc.className, "ROBLOX", 0xcf0000,
                          creationParameter, 0, 0, 0, 0);
}
