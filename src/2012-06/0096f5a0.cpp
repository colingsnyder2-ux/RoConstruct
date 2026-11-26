// from server: 100% by Xemicl
// roc 2012-06 0096f5a0  unit: W4_D3DFORMAT::?$EnumDesc  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0096f5a0
//
// 0096f5a0  e8bbf1ffff           call 0x96e760
// 0096f5a5  85c0                 test eax, eax
// 0096f5a7  740d                 je 0x96f5b6
// 0096f5a9  6a00                 push 0
// 0096f5ab  6a00                 push 0
// 0096f5ad  6a10                 push 0x10
// 0096f5af  50                   push eax
// 0096f5b0  ff15bc3bb200         call dword ptr [0xb23bbc]
// 0096f5b6  53                   push ebx
// 0096f5b7  56                   push esi
// 0096f5b8  57                   push edi
// 0096f5b9  6a01                 push 1
// 0096f5bb  e820f5ffff           call 0x96eae0
// 0096f5c0  83c404               add esp, 4
// 0096f5c3  e8a8000000           call 0x96f670
// 0096f5c8  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096f5cf  8b1db821b200         mov ebx, dword ptr [0xb221b8]
// 0096f5d5  8bf0                 mov esi, eax
// 0096f5d7  7407                 je 0x96f5e0
// 0096f5d9  684474e500           push 0xe57444
// 0096f5de  ffd3                 call ebx
// 0096f5e0  8b3db421b200         mov edi, dword ptr [0xb221b4]
// 0096f5e6  c7460800000000       mov dword ptr [esi + 8], 0
// 0096f5ed  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096f5f4  7407                 je 0x96f5fd
// 0096f5f6  684474e500           push 0xe57444
// 0096f5fb  ffd7                 call edi
// 0096f5fd  e80e010000           call 0x96f710
// 0096f602  85c0                 test eax, eax
// 0096f604  7408                 je 0x96f60e
// 0096f606  8b08                 mov ecx, dword ptr [eax]
// 0096f608  8b5108               mov edx, dword ptr [ecx + 8]
// 0096f60b  50                   push eax
// 0096f60c  ffd2                 call edx
// 0096f60e  e85d000000           call 0x96f670
// 0096f613  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096f61a  8bf0                 mov esi, eax
// 0096f61c  7407                 je 0x96f625
// 0096f61e  684474e500           push 0xe57444
// 0096f623  ffd3                 call ebx
// 0096f625  c70600000000         mov dword ptr [esi], 0
// 0096f62b  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096f632  7407                 je 0x96f63b
// 0096f634  684474e500           push 0xe57444
// 0096f639  ffd7                 call edi
// 0096f63b  5f                   pop edi
// 0096f63c  5e                   pop esi
// 0096f63d  5b                   pop ebx
// 0096f63e  c3                   ret 
// copied from an identical function in another client (function ?shutdown@@YAXXZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CRITICAL_SECTION_ { char data[24]; };
struct HWND__; typedef HWND__* HWND;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION_*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION_*);
extern "C" __declspec(dllimport) long __stdcall SendMessageW(HWND, unsigned int, unsigned int, long);
extern bool g_lockEnabled;
extern CRITICAL_SECTION_ g_cs;
struct ScopedLock {
    ScopedLock() { if (g_lockEnabled) EnterCriticalSection(&g_cs); }
    ~ScopedLock() { if (g_lockEnabled) LeaveCriticalSection(&g_cs); }
};
struct IUnk {
    virtual long __stdcall QueryInterface(const void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
struct Registry {
    IUnk* value;
    int a;
    int b;
    static Registry& instance();
};
HWND getWindow();
void stopAll(int);
IUnk* getRegistryValue();
void shutdown()
{
    HWND h = getWindow();
    if (h)
        SendMessageW(h, 0x10, 0, 0);
    stopAll(1);
    {
        Registry& r = Registry::instance();
        ScopedLock lock;
        r.b = 0;
    }
    IUnk* p = getRegistryValue();
    if (p)
        p->Release();
    {
        Registry& r = Registry::instance();
        ScopedLock lock;
        r.value = 0;
    }
}