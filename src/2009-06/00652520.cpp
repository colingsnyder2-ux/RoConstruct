// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c5300  unit: RBX::VVisit::?$BoundFuncDesc  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c5300
//
// 005c5300  6aff                 push -1
// 005c5302  68814a7d00           push 0x7d4a81
// 005c5307  64a100000000         mov eax, dword ptr fs:[0]
// 005c530d  50                   push eax
// 005c530e  64892500000000       mov dword ptr fs:[0], esp
// 005c5315  83ec20               sub esp, 0x20
// 005c5318  56                   push esi
// 005c5319  8bf1                 mov esi, ecx
// 005c531b  68888f8300           push 0x838f88
// 005c5320  8d4c240c             lea ecx, [esp + 0xc]
// 005c5324  89742408             mov dword ptr [esp + 8], esi
// 005c5328  ff1558248000         call dword ptr [0x802458]
// 005c532e  8b442434             mov eax, dword ptr [esp + 0x34]
// 005c5332  68d4568300           push 0x8356d4
// 005c5337  50                   push eax
// 005c5338  8d4c2410             lea ecx, [esp + 0x10]
// 005c533c  51                   push ecx
// 005c533d  8bce                 mov ecx, esi
// 005c533f  c744243800000000     mov dword ptr [esp + 0x38], 0
// 005c5347  e8e4a1fbff           call 0x57f530
// 005c534c  8d4c2408             lea ecx, [esp + 8]
// 005c5350  c644242c02           mov byte ptr [esp + 0x2c], 2
// 005c5355  ff1568248000         call dword ptr [0x802468]
// 005c535b  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005c535f  c706748f8300         mov dword ptr [esi], 0x838f74
// 005c5365  8bc6                 mov eax, esi
// 005c5367  5e                   pop esi
// 005c5368  64890d00000000       mov dword ptr fs:[0], ecx
// 005c536f  83c42c               add esp, 0x2c
// 005c5372  c20400               ret 4

struct String;
extern void (__thiscall *stringConstruct)(String *, const char *);
extern void (__thiscall *stringDestroy)(String *);

struct String {
    unsigned char storage[28];
    String(const char *s);
    ~String();
};

inline String::String(const char *s) {
    stringConstruct(this, s);
}

inline String::~String() {
    stringDestroy(this);
}

struct Base {
    Base(const String &, int, const char *);
    virtual ~Base();
};

struct S : Base {
    S(int);
    virtual ~S();
};

S::S(int value)
    : Base(String("TranslucentVerb"), value, "Transparent") {
}
