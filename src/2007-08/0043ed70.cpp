// from server: 100% by Intel
// from server: 99% by EspClaude
// roc 2007-08 0043ed70  unit: RefItem  size: 170 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043ed70
//
// 0043ed70  6aff                 push -1
// 0043ed72  68c8ed7300           push 0x73edc8
// 0043ed77  64a100000000         mov eax, dword ptr fs:[0]
// 0043ed7d  50                   push eax
// 0043ed7e  51                   push ecx
// 0043ed7f  56                   push esi
// 0043ed80  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043ed85  33c4                 xor eax, esp
// 0043ed87  50                   push eax
// 0043ed88  8d44240c             lea eax, [esp + 0xc]
// 0043ed8c  64a300000000         mov dword ptr fs:[0], eax
// 0043ed92  8bf1                 mov esi, ecx
// 0043ed94  89742408             mov dword ptr [esp + 8], esi
// 0043ed98  8b442420             mov eax, dword ptr [esp + 0x20]
// 0043ed9c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0043eda0  50                   push eax
// 0043eda1  51                   push ecx
// 0043eda2  8bce                 mov ecx, esi
// 0043eda4  e827dcffff           call 0x43c9d0
// 0043eda9  8bce                 mov ecx, esi
// 0043edab  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0043edb3  c706c4eb7800         mov dword ptr [esi], 0x78ebc4
// 0043edb9  c7462064eb7800       mov dword ptr [esi + 0x20], 0x78eb64
// 0043edc0  c786000100005ceb7800 mov dword ptr [esi + 0x100], 0x78eb5c
// 0043edca  e871a92400           call 0x689740
// 0043edcf  83c802               or eax, 2
// 0043edd2  50                   push eax
// 0043edd3  8bce                 mov ecx, esi
// 0043edd5  e8368c2500           call 0x697a10
// 0043edda  8bce                 mov ecx, esi
// 0043eddc  e85fa92400           call 0x689740
// 0043ede1  83e0fe               and eax, 0xfffffffe
// 0043ede4  50                   push eax
// 0043ede5  8bce                 mov ecx, esi
// 0043ede7  e8248c2500           call 0x697a10
// 0043edec  51                   push ecx
// 0043eded  8bcc                 mov ecx, esp
// 0043edef  89642424             mov dword ptr [esp + 0x24], esp
// 0043edf3  684ceb7800           push 0x78eb4c
// 0043edf8  ff15b8dd7700         call dword ptr [0x77ddb8]
// 0043edfe  8bce                 mov ecx, esi
// 0043ee00  e82b982500           call 0x698630
// 0043ee05  8bc6                 mov eax, esi
// 0043ee07  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0043ee0b  64890d00000000       mov dword ptr fs:[0], ecx
// 0043ee12  59                   pop ecx
// 0043ee13  5e                   pop esi
// 0043ee14  83c410               add esp, 0x10
// 0043ee17  c20800               ret 8

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727

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
    char padding[0xdc];
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
