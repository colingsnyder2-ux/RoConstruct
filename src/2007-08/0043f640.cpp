// from server: 99% by EspClaude
// roc-cl: 50727
// from server: 100% by colin
// roc 2008-06 00440d30  unit: CSelectionPropGrid  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00440d30
//
// 00440d30  6aff                 push -1
// 00440d32  6868087c00           push 0x7c0868
// 00440d37  64a100000000         mov eax, dword ptr fs:[0]
// 00440d3d  50                   push eax
// 00440d3e  64892500000000       mov dword ptr fs:[0], esp
// 00440d45  51                   push ecx
// 00440d46  8b442418             mov eax, dword ptr [esp + 0x18]
// 00440d4a  56                   push esi
// 00440d4b  8bf1                 mov esi, ecx
// 00440d4d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00440d51  50                   push eax
// 00440d52  51                   push ecx
// 00440d53  8bce                 mov ecx, esi
// 00440d55  8974240c             mov dword ptr [esp + 0xc], esi
// 00440d59  e8e2daffff           call 0x43e840
// 00440d5e  51                   push ecx
// 00440d5f  8bcc                 mov ecx, esp
// 00440d61  89642420             mov dword ptr [esp + 0x20], esp
// 00440d65  68b0548100           push 0x8154b0
// 00440d6a  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00440d72  c706b4538100         mov dword ptr [esi], 0x8153b4
// 00440d78  c7462054538100       mov dword ptr [esi + 0x20], 0x815354
// 00440d7f  c7860c0100004c538100 mov dword ptr [esi + 0x10c], 0x81534c
// 00440d89  ff15103f8000         call dword ptr [0x803f10]
// 00440d8f  8bce                 mov ecx, esi
// 00440d91  e85a0c2d00           call 0x7119f0
// 00440d96  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00440d9a  8bc6                 mov eax, esi
// 00440d9c  64890d00000000       mov dword ptr fs:[0], ecx
// 00440da3  5e                   pop esi
// 00440da4  83c410               add esp, 0x10
// 00440da7  c20800               ret 8

struct String;

struct String
{
    char* data;
    __declspec(dllimport) __forceinline String(const char*);
    String(const String&);
    ~String();
};



extern const char description[];

struct First
{
    virtual ~First();
    char padding[0x1c];
};

struct Second
{
    virtual ~Second();
    char padding[0xe8];
};

struct Third
{
    virtual ~Third();
};

struct Base : First, Second, Third
{
    Base(int, int);
    virtual ~Base();
    void SetDescription(String);
};

struct S : Base
{
    S(int, int);
    virtual ~S();
};

S::S(int a, int b) : Base(a, b)
{
    SetDescription(String(description));
}
