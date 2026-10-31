// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00423d50  unit: CSelectionTreeCtrl  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00423d50
//
// 00423d50  83ec0c               sub esp, 0xc
// 00423d53  57                   push edi
// 00423d54  8bf9                 mov edi, ecx
// 00423d56  83bf2c01000000       cmp dword ptr [edi + 0x12c], 0
// 00423d5d  0f84a8000000         je 0x423e0b
// 00423d63  8b442418             mov eax, dword ptr [esp + 0x18]
// 00423d67  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00423d6b  56                   push esi
// 00423d6c  8d54240c             lea edx, [esp + 0xc]
// 00423d70  8944240c             mov dword ptr [esp + 0xc], eax
// 00423d74  8b4720               mov eax, dword ptr [edi + 0x20]
// 00423d77  52                   push edx
// 00423d78  50                   push eax
// 00423d79  894c2418             mov dword ptr [esp + 0x18], ecx
// 00423d7d  ff15802d8000         call dword ptr [0x802d80]
// 00423d83  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00423d87  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00423d8b  51                   push ecx
// 00423d8c  52                   push edx
// 00423d8d  e894cb2700           call 0x6a0926
// 00423d92  8b8094000000         mov eax, dword ptr [eax + 0x94]
// 00423d98  8b08                 mov ecx, dword ptr [eax]
// 00423d9a  e8a1e5ffff           call 0x422340
// 00423d9f  8b542420             mov edx, dword ptr [esp + 0x20]
// 00423da3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00423da7  8d4c2408             lea ecx, [esp + 8]
// 00423dab  51                   push ecx
// 00423dac  52                   push edx
// 00423dad  50                   push eax
// 00423dae  8bcf                 mov ecx, edi
// 00423db0  e8a7d12700           call 0x6a0f5c
// 00423db5  8bf0                 mov esi, eax
// 00423db7  85f6                 test esi, esi
// 00423db9  7415                 je 0x423dd0
// 00423dbb  f644240846           test byte ptr [esp + 8], 0x46
// 00423dc0  740c                 je 0x423dce
// 00423dc2  56                   push esi
// 00423dc3  8bcf                 mov ecx, edi
// 00423dc5  e876feffff           call 0x423c40
// 00423dca  8bf0                 mov esi, eax
// 00423dcc  eb02                 jmp 0x423dd0
// 00423dce  33f6                 xor esi, esi
// 00423dd0  6a00                 push 0
// 00423dd2  e84fcb2700           call 0x6a0926
// 00423dd7  8b8894000000         mov ecx, dword ptr [eax + 0x94]
// 00423ddd  8b09                 mov ecx, dword ptr [ecx]
// 00423ddf  e87ce6ffff           call 0x422460
// 00423de4  8b5720               mov edx, dword ptr [edi + 0x20]
// 00423de7  56                   push esi
// 00423de8  6a08                 push 8
// 00423dea  680b110000           push 0x110b
// 00423def  52                   push edx
// 00423df0  ff15142e8000         call dword ptr [0x802e14]
// 00423df6  6a01                 push 1
// 00423df8  e829cb2700           call 0x6a0926
// 00423dfd  8b8094000000         mov eax, dword ptr [eax + 0x94]
// 00423e03  8b08                 mov ecx, dword ptr [eax]
// 00423e05  e856e6ffff           call 0x422460
// 00423e0a  5e                   pop esi
// 00423e0b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00423e0f  8b542418             mov edx, dword ptr [esp + 0x18]
// 00423e13  8b442414             mov eax, dword ptr [esp + 0x14]
// 00423e17  51                   push ecx
// 00423e18  52                   push edx
// 00423e19  50                   push eax
// 00423e1a  8d4f54               lea ecx, [edi + 0x54]
// 00423e1d  e84e992b00           call 0x6dd770
// 00423e22  5f                   pop edi
// 00423e23  83c40c               add esp, 0xc
// 00423e26  c20c00               ret 0xc

struct Point
{
    int x;
    int y;
};

extern "C" {
    extern int (__stdcall *ClientToScreen)(void*, Point*);
    extern long (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, long);
}

struct Context
{
    void setPoint(Point);
    void setEnabled(int);
};

struct ThreadState
{
    char padding[0x94];
    Context** context;
};

extern ThreadState* __cdecl getThreadState();

struct BaseControl
{
    char padding[0xD8];
    void onMouse(unsigned int, Point);
};

struct SelectionTree
{
    char padding0[0x20];
    void* window;
    char padding1[0x30];
    BaseControl base;
    int active;

    void* hitTest(Point, unsigned int*);
    void* adjustSelection(void*);
    void onMouse(unsigned int, Point);
};

void SelectionTree::onMouse(unsigned int flags, Point point)
{
    if (active)
    {
        Point screenPoint = point;
        unsigned int hitFlags;

        ClientToScreen(window, &screenPoint);
        (*getThreadState()->context)->setPoint(screenPoint);

        void* item = hitTest(point, &hitFlags);
        if (item)
        {
            if (hitFlags & 0x46)
                item = adjustSelection(item);
            else
                item = 0;
        }

        (*getThreadState()->context)->setEnabled(0);
        SendMessageA(window, 0x110B, 8, (long)item);
        (*getThreadState()->context)->setEnabled(1);
    }

    base.onMouse(flags, point);
}
