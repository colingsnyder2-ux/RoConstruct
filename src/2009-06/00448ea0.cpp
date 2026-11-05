// from server: 100% by EspClaude
// roc 2009-06 00448ea0  unit: CRobloxCommandLineInfo  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00448ea0
//
// 00448ea0  6aff                 push -1
// 00448ea2  68e5098500           push 0x8509e5
// 00448ea7  64a100000000         mov eax, dword ptr fs:[0]
// 00448ead  50                   push eax
// 00448eae  64892500000000       mov dword ptr fs:[0], esp
// 00448eb5  51                   push ecx
// 00448eb6  56                   push esi
// 00448eb7  8bf1                 mov esi, ecx
// 00448eb9  57                   push edi
// 00448eba  89742408             mov dword ptr [esp + 8], esi
// 00448ebe  c7060c738b00         mov dword ptr [esi], 0x8b730c
// 00448ec4  8bbe0c010000         mov edi, dword ptr [esi + 0x10c]
// 00448eca  c744241402000000     mov dword ptr [esp + 0x14], 2
// 00448ed2  85ff                 test edi, edi
// 00448ed4  7410                 je 0x448ee6
// 00448ed6  8bcf                 mov ecx, edi
// 00448ed8  e853c10700           call 0x4c5030
// 00448edd  57                   push edi
// 00448ede  e84ffb2c00           call 0x718a32
// 00448ee3  83c404               add esp, 4
// 00448ee6  8d8ef0000000         lea ecx, [esi + 0xf0]
// 00448eec  c644241401           mov byte ptr [esp + 0x14], 1
// 00448ef1  ff15c4e48900         call dword ptr [0x89e4c4]
// 00448ef7  8d8ea4000000         lea ecx, [esi + 0xa4]
// 00448efd  c644241400           mov byte ptr [esp + 0x14], 0
// 00448f02  e889a8fdff           call 0x423790
// 00448f07  8bce                 mov ecx, esi
// 00448f09  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00448f11  e8ca072d00           call 0x7196e0
// 00448f16  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00448f1a  5f                   pop edi
// 00448f1b  5e                   pop esi
// 00448f1c  64890d00000000       mov dword ptr fs:[0], ecx
// 00448f23  83c410               add esp, 0x10
// 00448f26  c3                   ret 
// copied from an identical function in another client (function ??1CRobloxModule@@UAE@XZ)

extern void (__thiscall *destroyString)(void *);

void __cdecl operator delete(void *);

struct Base
{
    virtual ~Base();
    char storage[0xa0];
};

struct Member
{
    char storage[0x4c];
    ~Member();
};

struct String
{
    char storage[0x1c];
    ~String();
};

inline String::~String()
{
    destroyString(this);
}

struct Document
{
    ~Document();
};

struct CRobloxModule : Base
{
    Member member;
    String text;
    Document *document;

    virtual ~CRobloxModule();
};

CRobloxModule::~CRobloxModule()
{
    delete document;
}