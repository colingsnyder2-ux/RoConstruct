// from server: 100% by EspClaude
// roc 2009-06 00445770  unit: CRobloxApp  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00445770
//
// 00445770  6aff                 push -1
// 00445772  6839068500           push 0x850639
// 00445777  64a100000000         mov eax, dword ptr fs:[0]
// 0044577d  50                   push eax
// 0044577e  64892500000000       mov dword ptr fs:[0], esp
// 00445785  51                   push ecx
// 00445786  56                   push esi
// 00445787  8d4c2404             lea ecx, [esp + 4]
// 0044578b  ff15bcfc8900         call dword ptr [0x89fcbc]
// 00445791  68c46d8b00           push 0x8b6dc4
// 00445796  8d442408             lea eax, [esp + 8]
// 0044579a  68a46d8b00           push 0x8b6da4
// 0044579f  50                   push eax
// 004457a0  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004457a8  ff15c4fc8900         call dword ptr [0x89fcc4]
// 004457ae  83c40c               add esp, 0xc
// 004457b1  e8383a2d00           call 0x7191ee
// 004457b6  85c0                 test eax, eax
// 004457b8  740d                 je 0x4457c7
// 004457ba  8b10                 mov edx, dword ptr [eax]
// 004457bc  8bc8                 mov ecx, eax
// 004457be  8b427c               mov eax, dword ptr [edx + 0x7c]
// 004457c1  ffd0                 call eax
// 004457c3  8bf0                 mov esi, eax
// 004457c5  eb02                 jmp 0x4457c9
// 004457c7  33f6                 xor esi, esi
// 004457c9  6a0a                 push 0xa
// 004457cb  6a00                 push 0
// 004457cd  8d4c240c             lea ecx, [esp + 0xc]
// 004457d1  ff15d0fc8900         call dword ptr [0x89fcd0]
// 004457d7  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 004457da  50                   push eax
// 004457db  68946d8b00           push 0x8b6d94
// 004457e0  688c6d8b00           push 0x8b6d8c
// 004457e5  51                   push ecx
// 004457e6  ff1508ec8900         call dword ptr [0x89ec08]
// 004457ec  8d4c2404             lea ecx, [esp + 4]
// 004457f0  ff1510fd8900         call dword ptr [0x89fd10]
// 004457f6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004457fa  5e                   pop esi
// 004457fb  64890d00000000       mov dword ptr fs:[0], ecx
// 00445802  83c410               add esp, 0x10
// 00445805  c3                   ret 
// copied from an identical function in another client (function ?OpenWiki@ns_ROCX000000@@YAXXZ)

namespace ns_ROCX000000 {
struct Text;

extern void (__cdecl *TextFormat)(Text *, const char *, ...);
extern const char *(__thiscall *TextData)(const Text *);

struct Text {
    char *data;
    __declspec(dllimport) Text();
    __declspec(dllimport) ~Text() throw();
};





struct Window {
    char padding[32];
    void *handle;
};

struct Application {
    struct Table {
        void *unused[31];
        Window *(__thiscall *getWindow)(Application *);
    };
    Table *table;
};

extern Application *__cdecl GetApplication();

extern void *(__stdcall *ShellExecuteA)(
    void *, const char *, const char *, const char *, const char *, int);

void OpenWiki()
{
    Text command;
    TextFormat(&command, "url.dll,FileProtocolHandler %s",
               "http://wiki.roblox.com");

    Application *application = GetApplication();
    Window *window;
    if (application)
        window = application->table->getWindow(application);
    else
        window = 0;

    ShellExecuteA(window->handle, "open", "rundll32.exe",
                  TextData(&command), 0, 10);
}
}
