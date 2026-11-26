// from server: 100% by Xemicl
// roc 2012-06 0046d720  unit: CRobloxApp  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046d720
//
// 0046d720  6aff                 push -1
// 0046d722  68d9aea900           push 0xa9aed9
// 0046d727  64a100000000         mov eax, dword ptr fs:[0]
// 0046d72d  50                   push eax
// 0046d72e  64892500000000       mov dword ptr fs:[0], esp
// 0046d735  51                   push ecx
// 0046d736  56                   push esi
// 0046d737  8d4c2404             lea ecx, [esp + 4]
// 0046d73b  ff158447b200         call dword ptr [0xb24784]
// 0046d741  68a49bb500           push 0xb59ba4
// 0046d746  8d442408             lea eax, [esp + 8]
// 0046d74a  68849bb500           push 0xb59b84
// 0046d74f  50                   push eax
// 0046d750  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0046d758  ff158847b200         call dword ptr [0xb24788]
// 0046d75e  83c40c               add esp, 0xc
// 0046d761  e82e515100           call 0x982894
// 0046d766  85c0                 test eax, eax
// 0046d768  740d                 je 0x46d777
// 0046d76a  8b10                 mov edx, dword ptr [eax]
// 0046d76c  8bc8                 mov ecx, eax
// 0046d76e  8b427c               mov eax, dword ptr [edx + 0x7c]
// 0046d771  ffd0                 call eax
// 0046d773  8bf0                 mov esi, eax
// 0046d775  eb02                 jmp 0x46d779
// 0046d777  33f6                 xor esi, esi
// 0046d779  6a0a                 push 0xa
// 0046d77b  6a00                 push 0
// 0046d77d  8d4c240c             lea ecx, [esp + 0xc]
// 0046d781  ff159847b200         call dword ptr [0xb24798]
// 0046d787  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0046d78a  50                   push eax
// 0046d78b  68749bb500           push 0xb59b74
// 0046d790  6848fcb400           push 0xb4fc48
// 0046d795  51                   push ecx
// 0046d796  ff151c3ab200         call dword ptr [0xb23a1c]
// 0046d79c  8d4c2404             lea ecx, [esp + 4]
// 0046d7a0  ff15d047b200         call dword ptr [0xb247d0]
// 0046d7a6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0046d7aa  5e                   pop esi
// 0046d7ab  64890d00000000       mov dword ptr fs:[0], ecx
// 0046d7b2  83c410               add esp, 0x10
// 0046d7b5  c3                   ret 
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