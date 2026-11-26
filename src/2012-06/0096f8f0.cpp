// from server: 100% by Xemicl
// roc 2012-06 0096f8f0  unit: W4_D3DFORMAT::?$EnumDesc  size: 298 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0096f8f0
//
// 0096f8f0  f605f87fe50001       test byte ptr [0xe57ff8], 1
// 0096f8f7  751e                 jne 0x96f917
// 0096f8f9  830df87fe50001       or dword ptr [0xe57ff8], 1
// 0096f900  b96074e500           mov ecx, 0xe57460
// 0096f905  e846edffff           call 0x96e650
// 0096f90a  68c014b200           push 0xb214c0
// 0096f90f  e8e1380100           call 0x9831f5
// 0096f914  83c404               add esp, 4
// 0096f917  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096f91e  55                   push ebp
// 0096f91f  8b2db821b200         mov ebp, dword ptr [0xb221b8]
// 0096f925  56                   push esi
// 0096f926  57                   push edi
// 0096f927  7407                 je 0x96f930
// 0096f929  684474e500           push 0xe57444
// 0096f92e  ffd5                 call ebp
// 0096f930  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096f937  8b356874e500         mov esi, dword ptr [0xe57468]
// 0096f93d  740b                 je 0x96f94a
// 0096f93f  684474e500           push 0xe57444
// 0096f944  ff15b421b200         call dword ptr [0xb221b4]
// 0096f94a  8bfe                 mov edi, esi
// 0096f94c  85f6                 test esi, esi
// 0096f94e  755a                 jne 0x96f9aa
// 0096f950  e8cb270000           call 0x972120
// 0096f955  f605f87fe50001       test byte ptr [0xe57ff8], 1
// 0096f95c  8bf8                 mov edi, eax
// 0096f95e  751e                 jne 0x96f97e
// 0096f960  830df87fe50001       or dword ptr [0xe57ff8], 1
// 0096f967  b96074e500           mov ecx, 0xe57460
// 0096f96c  e8dfecffff           call 0x96e650
// 0096f971  68c014b200           push 0xb214c0
// 0096f976  e87a380100           call 0x9831f5
// 0096f97b  83c404               add esp, 4
// 0096f97e  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096f985  7407                 je 0x96f98e
// 0096f987  684474e500           push 0xe57444
// 0096f98c  ffd5                 call ebp
// 0096f98e  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096f995  893d6874e500         mov dword ptr [0xe57468], edi
// 0096f99b  7414                 je 0x96f9b1
// 0096f99d  684474e500           push 0xe57444
// 0096f9a2  ff15b421b200         call dword ptr [0xb221b4]
// 0096f9a8  eb07                 jmp 0x96f9b1
// 0096f9aa  807c241000           cmp byte ptr [esp + 0x10], 0
// 0096f9af  7463                 je 0x96fa14
// 0096f9b1  53                   push ebx
// 0096f9b2  e859fdffff           call 0x96f710
// 0096f9b7  f605f87fe50001       test byte ptr [0xe57ff8], 1
// 0096f9be  8bd8                 mov ebx, eax
// 0096f9c0  751e                 jne 0x96f9e0
// 0096f9c2  830df87fe50001       or dword ptr [0xe57ff8], 1
// 0096f9c9  b96074e500           mov ecx, 0xe57460
// 0096f9ce  e87decffff           call 0x96e650
// 0096f9d3  68c014b200           push 0xb214c0
// 0096f9d8  e818380100           call 0x9831f5
// 0096f9dd  83c404               add esp, 4
// 0096f9e0  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096f9e7  7407                 je 0x96f9f0
// 0096f9e9  684474e500           push 0xe57444
// 0096f9ee  ffd5                 call ebp
// 0096f9f0  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096f9f7  8b35b876e500         mov esi, dword ptr [0xe576b8]
// 0096f9fd  740b                 je 0x96fa0a
// 0096f9ff  684474e500           push 0xe57444
// 0096fa04  ff15b421b200         call dword ptr [0xb221b4]
// 0096fa0a  56                   push esi
// 0096fa0b  53                   push ebx
// 0096fa0c  8bcf                 mov ecx, edi
// 0096fa0e  e80d220000           call 0x971c20
// 0096fa13  5b                   pop ebx
// 0096fa14  8bc7                 mov eax, edi
// 0096fa16  5f                   pop edi
// 0096fa17  5e                   pop esi
// 0096fa18  5d                   pop ebp
// 0096fa19  c3                   ret 
// copied from an identical function in another client (function ?getDevice@@YAPAUDevice@@_N@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);
struct CS { char data[0x18]; };
extern bool g_lockEnabled;
extern CS g_lock;
__forceinline void lockGlobals() { if (g_lockEnabled) EnterCriticalSection(&g_lock); }
__forceinline void unlockGlobals() { if (g_lockEnabled) LeaveCriticalSection(&g_lock); }
struct Context;
struct Device {
    long init(Context* ctx, void* arg);
};
struct Globals {
    Context* context;
    int pad4;
    Device* device;
    char pad[0x258 - 0xc];
    void* setting;
    char rest[0xb98 - 0x25c];
    Globals() throw();
    ~Globals();
};
__forceinline Globals& globals() { static Globals g; return g; }
Context* getContext();
Device* createDevice();
__forceinline Device* getStoredDevice() { Globals& g = globals(); lockGlobals(); Device* d = g.device; unlockGlobals(); return d; }
__forceinline void setStoredDevice(Device* d) { Globals& g = globals(); lockGlobals(); g.device = d; unlockGlobals(); }
__forceinline void* getSetting() { Globals& g = globals(); lockGlobals(); void* s = g.setting; unlockGlobals(); return s; }
Device* getDevice(bool reinit)
{
    Device* d = getStoredDevice();
    Device* result = d;
    if (d == 0) {
        result = createDevice();
        setStoredDevice(result);
    }
    if (d == 0 || reinit) {
        Context* ctx = getContext();
        void* s = getSetting();
        result->init(ctx, s);
    }
    return result;
}