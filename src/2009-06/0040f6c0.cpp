// from server: 100% by EspClaude
// roc 2009-06 0040f6c0  unit: CChatPrompt  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040f6c0
//
// 0040f6c0  56                   push esi
// 0040f6c1  6840404000           push 0x404040
// 0040f6c6  8bf1                 mov esi, ecx
// 0040f6c8  ff1568e18900         call dword ptr [0x89e168]
// 0040f6ce  50                   push eax
// 0040f6cf  8d8e94000000         lea ecx, [esi + 0x94]
// 0040f6d5  e828993000           call 0x719002
// 0040f6da  8b442408             mov eax, dword ptr [esp + 8]
// 0040f6de  50                   push eax
// 0040f6df  8bce                 mov ecx, esi
// 0040f6e1  e834993000           call 0x71901a
// 0040f6e6  83f8ff               cmp eax, -1
// 0040f6e9  7506                 jne 0x40f6f1
// 0040f6eb  0bc0                 or eax, eax
// 0040f6ed  5e                   pop esi
// 0040f6ee  c20400               ret 4
// 0040f6f1  833d4419a50000       cmp dword ptr [0xa51944], 0
// 0040f6f8  750a                 jne 0x40f704
// 0040f6fa  6a00                 push 0
// 0040f6fc  e8bf403100           call 0x7237c0
// 0040f701  83c404               add esp, 4
// 0040f704  a14419a500           mov eax, dword ptr [0xa51944]
// 0040f709  05f8000000           add eax, 0xf8
// 0040f70e  7403                 je 0x40f713
// 0040f710  8b4004               mov eax, dword ptr [eax + 4]
// 0040f713  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0040f716  6a01                 push 1
// 0040f718  50                   push eax
// 0040f719  6a30                 push 0x30
// 0040f71b  51                   push ecx
// 0040f71c  ff1590ee8900         call dword ptr [0x89ee90]
// 0040f722  8b156ce69d00         mov edx, dword ptr [0x9de66c]
// 0040f728  52                   push edx
// 0040f729  8bce                 mov ecx, esi
// 0040f72b  e8bc963000           call 0x718dec
// 0040f730  33c0                 xor eax, eax
// 0040f732  5e                   pop esi
// 0040f733  c20400               ret 4
// copied from an identical function in another client (function ?Initialize@CBrush@ns_ROCX000018@@QAEHPAX@Z)

namespace ns_ROCX000018 {
extern "C" {
    extern void* (__stdcall *CreateSolidBrush)(unsigned long color);
    extern long (__stdcall *SendMessageA)(void* window, unsigned int message,
                                         unsigned int wparam, long lparam);
}

struct Handle {
    void* reserved;
    void* handle;
    void Attach(void* value);
};

struct PaintManager {
    char padding[0xf8];
    Handle font;
};

extern PaintManager* paintManager;
extern void* resource;
void __cdecl InitializePaintManager(int);

struct CBrush {
    char padding0[0x20];
    void* window;
    char padding1[0x70];
    Handle brush;

    int BaseInitialize(void* argument);
    void SetResource(void* value);
    int Initialize(void* argument);
};

int CBrush::Initialize(void* argument)
{
    brush.Attach(CreateSolidBrush(0x404040));

    int result = BaseInitialize(argument);
    if (result == -1)
        return result;

    if (!paintManager)
        InitializePaintManager(0);

    Handle* font = &paintManager->font;
    void* fontHandle = font;
    if (font)
        fontHandle = font->handle;

    SendMessageA(window, 0x30, (unsigned int)fontHandle, 1);
    SetResource(resource);
    return 0;
}
}
