// from server: 100% by Intel
// from server: 98% by EspClaude
// roc-cl: 50727
// from server: 100% by colin
// roc 2008-06 00437ae0  unit: CPropertyGridItemBrickColor  size: 171 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00437ae0
//
// 00437ae0  6aff                 push -1
// 00437ae2  6801037c00           push 0x7c0301
// 00437ae7  64a100000000         mov eax, dword ptr fs:[0]
// 00437aed  50                   push eax
// 00437aee  64892500000000       mov dword ptr fs:[0], esp
// 00437af5  51                   push ecx
// 00437af6  56                   push esi
// 00437af7  8bf1                 mov esi, ecx
// 00437af9  57                   push edi
// 00437afa  89742408             mov dword ptr [esp + 8], esi
// 00437afe  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00437b02  6a00                 push 0
// 00437b04  57                   push edi
// 00437b05  8d4c2424             lea ecx, [esp + 0x24]
// 00437b09  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00437b11  ff15e03e8000         call dword ptr [0x803ee0]
// 00437b17  50                   push eax
// 00437b18  8bce                 mov ecx, esi
// 00437b1a  e861c02d00           call 0x713b80
// 00437b1f  51                   push ecx
// 00437b20  8bc4                 mov eax, esp
// 00437b22  89642424             mov dword ptr [esp + 0x24], esp
// 00437b26  57                   push edi
// 00437b27  50                   push eax
// 00437b28  c644242001           mov byte ptr [esp + 0x20], 1
// 00437b2d  c70644368100         mov dword ptr [esi], 0x813644
// 00437b33  c74620e4358100       mov dword ptr [esi + 0x20], 0x8135e4
// 00437b3a  c7868c00000004000000 mov dword ptr [esi + 0x8c], 4
// 00437b44  89be0c010000         mov dword ptr [esi + 0x10c], edi
// 00437b4a  e8d1feffff           call 0x437a20
// 00437b4f  83c408               add esp, 8
// 00437b52  8bce                 mov ecx, esi
// 00437b54  e8979e2d00           call 0x7119f0
// 00437b59  8d8ea4000000         lea ecx, [esi + 0xa4]
// 00437b5f  51                   push ecx
// 00437b60  8d8ea8000000         lea ecx, [esi + 0xa8]
// 00437b66  ff1544318000         call dword ptr [0x803144]
// 00437b6c  8d4c241c             lea ecx, [esp + 0x1c]
// 00437b70  ff15143f8000         call dword ptr [0x803f14]
// 00437b76  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00437b7a  5f                   pop edi
// 00437b7b  8bc6                 mov eax, esi
// 00437b7d  64890d00000000       mov dword ptr fs:[0], ecx
// 00437b84  5e                   pop esi
// 00437b85  83c410               add esp, 0x10
// 00437b88  c20800               ret 8

struct String;
typedef const String& (__thiscall *PrepareProc)(String*, int, int);
typedef void (__thiscall *DestroyProc)(String*);
typedef void (__thiscall *AssignProc)(void*, const String*);

extern PrepareProc prepareString;
extern DestroyProc destroyString;
extern AssignProc assignString;
extern char primaryTable[];
extern char secondaryTable[];

struct String
{
    void* data;
    String(const String&);
    __declspec(dllimport) ~String() throw();
};



String __cdecl makeValue(int);

struct Binding
{
    char data[92];
};

struct Base
{
    Base(const String&);
    ~Base();
    void setValue(String);

    void* primaryTable;
    char reserved04[28];
    void* secondaryTable;
    char reserved24[104];
    int type;
    char reserved90[16];
    String value;
    Binding binding;
};

struct S : Base
{
    int color;
    S(String caption, int colorValue);
};

S::S(String caption, int colorValue)
    : Base(prepareString(&caption, colorValue, 0))
{
    primaryTable = ::primaryTable;
    secondaryTable = ::secondaryTable;
    type = 4;
    color = colorValue;
    setValue(makeValue(colorValue));
    assignString(&binding, &value);
}
