// from server: 100% by Yeetserama
// roc 2010-06 0043d810  unit: RefItem  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0043d810
//
// 0043d810  6aff                 push -1
// 0043d812  68780d9800           push 0x980d78
// 0043d817  64a100000000         mov eax, dword ptr fs:[0]
// 0043d81d  50                   push eax
// 0043d81e  64892500000000       mov dword ptr fs:[0], esp
// 0043d825  51                   push ecx
// 0043d826  8b442418             mov eax, dword ptr [esp + 0x18]
// 0043d82a  56                   push esi
// 0043d82b  8bf1                 mov esi, ecx
// 0043d82d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0043d831  50                   push eax
// 0043d832  51                   push ecx
// 0043d833  8bce                 mov ecx, esi
// 0043d835  8974240c             mov dword ptr [esp + 0xc], esi
// 0043d839  e812acffff           call 0x438450
// 0043d83e  8bce                 mov ecx, esi
// 0043d840  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0043d848  c7063ca1a000         mov dword ptr [esi], 0xa0a13c
// 0043d84e  c74620dca0a000       mov dword ptr [esi + 0x20], 0xa0a0dc
// 0043d855  c7860c010000d4a0a000 mov dword ptr [esi + 0x10c], 0xa0a0d4
// 0043d85f  e8dcb93c00           call 0x809240
// 0043d864  83c802               or eax, 2
// 0043d867  50                   push eax
// 0043d868  8bce                 mov ecx, esi
// 0043d86a  e861ad3d00           call 0x8185d0
// 0043d86f  8bce                 mov ecx, esi
// 0043d871  e8cab93c00           call 0x809240
// 0043d876  83e0fe               and eax, 0xfffffffe
// 0043d879  50                   push eax
// 0043d87a  8bce                 mov ecx, esi
// 0043d87c  e84fad3d00           call 0x8185d0
// 0043d881  51                   push ecx
// 0043d882  8bcc                 mov ecx, esp
// 0043d884  89642420             mov dword ptr [esp + 0x20], esp
// 0043d888  68c4a0a000           push 0xa0a0c4
// 0043d88d  ff15e8ce9e00         call dword ptr [0x9ecee8]
// 0043d893  8bce                 mov ecx, esi
// 0043d895  e816b93d00           call 0x8191b0
// 0043d89a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0043d89e  8bc6                 mov eax, esi
// 0043d8a0  64890d00000000       mov dword ptr fs:[0], ecx
// 0043d8a7  5e                   pop esi
// 0043d8a8  83c410               add esp, 0x10
// 0043d8ab  c20800               ret 8
// copied from an identical function in another client (function ??0ScriptItem@@QAE@PAUSource@@H@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct CStr {
    __declspec(dllimport) CStr(const char*);
    __declspec(dllimport) CStr(const CStr&);
    __declspec(dllimport) ~CStr();
    char* p;
};

struct Source;

struct First {
    virtual ~First();
    char padding[0x1c];
};

struct Second {
    virtual ~Second();
    char padding[0xd8];
    int flag;
    char tail[0xc];
};

struct Base : First, Second {
    Base(const char*, int, int);
    ~Base();
    int GetFlags();
    void SetFlags(int);
    void SetValue(CStr);
};

struct Link {
    virtual ~Link();
    char padding[0x1c];
    Link(Source*, int);
};

struct Item : Base, Link {
    Source* source;
    Item(Source*, int);
    virtual ~Item();
};

struct ScriptItem : Item {
    ScriptItem(Source*, int);
    virtual ~ScriptItem();
};

ScriptItem::ScriptItem(Source* input, int option)
    : Item(input, option)
{
    SetFlags(GetFlags() | 2);
    SetFlags(GetFlags() & ~1);
    SetValue("(Script)");
}