// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00440db0  unit: CSelectionPropGrid  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00440db0
//
// 00440db0  6aff                 push -1
// 00440db2  6868087c00           push 0x7c0868
// 00440db7  64a100000000         mov eax, dword ptr fs:[0]
// 00440dbd  50                   push eax
// 00440dbe  64892500000000       mov dword ptr fs:[0], esp
// 00440dc5  51                   push ecx
// 00440dc6  8b442418             mov eax, dword ptr [esp + 0x18]
// 00440dca  56                   push esi
// 00440dcb  8bf1                 mov esi, ecx
// 00440dcd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00440dd1  50                   push eax
// 00440dd2  51                   push ecx
// 00440dd3  8bce                 mov ecx, esi
// 00440dd5  8974240c             mov dword ptr [esp + 0xc], esi
// 00440dd9  e842dcffff           call 0x43ea20
// 00440dde  51                   push ecx
// 00440ddf  8bcc                 mov ecx, esp
// 00440de1  89642420             mov dword ptr [esp + 0x20], esp
// 00440de5  6820568100           push 0x815620
// 00440dea  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00440df2  c70624558100         mov dword ptr [esi], 0x815524
// 00440df8  c74620c4548100       mov dword ptr [esi + 0x20], 0x8154c4
// 00440dff  c7860c010000bc548100 mov dword ptr [esi + 0x10c], 0x8154bc
// 00440e09  ff15103f8000         call dword ptr [0x803f10]
// 00440e0f  8bce                 mov ecx, esi
// 00440e11  e8da0b2d00           call 0x7119f0
// 00440e16  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00440e1a  8bc6                 mov eax, esi
// 00440e1c  64890d00000000       mov dword ptr fs:[0], ecx
// 00440e23  5e                   pop esi
// 00440e24  83c410               add esp, 0x10
// 00440e27  c20800               ret 8

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
