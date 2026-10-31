// from server: 100% by EspClaude
// roc 2009-06 00438720  unit: RefItem  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00438720
//
// 00438720  6aff                 push -1
// 00438722  68a8fc8400           push 0x84fca8
// 00438727  64a100000000         mov eax, dword ptr fs:[0]
// 0043872d  50                   push eax
// 0043872e  64892500000000       mov dword ptr fs:[0], esp
// 00438735  51                   push ecx
// 00438736  8b442418             mov eax, dword ptr [esp + 0x18]
// 0043873a  56                   push esi
// 0043873b  8bf1                 mov esi, ecx
// 0043873d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00438741  50                   push eax
// 00438742  51                   push ecx
// 00438743  8bce                 mov ecx, esi
// 00438745  8974240c             mov dword ptr [esp + 0xc], esi
// 00438749  e872d2ffff           call 0x4359c0
// 0043874e  8bce                 mov ecx, esi
// 00438750  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00438758  c706a4538b00         mov dword ptr [esi], 0x8b53a4
// 0043875e  c7462044538b00       mov dword ptr [esi + 0x20], 0x8b5344
// 00438765  c7860c0100003c538b00 mov dword ptr [esi + 0x10c], 0x8b533c
// 0043876f  e85cba0700           call 0x4b41d0
// 00438774  83c802               or eax, 2
// 00438777  50                   push eax
// 00438778  8bce                 mov ecx, esi
// 0043877a  e8710e3500           call 0x7895f0
// 0043877f  8bce                 mov ecx, esi
// 00438781  e84aba0700           call 0x4b41d0
// 00438786  83e0fe               and eax, 0xfffffffe
// 00438789  50                   push eax
// 0043878a  8bce                 mov ecx, esi
// 0043878c  e85f0e3500           call 0x7895f0
// 00438791  51                   push ecx
// 00438792  8bcc                 mov ecx, esp
// 00438794  89642420             mov dword ptr [esp + 0x20], esp
// 00438798  682c538b00           push 0x8b532c
// 0043879d  ff1508fd8900         call dword ptr [0x89fd08]
// 004387a3  8bce                 mov ecx, esi
// 004387a5  e8361a3500           call 0x78a1e0
// 004387aa  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004387ae  8bc6                 mov eax, esi
// 004387b0  64890d00000000       mov dword ptr fs:[0], ecx
// 004387b7  5e                   pop esi
// 004387b8  83c410               add esp, 0x10
// 004387bb  c20800               ret 8
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