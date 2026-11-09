// from server: 95% by Intel
﻿// from server: 93% by EspClaude
// roc-cl: 50727
// 2007-08 hand variant: PaintManager::font offset is 0xe0 here (0xf8 in the 2008-06 original)
// from server: 100% by king_originala
// roc 2008-06 00411640  unit: CBrush  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00411640
//
// 00411640  56                   push esi
// 00411641  6840404000           push 0x404040
// 00411646  8bf1                 mov esi, ecx
// 00411648  ff1558218000         call dword ptr [0x802158]
// 0041164e  50                   push eax
// 0041164f  8d8e94000000         lea ecx, [esi + 0x94]
// 00411655  e808f62800           call 0x6a0c62
// 0041165a  8b442408             mov eax, dword ptr [esp + 8]
// 0041165e  50                   push eax
// 0041165f  8bce                 mov ecx, esi
// 00411661  e81af62800           call 0x6a0c80
// 00411666  83f8ff               cmp eax, -1
// 00411669  7506                 jne 0x411671
// 0041166b  0bc0                 or eax, eax
// 0041166d  5e                   pop esi
// 0041166e  c20400               ret 4
// 00411671  833d60e0970000       cmp dword ptr [0x97e060], 0
// 00411678  750a                 jne 0x411684
// 0041167a  6a00                 push 0
// 0041167c  e81fda2900           call 0x6af0a0
// 00411681  83c404               add esp, 4
// 00411684  a160e09700           mov eax, dword ptr [0x97e060]
// 00411689  05f8000000           add eax, 0xf8
// 0041168e  7403                 je 0x411693
// 00411690  8b4004               mov eax, dword ptr [eax + 4]
// 00411693  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00411696  6a01                 push 1
// 00411698  50                   push eax
// 00411699  6a30                 push 0x30
// 0041169b  51                   push ecx
// 0041169c  ff15142e8000         call dword ptr [0x802e14]
// 004116a2  8b1580b79200         mov edx, dword ptr [0x92b780]
// 004116a8  52                   push edx
// 004116a9  8bce                 mov ecx, esi
// 004116ab  e86af52800           call 0x6a0c1a
// 004116b0  33c0                 xor eax, eax
// 004116b2  5e                   pop esi
// 004116b3  c20400               ret 4

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
    char padding[0xe0];
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
    void* fontHandle;
    if (font)
        fontHandle = font->handle;
    else
        fontHandle = 0;

    SendMessageA(window, 0x30, (unsigned int)fontHandle, 1);
    SetResource(resource);
    return 0;
}
