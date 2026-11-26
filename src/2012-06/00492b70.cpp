// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 004926c0  unit: InsertModelFromRobloxVerb  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004926c0
//
// 004926c0  a0a11ae300           mov al, byte ptr [0xe31aa1]
// 004926c5  56                   push esi
// 004926c6  8bf1                 mov esi, ecx
// 004926c8  84c0                 test al, al
// 004926ca  7413                 je 0x4926df
// 004926cc  6a00                 push 0
// 004926ce  0fb6c0               movzx eax, al
// 004926d1  6840e3b500           push 0xb5e340
// 004926d6  50                   push eax
// 004926d7  e80c791300           call 0x5c9fe8
// 004926dc  83c40c               add esp, 0xc
// 004926df  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004926e2  8b5120               mov edx, dword ptr [ecx + 0x20]
// 004926e5  6a00                 push 0
// 004926e7  68fe800000           push 0x80fe
// 004926ec  6811010000           push 0x111
// 004926f1  52                   push edx
// 004926f2  ff15243cb200         call dword ptr [0xb23c24]
// 004926f8  5e                   pop esi
// 004926f9  c20400               ret 4

// from server: 97% by Intel
// roc 2012-06 004926c0  unit: InsertModelFromRobloxVerb  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004926c0
//
// 004926c0  a0a11ae300           mov al, byte ptr [0xe31aa1]
// 004926c5  56                   push esi
// 004926c6  8bf1                 mov esi, ecx
// 004926c8  84c0                 test al, al
// 004926ca  7413                 je 0x4926df
// 004926cc  6a00                 push 0
// 004926ce  0fb6c0               movzx eax, al
// 004926d1  6840e3b500           push 0xb5e340
// 004926d6  50                   push eax
// 004926d7  e80c791300           call 0x5c9fe8
// 004926dc  83c40c               add esp, 0xc
// 004926df  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004926e2  8b5120               mov edx, dword ptr [ecx + 0x20]
// 004926e5  6a00                 push 0
// 004926e7  68fe800000           push 0x80fe
// 004926ec  6811010000           push 0x111
// 004926f1  52                   push edx
// 004926f2  ff15243cb200         call dword ptr [0xb23c24]
// 004926f8  5e                   pop esi
// 004926f9  c20400               ret 4

extern unsigned char g_GlobalFlag;
extern const char g_GlobalString[];

extern "C" void __cdecl CallbackFunction(int, const char*, int);
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void*, unsigned int, unsigned int, long);

struct WindowContainer {
    char padding[0x20];
    void* windowHandle;
};

struct InsertModelFromRobloxVerb {
    char padding[0xC];
    WindowContainer* container;
    void Method(int arg);
};

void InsertModelFromRobloxVerb::Method(int arg)
{
    if (g_GlobalFlag) {
        CallbackFunction(g_GlobalFlag, g_GlobalString, 0);
    }
    WindowContainer* container = this->container;
    void* hwnd = container->windowHandle;
    PostMessageA(hwnd, 0x111, 0x80fd, 0);
}
