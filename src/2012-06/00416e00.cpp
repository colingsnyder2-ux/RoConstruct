// from server: 100% by Xemicl
// roc 2012-06 00416e00  unit: CChatPrompt  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00416e00
//
// 00416e00  56                   push esi
// 00416e01  6840404000           push 0x404040
// 00416e06  8bf1                 mov esi, ecx
// 00416e08  ff155421b200         call dword ptr [0xb22154]
// 00416e0e  50                   push eax
// 00416e0f  8d8e94000000         lea ecx, [esi + 0x94]
// 00416e15  e8beb85600           call 0x9826d8
// 00416e1a  8b442408             mov eax, dword ptr [esp + 8]
// 00416e1e  50                   push eax
// 00416e1f  8bce                 mov ecx, esi
// 00416e21  e8cab85600           call 0x9826f0
// 00416e26  83f8ff               cmp eax, -1
// 00416e29  7506                 jne 0x416e31
// 00416e2b  0bc0                 or eax, eax
// 00416e2d  5e                   pop esi
// 00416e2e  c20400               ret 4
// 00416e31  833d0893e50000       cmp dword ptr [0xe59308], 0
// 00416e38  750a                 jne 0x416e44
// 00416e3a  6a00                 push 0
// 00416e3c  e82f1a5700           call 0x988870
// 00416e41  83c404               add esp, 4
// 00416e44  a10893e500           mov eax, dword ptr [0xe59308]
// 00416e49  05f8000000           add eax, 0xf8
// 00416e4e  7403                 je 0x416e53
// 00416e50  8b4004               mov eax, dword ptr [eax + 4]
// 00416e53  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00416e56  6a01                 push 1
// 00416e58  50                   push eax
// 00416e59  6a30                 push 0x30
// 00416e5b  51                   push ecx
// 00416e5c  ff15043cb200         call dword ptr [0xb23c04]
// 00416e62  8b15b034d600         mov edx, dword ptr [0xd634b0]
// 00416e68  52                   push edx
// 00416e69  8bce                 mov ecx, esi
// 00416e6b  e84cb65600           call 0x9824bc
// 00416e70  33c0                 xor eax, eax
// 00416e72  5e                   pop esi
// 00416e73  c20400               ret 4
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