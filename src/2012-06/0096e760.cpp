// from server: 100% by Xemicl
// roc 2012-06 0096e760  unit: W4_D3DFORMAT::?$EnumDesc  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0096e760
//
// 0096e760  53                   push ebx
// 0096e761  56                   push esi
// 0096e762  57                   push edi
// 0096e763  e8080f0000           call 0x96f670
// 0096e768  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096e76f  8b3db821b200         mov edi, dword ptr [0xb221b8]
// 0096e775  8bf0                 mov esi, eax
// 0096e777  7407                 je 0x96e780
// 0096e779  684474e500           push 0xe57444
// 0096e77e  ffd7                 call edi
// 0096e780  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096e787  8b760c               mov esi, dword ptr [esi + 0xc]
// 0096e78a  8b1db421b200         mov ebx, dword ptr [0xb221b4]
// 0096e790  7407                 je 0x96e799
// 0096e792  684474e500           push 0xe57444
// 0096e797  ffd3                 call ebx
// 0096e799  85f6                 test esi, esi
// 0096e79b  742a                 je 0x96e7c7
// 0096e79d  837e3000             cmp dword ptr [esi + 0x30], 0
// 0096e7a1  0f95c0               setne al
// 0096e7a4  84c0                 test al, al
// 0096e7a6  741f                 je 0x96e7c7
// 0096e7a8  e8c30e0000           call 0x96f670
// 0096e7ad  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096e7b4  8bf0                 mov esi, eax
// 0096e7b6  7407                 je 0x96e7bf
// 0096e7b8  684474e500           push 0xe57444
// 0096e7bd  ffd7                 call edi
// 0096e7bf  8bb668010000         mov esi, dword ptr [esi + 0x168]
// 0096e7c5  eb1d                 jmp 0x96e7e4
// 0096e7c7  e8a40e0000           call 0x96f670
// 0096e7cc  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096e7d3  8bf0                 mov esi, eax
// 0096e7d5  7407                 je 0x96e7de
// 0096e7d7  684474e500           push 0xe57444
// 0096e7dc  ffd7                 call edi
// 0096e7de  8bb664010000         mov esi, dword ptr [esi + 0x164]
// 0096e7e4  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096e7eb  7407                 je 0x96e7f4
// 0096e7ed  684474e500           push 0xe57444
// 0096e7f2  ffd3                 call ebx
// 0096e7f4  5f                   pop edi
// 0096e7f5  8bc6                 mov eax, esi
// 0096e7f7  5e                   pop esi
// 0096e7f8  5b                   pop ebx
// 0096e7f9  c3                   ret 
// copied from an identical function in another client (function ?getTopWindow@@YAPAUHWND__@@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CRITICAL_SECTION { void* a; long b, c; void* d, *e; unsigned long f; };
typedef struct HWND__* HWND;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
extern bool g_threaded;
extern CRITICAL_SECTION g_cs;
struct AutoLock {
    AutoLock() { if (g_threaded) EnterCriticalSection(&g_cs); }
    ~AutoLock() { if (g_threaded) LeaveCriticalSection(&g_cs); }
};
struct Doc {
    char pad[0x30];
    void* view;
    bool hasView() const { return view != 0; }
};
struct App {
    char pad[0xc];
    Doc* doc;
    char pad2[0x164 - 0x10];
    HWND mainWnd;
    HWND docWnd;
    Doc* getDoc() { AutoLock l; return doc; }
    HWND getMainWnd() { AutoLock l; return mainWnd; }
    HWND getDocWnd() { AutoLock l; return docWnd; }
};
App& getApp();
HWND getTopWindow()
{
    Doc* d = getApp().getDoc();
    if (d ? d->hasView() : false)
        return getApp().getDocWnd();
    return getApp().getMainWnd();
}