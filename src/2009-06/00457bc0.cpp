// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00459170  unit: HelpCommand  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00459170
//
// 00459170  8b442404             mov eax, dword ptr [esp + 4]
// 00459174  83ec10               sub esp, 0x10
// 00459177  56                   push esi
// 00459178  50                   push eax
// 00459179  8bf1                 mov esi, ecx
// 0045917b  e8627f2400           call 0x6a10e2
// 00459180  83f8ff               cmp eax, -1
// 00459183  7509                 jne 0x45918e
// 00459185  0bc0                 or eax, eax
// 00459187  5e                   pop esi
// 00459188  83c410               add esp, 0x10
// 0045918b  c20400               ret 4
// 0045918e  8b5620               mov edx, dword ptr [esi + 0x20]
// 00459191  8d4c2404             lea ecx, [esp + 4]
// 00459195  51                   push ecx
// 00459196  52                   push edx
// 00459197  ff15842d8000         call dword ptr [0x802d84]
// 0045919d  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 004591a3  8b405c               mov eax, dword ptr [eax + 0x5c]
// 004591a6  6a00                 push 0
// 004591a8  6a01                 push 1
// 004591aa  56                   push esi
// 004591ab  8d542410             lea edx, [esp + 0x10]
// 004591af  52                   push edx
// 004591b0  6800000050           push 0x50000000
// 004591b5  8d8eb0000000         lea ecx, [esi + 0xb0]
// 004591bb  6820e98000           push 0x80e920
// 004591c0  6a00                 push 0
// 004591c2  ffd0                 call eax
// 004591c4  f7d8                 neg eax
// 004591c6  1bc0                 sbb eax, eax
// 004591c8  f7d8                 neg eax
// 004591ca  48                   dec eax
// 004591cb  5e                   pop esi
// 004591cc  83c410               add esp, 0x10
// 004591cf  c20400               ret 4

struct Rect {
    int left, top, right, bottom;
};

extern "C" int (__stdcall *GetClientRect)(void*, Rect*);

struct Window;

struct WindowTable {
    void* unused[23];
    int (__thiscall *create)(Window*, void*, const char*, unsigned int,
                            Rect*, void*, int, int);
};

struct Window {
    WindowTable* table;
};

struct HelpCommand {
    char padding0[0x20];
    void* window;
    char padding1[0x7c];
    Window child;

    int initialize(int arg);
    int method(int arg);
};

int HelpCommand::method(int arg) {
    Rect rect;
    if (initialize(arg) == -1)
        return -1;

    GetClientRect(window, &rect);
    return (child.table->create(&child, 0, "Roblox", 0x50000000,
                                &rect, this, 1, 0) != 0) - 1;
}
