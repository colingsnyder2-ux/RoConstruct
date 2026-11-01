// from server: 100% by Yeetserama
// roc 2012-06 0045f2b0  unit: RefItem  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0045f2b0
//
// 0045f2b0  6aff                 push -1
// 0045f2b2  68c8f4a900           push 0xa9f4c8
// 0045f2b7  64a100000000         mov eax, dword ptr fs:[0]
// 0045f2bd  50                   push eax
// 0045f2be  64892500000000       mov dword ptr fs:[0], esp
// 0045f2c5  51                   push ecx
// 0045f2c6  8b442418             mov eax, dword ptr [esp + 0x18]
// 0045f2ca  56                   push esi
// 0045f2cb  8bf1                 mov esi, ecx
// 0045f2cd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0045f2d1  50                   push eax
// 0045f2d2  51                   push ecx
// 0045f2d3  8bce                 mov ecx, esi
// 0045f2d5  8974240c             mov dword ptr [esp + 0xc], esi
// 0045f2d9  e8929effff           call 0x459170
// 0045f2de  8bce                 mov ecx, esi
// 0045f2e0  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0045f2e8  c7061c6ab500         mov dword ptr [esi], 0xb56a1c
// 0045f2ee  c74620bc69b500       mov dword ptr [esi + 0x20], 0xb569bc
// 0045f2f5  c7860c010000b469b500 mov dword ptr [esi + 0x10c], 0xb569b4
// 0045f2ff  e81cd85700           call 0x9dcb20
// 0045f304  83c802               or eax, 2
// 0045f307  50                   push eax
// 0045f308  8bce                 mov ecx, esi
// 0045f30a  e841205900           call 0x9f1350
// 0045f30f  8bce                 mov ecx, esi
// 0045f311  e80ad85700           call 0x9dcb20
// 0045f316  83e0fe               and eax, 0xfffffffe
// 0045f319  50                   push eax
// 0045f31a  8bce                 mov ecx, esi
// 0045f31c  e82f205900           call 0x9f1350
// 0045f321  51                   push ecx
// 0045f322  8bcc                 mov ecx, esp
// 0045f324  89642420             mov dword ptr [esp + 0x20], esp
// 0045f328  68a469b500           push 0xb569a4
// 0045f32d  ff15c847b200         call dword ptr [0xb247c8]
// 0045f333  8bce                 mov ecx, esi
// 0045f335  e8062c5900           call 0x9f1f40
// 0045f33a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0045f33e  8bc6                 mov eax, esi
// 0045f340  64890d00000000       mov dword ptr fs:[0], ecx
// 0045f347  5e                   pop esi
// 0045f348  83c410               add esp, 0x10
// 0045f34b  c20800               ret 8
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