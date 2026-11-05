// from server: 100% by colin
// from server: 96% by king_originala
// roc 2008-06 005cf870  unit: ChatEnter  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005cf870
//
// 005cf870  6aff                 push -1
// 005cf872  68496b7c00           push 0x7c6b49
// 005cf877  64a100000000         mov eax, dword ptr fs:[0]
// 005cf87d  50                   push eax
// 005cf87e  64892500000000       mov dword ptr fs:[0], esp
// 005cf885  51                   push ecx
// 005cf886  56                   push esi
// 005cf887  8bf1                 mov esi, ecx
// 005cf889  57                   push edi
// 005cf88a  89742408             mov dword ptr [esp + 8], esi
// 005cf88e  ff1560248000         call dword ptr [0x802460]
// 005cf894  33ff                 xor edi, edi
// 005cf896  897c2414             mov dword ptr [esp + 0x14], edi
// 005cf89a  e8d149f8ff           call 0x554270
// 005cf89f  d9ee                 fldz 
// 005cf8a1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005cf8a5  89461c               mov dword ptr [esi + 0x1c], eax
// 005cf8a8  d95630               fst dword ptr [esi + 0x30]
// 005cf8ab  897e20               mov dword ptr [esi + 0x20], edi
// 005cf8ae  d95e34               fstp dword ptr [esi + 0x34]
// 005cf8b1  897e24               mov dword ptr [esi + 0x24], edi
// 005cf8b4  897e28               mov dword ptr [esi + 0x28], edi
// 005cf8b7  897e2c               mov dword ptr [esi + 0x2c], edi
// 005cf8ba  5f                   pop edi
// 005cf8bb  8bc6                 mov eax, esi
// 005cf8bd  5e                   pop esi
// 005cf8be  64890d00000000       mov dword ptr fs:[0], ecx
// 005cf8c5  83c410               add esp, 0x10
// 005cf8c8  c3                   ret 

struct Name;
extern const Name& __cdecl getLocalScope();

typedef void (__thiscall *StringConstructor)(void*);
extern StringConstructor stringConstructor;

struct String
{
    char data[28];
    String() { stringConstructor(this); }
    ~String();
};

struct ScopeRef
{
    const Name* p;
    ScopeRef(const Name& n) : p(&n) {}
};

struct ChatEnter
{
    String text;
    ScopeRef scope;
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    float x;
    float y;

    ChatEnter();
};

ChatEnter::ChatEnter()
    : scope(getLocalScope()),
      a(0), b(0), c(0), d(0), x(0.0f), y(0.0f)
{
}
