// from server: 70% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 00459eb0  unit: CRobloxView  size: 242 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00459eb0
//
// 00459eb0  6aff                 push -1
// 00459eb2  6871297c00           push 0x7c2971
// 00459eb7  64a100000000         mov eax, dword ptr fs:[0]
// 00459ebd  50                   push eax
// 00459ebe  64892500000000       mov dword ptr fs:[0], esp
// 00459ec5  51                   push ecx
// 00459ec6  53                   push ebx
// 00459ec7  56                   push esi
// 00459ec8  8bf1                 mov esi, ecx
// 00459eca  57                   push edi
// 00459ecb  8974240c             mov dword ptr [esp + 0xc], esi
// 00459ecf  e8bcf9ffff           call 0x459890
// 00459ed4  33ff                 xor edi, edi
// 00459ed6  8d5e78               lea ebx, [esi + 0x78]
// 00459ed9  57                   push edi
// 00459eda  8bcb                 mov ecx, ebx
// 00459edc  897c241c             mov dword ptr [esp + 0x1c], edi
// 00459ee0  e87b951200           call 0x583460
// 00459ee5  57                   push edi
// 00459ee6  8d8eb0000000         lea ecx, [esi + 0xb0]
// 00459eec  c644241c01           mov byte ptr [esp + 0x1c], 1
// 00459ef1  c7063c938100         mov dword ptr [esi], 0x81933c
// 00459ef7  c70330938100         mov dword ptr [ebx], 0x819330
// 00459efd  c786a000000024938100 mov dword ptr [esi + 0xa0], 0x819324
// 00459f07  c786a400000018938100 mov dword ptr [esi + 0xa4], 0x819318
// 00459f11  c786a80000000c938100 mov dword ptr [esi + 0xa8], 0x81930c
// 00459f1b  e810280000           call 0x45c730
// 00459f20  89be70010000         mov dword ptr [esi + 0x170], edi
// 00459f26  89be74010000         mov dword ptr [esi + 0x174], edi
// 00459f2c  8d9e78010000         lea ebx, [esi + 0x178]
// 00459f32  c703dcfb8000         mov dword ptr [ebx], 0x80fbdc
// 00459f38  897b04               mov dword ptr [ebx + 4], edi
// 00459f3b  8d8e80010000         lea ecx, [esi + 0x180]
// 00459f41  c644241804           mov byte ptr [esp + 0x18], 4
// 00459f46  e8e58efdff           call 0x432e30
// 00459f4b  89bed8010000         mov dword ptr [esi + 0x1d8], edi
// 00459f51  89bedc010000         mov dword ptr [esi + 0x1dc], edi
// 00459f57  89bee0010000         mov dword ptr [esi + 0x1e0], edi
// 00459f5d  89bee4010000         mov dword ptr [esi + 0x1e4], edi
// 00459f63  89bee8010000         mov dword ptr [esi + 0x1e8], edi
// 00459f69  89beec010000         mov dword ptr [esi + 0x1ec], edi
// 00459f6f  6a67                 push 0x67
// 00459f71  6a04                 push 4
// 00459f73  6a67                 push 0x67
// 00459f75  c64424240a           mov byte ptr [esp + 0x24], 0xa
// 00459f7a  e8ad6f2400           call 0x6a0f2c
// 00459f7f  50                   push eax
// 00459f80  ff15882d8000         call dword ptr [0x802d88]
// 00459f86  50                   push eax
// 00459f87  8bcb                 mov ecx, ebx
// 00459f89  e8986f2400           call 0x6a0f26
// 00459f8e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00459f92  5f                   pop edi
// 00459f93  8bc6                 mov eax, esi
// 00459f95  5e                   pop esi
// 00459f96  5b                   pop ebx
// 00459f97  64890d00000000       mov dword ptr fs:[0], ecx
// 00459f9e  83c410               add esp, 0x10
// 00459fa1  c3                   ret 

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
