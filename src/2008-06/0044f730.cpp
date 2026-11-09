// from server: 100% by colin
// from server: 98% by king_originala
// roc 2008-06 0044f730  unit: ExitCommand  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044f730
//
// 0044f730  51                   push ecx
// 0044f731  56                   push esi
// 0044f732  8bf1                 mov esi, ecx
// 0044f734  e8ed112500           call 0x6a0926
// 0044f739  8b4004               mov eax, dword ptr [eax + 4]
// 0044f73c  8b4020               mov eax, dword ptr [eax + 0x20]
// 0044f73f  80b80401000000       cmp byte ptr [eax + 0x104], 0
// 0044f746  7415                 je 0x44f75d
// 0044f748  8b4020               mov eax, dword ptr [eax + 0x20]
// 0044f74b  6a00                 push 0
// 0044f74d  6a00                 push 0
// 0044f74f  6a10                 push 0x10
// 0044f751  50                   push eax
// 0044f752  ff150c2e8000         call dword ptr [0x802e0c]
// 0044f758  5e                   pop esi
// 0044f759  59                   pop ecx
// 0044f75a  c20400               ret 4
// 0044f75d  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0044f760  8b11                 mov edx, dword ptr [ecx]
// 0044f762  8b4268               mov eax, dword ptr [edx + 0x68]
// 0044f765  ffd0                 call eax
// 0044f767  89442404             mov dword ptr [esp + 4], eax
// 0044f76b  85c0                 test eax, eax
// 0044f76d  7425                 je 0x44f794
// 0044f76f  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0044f772  8b11                 mov edx, dword ptr [ecx]
// 0044f774  8b526c               mov edx, dword ptr [edx + 0x6c]
// 0044f777  8d442404             lea eax, [esp + 4]
// 0044f77b  50                   push eax
// 0044f77c  ffd2                 call edx
// 0044f77e  8b4020               mov eax, dword ptr [eax + 0x20]
// 0044f781  6a00                 push 0
// 0044f783  6802e10000           push 0xe102
// 0044f788  6811010000           push 0x111
// 0044f78d  50                   push eax
// 0044f78e  ff150c2e8000         call dword ptr [0x802e0c]
// 0044f794  5e                   pop esi
// 0044f795  59                   pop ecx
// 0044f796  c20400               ret 4

struct Window {
    char padding0[0x20];
    void* handle;
    char padding1[0xE0];
    unsigned char closing;
};

struct Context {
    char padding[0x20];
    Window* window;
};

struct Root {
    char padding[4];
    Context* context;
};

struct Receiver;

struct ReceiverTable {
    void* padding[26];
    int (__thiscall* current)(Receiver*);
    Window* (__thiscall* resolve)(Receiver*, int*);
};

struct Receiver {
    ReceiverTable* table;
};

extern "C" __declspec(dllimport) int __stdcall PostMessageA(void*, unsigned int, unsigned int, long);

struct ExitCommand {
    char padding[0x0C];
    Receiver* receiver;

    Root* acquire();
    void execute(void*);
};

void ExitCommand::execute(void*)
{
    Context* context = acquire()->context;
    Window* window = context->window;
    if (window->closing) {
        PostMessageA(window->handle, 0x10, 0, 0);
        return;
    }

    int current = receiver->table->current(receiver);
    if (current) {
        window = receiver->table->resolve(receiver, &current);
        PostMessageA(window->handle, 0x111, 0xE102, 0);
    }
}