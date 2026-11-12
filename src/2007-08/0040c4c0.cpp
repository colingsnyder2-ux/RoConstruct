// from server: 100% by EspClaude
// from server: 43% by colin
// roc 2007-08 0040c4c0  unit: CBrowserView  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040c4c0
//
// 0040c4c0  6aff                 push -1
// 0040c4c2  68a69b7300           push 0x739ba6
// 0040c4c7  64a100000000         mov eax, dword ptr fs:[0]
// 0040c4cd  50                   push eax
// 0040c4ce  51                   push ecx
// 0040c4cf  56                   push esi
// 0040c4d0  57                   push edi
// 0040c4d1  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040c4d6  33c4                 xor eax, esp
// 0040c4d8  50                   push eax
// 0040c4d9  8d442410             lea eax, [esp + 0x10]
// 0040c4dd  64a300000000         mov dword ptr fs:[0], eax
// 0040c4e3  8bf1                 mov esi, ecx
// 0040c4e5  8974240c             mov dword ptr [esp + 0xc], esi
// 0040c4e9  c7063c5d7800         mov dword ptr [esi], 0x785d3c
// 0040c4ef  8d8eb8020000         lea ecx, [esi + 0x2b8]
// 0040c4f5  c744241801000000     mov dword ptr [esp + 0x18], 1
// 0040c4fd  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0040c503  8b86b0020000         mov eax, dword ptr [esi + 0x2b0]
// 0040c509  85c0                 test eax, eax
// 0040c50b  7408                 je 0x40c515
// 0040c50d  8b08                 mov ecx, dword ptr [eax]
// 0040c50f  8b5108               mov edx, dword ptr [ecx + 8]
// 0040c512  50                   push eax
// 0040c513  ffd2                 call edx
// 0040c515  8d8e08010000         lea ecx, [esi + 0x108]
// 0040c51b  e8f0282400           call 0x64ee10
// 0040c520  8dbef8000000         lea edi, [esi + 0xf8]
// 0040c526  8bcf                 mov ecx, edi
// 0040c528  c644241800           mov byte ptr [esp + 0x18], 0
// 0040c52d  e87ea01300           call 0x5465b0
// 0040c532  8b4704               mov eax, dword ptr [edi + 4]
// 0040c535  50                   push eax
// 0040c536  e827372200           call 0x62fc62
// 0040c53b  83c404               add esp, 4
// 0040c53e  8bce                 mov ecx, esi
// 0040c540  c7470400000000       mov dword ptr [edi + 4], 0
// 0040c547  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0040c54f  e8fce5ffff           call 0x40ab50
// 0040c554  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040c558  64890d00000000       mov dword ptr fs:[0], ecx
// 0040c55f  59                   pop ecx
// 0040c560  5f                   pop edi
// 0040c561  5e                   pop esi
// 0040c562  83c410               add esp, 0x10
// 0040c565  c3                   ret 

struct CWndBase {
    virtual ~CWndBase();
    char pad[0xf4];
};
void __cdecl operator delete(void*);
struct Buf {
    int a;
    void* p;
    void clear();
    ~Buf() { clear(); operator delete(p); p = 0; }
};
struct M108 { ~M108(); };
struct M2b8 { __declspec(dllimport) ~M2b8() throw(); };
struct IUnk { virtual long __stdcall QI(); virtual unsigned long __stdcall AddRef(); virtual unsigned long __stdcall Release(); };
struct Ptr { IUnk* p; ~Ptr() throw() { if (p) p->Release(); } };
struct CBrowserView : CWndBase {
    Buf m_f8;
    char pad100[8];
    M108 m_108;
    char pad109[0x2b0 - 0x109];
    Ptr m_2b0;
    int m_2b4;
    M2b8 m_2b8;
    virtual ~CBrowserView();
};
CBrowserView::~CBrowserView() {}
