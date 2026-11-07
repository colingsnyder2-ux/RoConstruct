// from server: 100% by Intel
// from server: 99% by EspClaude
// roc 2007-08 004211e0  unit: CSelectionTreeCtrl  size: 205 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004211e0
//
// 004211e0  83ec08               sub esp, 8
// 004211e3  53                   push ebx
// 004211e4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004211e8  55                   push ebp
// 004211e9  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004211ed  56                   push esi
// 004211ee  8bf1                 mov esi, ecx
// 004211f0  83beec00000000       cmp dword ptr [esi + 0xec], 0
// 004211f7  0f8498000000         je 0x421295
// 004211fd  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00421200  57                   push edi
// 00421201  8d442410             lea eax, [esp + 0x10]
// 00421205  50                   push eax
// 00421206  51                   push ecx
// 00421207  896c2418             mov dword ptr [esp + 0x18], ebp
// 0042120b  895c241c             mov dword ptr [esp + 0x1c], ebx
// 0042120f  ff15f0ed7700         call dword ptr [0x77edf0]
// 00421215  8b542414             mov edx, dword ptr [esp + 0x14]
// 00421219  8b442410             mov eax, dword ptr [esp + 0x10]
// 0042121d  52                   push edx
// 0042121e  50                   push eax
// 0042121f  e8deec2000           call 0x62ff02
// 00421224  8b8894000000         mov ecx, dword ptr [eax + 0x94]
// 0042122a  8b09                 mov ecx, dword ptr [ecx]
// 0042122c  e81fe2ffff           call 0x41f450
// 00421231  8d542420             lea edx, [esp + 0x20]
// 00421235  52                   push edx
// 00421236  53                   push ebx
// 00421237  55                   push ebp
// 00421238  8bce                 mov ecx, esi
// 0042123a  e875f22000           call 0x6304b4
// 0042123f  8bf8                 mov edi, eax
// 00421241  85ff                 test edi, edi
// 00421243  7415                 je 0x42125a
// 00421245  f644242046           test byte ptr [esp + 0x20], 0x46
// 0042124a  740c                 je 0x421258
// 0042124c  57                   push edi
// 0042124d  8bce                 mov ecx, esi
// 0042124f  e88cfeffff           call 0x4210e0
// 00421254  8bf8                 mov edi, eax
// 00421256  eb02                 jmp 0x42125a
// 00421258  33ff                 xor edi, edi
// 0042125a  6a00                 push 0
// 0042125c  e8a1ec2000           call 0x62ff02
// 00421261  8b8094000000         mov eax, dword ptr [eax + 0x94]
// 00421267  8b08                 mov ecx, dword ptr [eax]
// 00421269  e812e3ffff           call 0x41f580
// 0042126e  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00421271  57                   push edi
// 00421272  6a08                 push 8
// 00421274  680b110000           push 0x110b
// 00421279  51                   push ecx
// 0042127a  ff15d8ec7700         call dword ptr [0x77ecd8]
// 00421280  6a01                 push 1
// 00421282  e87bec2000           call 0x62ff02
// 00421287  8b9094000000         mov edx, dword ptr [eax + 0x94]
// 0042128d  8b0a                 mov ecx, dword ptr [edx]
// 0042128f  e8ece2ffff           call 0x41f580
// 00421294  5f                   pop edi
// 00421295  8b442418             mov eax, dword ptr [esp + 0x18]
// 00421299  53                   push ebx
// 0042129a  55                   push ebp
// 0042129b  50                   push eax
// 0042129c  8d4e54               lea ecx, [esi + 0x54]
// 0042129f  e82c572400           call 0x6669d0
// 004212a4  5e                   pop esi
// 004212a5  5d                   pop ebp
// 004212a6  5b                   pop ebx
// 004212a7  83c408               add esp, 8
// 004212aa  c20c00               ret 0xc

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
    char padding[0x98];
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
