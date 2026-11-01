// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c8ea0  unit: RBX::LaserTool  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c8ea0
//
// 005c8ea0  6aff                 push -1
// 005c8ea2  6809e77c00           push 0x7ce709
// 005c8ea7  64a100000000         mov eax, dword ptr fs:[0]
// 005c8ead  50                   push eax
// 005c8eae  64892500000000       mov dword ptr fs:[0], esp
// 005c8eb5  83ec1c               sub esp, 0x1c
// 005c8eb8  56                   push esi
// 005c8eb9  57                   push edi
// 005c8eba  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 005c8ebe  8d442408             lea eax, [esp + 8]
// 005c8ec2  57                   push edi
// 005c8ec3  50                   push eax
// 005c8ec4  8bf1                 mov esi, ecx
// 005c8ec6  e8f5dcfdff           call 0x5a6bc0
// 005c8ecb  83c408               add esp, 8
// 005c8ece  897c2434             mov dword ptr [esp + 0x34], edi
// 005c8ed2  db442434             fild dword ptr [esp + 0x34]
// 005c8ed6  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005c8ede  85ff                 test edi, edi
// 005c8ee0  7d06                 jge 0x5c8ee8
// 005c8ee2  dc0540128100         fadd qword ptr [0x811240]
// 005c8ee8  50                   push eax
// 005c8ee9  dd9e30010000         fstp qword ptr [esi + 0x130]
// 005c8eef  8d8e38010000         lea ecx, [esi + 0x138]
// 005c8ef5  ff150c248000         call dword ptr [0x80240c]
// 005c8efb  8d4c2408             lea ecx, [esp + 8]
// 005c8eff  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 005c8f07  ff1568248000         call dword ptr [0x802468]
// 005c8f0d  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005c8f11  5f                   pop edi
// 005c8f12  5e                   pop esi
// 005c8f13  64890d00000000       mov dword ptr fs:[0], ecx
// 005c8f1a  83c428               add esp, 0x28
// 005c8f1d  c20400               ret 4

struct String;

extern void (__thiscall *destroyString)(String *);
extern String *(__thiscall *assignString)(String *, const String *);

struct String {
    char storage[28];
    ~String();
};

__forceinline String::~String()
{
    destroyString(this);
}

extern String __cdecl formatValue(unsigned int);

struct LaserTool {
    char padding[0x90];
    double value;
    String label;

    void setValue(unsigned int);
    void applyValue(const String &, unsigned int);
};

__forceinline void LaserTool::applyValue(const String &text, unsigned int n)
{
    value = n;
    assignString(&label, &text);
}

void LaserTool::setValue(unsigned int n)
{
    applyValue(formatValue(n), n);
}
