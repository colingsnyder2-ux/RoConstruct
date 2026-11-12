// from server: 100% by EspClaude
// from server: 47% by colin
// roc 2007-08 006f5610  unit: CXTPControlCustom  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006f5610
// 006f5610  6aff                 push -1
// 006f5612  68488f7600           push 0x768f48
// 006f5617  64a100000000         mov eax, dword ptr fs:[0]
// 006f561d  50                   push eax
// 006f561e  51                   push ecx
// 006f561f  53                   push ebx
// 006f5620  56                   push esi
// 006f5621  57                   push edi
// 006f5622  a188518b00           mov eax, dword ptr [0x8b5188]
// 006f5627  33c4                 xor eax, esp
// 006f5629  50                   push eax
// 006f562a  8d442414             lea eax, [esp + 0x14]
// 006f562e  64a300000000         mov dword ptr fs:[0], eax
// 006f5634  8bf1                 mov esi, ecx
// 006f5636  89742410             mov dword ptr [esp + 0x10], esi
// 006f563a  e8214efdff           call 0x6ca460
// 006f563f  8dbe68010000         lea edi, [esi + 0x168]
// 006f5645  33db                 xor ebx, ebx
// 006f5647  8bcf                 mov ecx, edi
// 006f5649  895c241c             mov dword ptr [esp + 0x1c], ebx
// 006f564d  e8fed4faff           call 0x6a2b50
// 006f5652  8d8674010000         lea eax, [esi + 0x174]
// 006f5658  50                   push eax
// 006f5659  c70614c17d00         mov dword ptr [esi], 0x7dc114
// 006f565f  c74620b4c07d00       mov dword ptr [esi + 0x20], 0x7dc0b4
// 006f5666  c707a8c07d00         mov dword ptr [edi], 0x7dc0a8
// 006f566c  899e70010000         mov dword ptr [esi + 0x170], ebx
// 006f5672  ff1514ee7700         call dword ptr [0x77ee14]
// 006f5678  899e90010000         mov dword ptr [esi + 0x190], ebx
// 006f567e  c7868401000001000000 mov dword ptr [esi + 0x184], 1
// 006f5688  c786d400000010000000 mov dword ptr [esi + 0xd4], 0x10
// 006f5692  899e94010000         mov dword ptr [esi + 0x194], ebx
// 006f5698  8bc6                 mov eax, esi
// 006f569a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006f569e  64890d00000000       mov dword ptr fs:[0], ecx
// 006f56a5  59                   pop ecx
// 006f56a6  5f                   pop edi
// 006f56a7  5e                   pop esi
// 006f56a8  5b                   pop ebx
// 006f56a9  83c410               add esp, 0x10
// 006f56ac  c3                   ret 

struct tagRECT { long left, top, right, bottom; };
extern "C" __declspec(dllimport) int __stdcall SetRectEmpty(tagRECT*);

struct CXTPControlBase0 {
    virtual ~CXTPControlBase0();
    char pad0[0x1c];
};
struct CXTPControlBase20 {
    virtual void Base20Slot();
};
struct CXTPControl : public CXTPControlBase0, public CXTPControlBase20 {
    CXTPControl();
    virtual ~CXTPControl();
    char pad24[0xd4 - 0x24];
    int m_dwFlags;            // +0xd4
    char padd8[0x168 - 0xd8];
};
struct CXTPHookManagerHookAble {
    CXTPHookManagerHookAble();
    virtual ~CXTPHookManagerHookAble();
    int m_hook;
};

struct CXTPControlCustom : public CXTPControl, public CXTPHookManagerHookAble {
    CXTPControlCustom();
    virtual ~CXTPControlCustom();
    int m_hwndControl;        // +0x170
    tagRECT m_rcBorders;      // +0x174
    int m_verticalOptions;    // +0x184
    int pad188[2];
    int m_field190;           // +0x190
    int m_field194;           // +0x194
};

CXTPControlCustom::CXTPControlCustom()
{
    m_hwndControl = 0;
    SetRectEmpty(&m_rcBorders);
    m_field190 = 0;
    m_verticalOptions = 1;
    m_dwFlags = 0x10;
    m_field194 = 0;
}
