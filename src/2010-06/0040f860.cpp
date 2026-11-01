// from server: 100% by Yeetserama
// roc 2010-06 0040f860  unit: CChatPrompt  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040f860
//
// 0040f860  56                   push esi
// 0040f861  6840404000           push 0x404040
// 0040f866  8bf1                 mov esi, ecx
// 0040f868  ff15a8a09e00         call dword ptr [0x9ea0a8]
// 0040f86e  50                   push eax
// 0040f86f  8d8e94000000         lea ecx, [esi + 0x94]
// 0040f875  e8f0863900           call 0x7a7f6a
// 0040f87a  8b442408             mov eax, dword ptr [esp + 8]
// 0040f87e  50                   push eax
// 0040f87f  8bce                 mov ecx, esi
// 0040f881  e8fc863900           call 0x7a7f82
// 0040f886  83f8ff               cmp eax, -1
// 0040f889  7506                 jne 0x40f891
// 0040f88b  0bc0                 or eax, eax
// 0040f88d  5e                   pop esi
// 0040f88e  c20400               ret 4
// 0040f891  833db054c20000       cmp dword ptr [0xc254b0], 0
// 0040f898  750a                 jne 0x40f8a4
// 0040f89a  6a00                 push 0
// 0040f89c  e8cfe83900           call 0x7ae170
// 0040f8a1  83c404               add esp, 4
// 0040f8a4  a1b054c200           mov eax, dword ptr [0xc254b0]
// 0040f8a9  05f8000000           add eax, 0xf8
// 0040f8ae  7403                 je 0x40f8b3
// 0040f8b0  8b4004               mov eax, dword ptr [eax + 4]
// 0040f8b3  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0040f8b6  6a01                 push 1
// 0040f8b8  50                   push eax
// 0040f8b9  6a30                 push 0x30
// 0040f8bb  51                   push ecx
// 0040f8bc  ff1554ba9e00         call dword ptr [0x9eba54]
// 0040f8c2  8b1554b7b700         mov edx, dword ptr [0xb7b754]
// 0040f8c8  52                   push edx
// 0040f8c9  8bce                 mov ecx, esi
// 0040f8cb  e884843900           call 0x7a7d54
// 0040f8d0  33c0                 xor eax, eax
// 0040f8d2  5e                   pop esi
// 0040f8d3  c20400               ret 4
// copied from an identical function in another client (function ?Initialize@CBrush@ns_ROCX000016@@QAEHPAX@Z)

namespace ns_ROCX000016 {
// from server: 100% by king_originala
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
