// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004495a0  unit: RBX::Reflection::Metadata::VItem::?$BoundPropGetSet  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004495a0
//
// 004495a0  83ec28               sub esp, 0x28
// 004495a3  a1c42d8000           mov eax, dword ptr [0x802dc4]
// 004495a8  c7042403000000       mov dword ptr [esp], 3
// 004495af  89442404             mov dword ptr [esp + 4], eax
// 004495b3  c744240800000000     mov dword ptr [esp + 8], 0
// 004495bb  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004495c3  e85e732500           call 0x6a0926
// 004495c8  8b4808               mov ecx, dword ptr [eax + 8]
// 004495cb  68007f0000           push 0x7f00
// 004495d0  6a00                 push 0
// 004495d2  894c2418             mov dword ptr [esp + 0x18], ecx
// 004495d6  ff15642d8000         call dword ptr [0x802d64]
// 004495dc  68007f0000           push 0x7f00
// 004495e1  6a00                 push 0
// 004495e3  8944241c             mov dword ptr [esp + 0x1c], eax
// 004495e7  ff15d02d8000         call dword ptr [0x802dd0]
// 004495ed  8d1424               lea edx, [esp]
// 004495f0  52                   push edx
// 004495f1  8944241c             mov dword ptr [esp + 0x1c], eax
// 004495f5  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004495fd  c74424242c668100     mov dword ptr [esp + 0x24], 0x81662c
// 00449605  c744242820668100     mov dword ptr [esp + 0x28], 0x816620
// 0044960d  ff15342d8000         call dword ptr [0x802d34]
// 00449613  e84e7b2500           call 0x6a1166
// 00449618  8bc8                 mov ecx, eax
// 0044961a  e8a3792500           call 0x6a0fc2
// 0044961f  8b0df4348000         mov ecx, dword ptr [0x8034f4]
// 00449625  8b10                 mov edx, dword ptr [eax]
// 00449627  8b9244010000         mov edx, dword ptr [edx + 0x144]
// 0044962d  6a00                 push 0
// 0044962f  6a00                 push 0
// 00449631  6a00                 push 0
// 00449633  6a00                 push 0
// 00449635  51                   push ecx
// 00449636  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0044963a  680000cf00           push 0xcf0000
// 0044963f  6818668100           push 0x816618
// 00449644  51                   push ecx
// 00449645  8bc8                 mov ecx, eax
// 00449647  ffd2                 call edx
// 00449649  83c428               add esp, 0x28
// 0044964c  c3                   ret 

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
