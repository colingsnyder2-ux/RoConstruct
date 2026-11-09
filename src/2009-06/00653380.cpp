// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c6010  unit: RBX::VVisit::?$BoundFuncDesc  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c6010
//
// 005c6010  6aff                 push -1
// 005c6012  68814a7d00           push 0x7d4a81
// 005c6017  64a100000000         mov eax, dword ptr fs:[0]
// 005c601d  50                   push eax
// 005c601e  64892500000000       mov dword ptr fs:[0], esp
// 005c6025  83ec20               sub esp, 0x20
// 005c6028  56                   push esi
// 005c6029  8bf1                 mov esi, ecx
// 005c602b  68b8908300           push 0x8390b8
// 005c6030  8d4c240c             lea ecx, [esp + 0xc]
// 005c6034  89742408             mov dword ptr [esp + 8], esi
// 005c6038  ff1558248000         call dword ptr [0x802458]
// 005c603e  8b442434             mov eax, dword ptr [esp + 0x34]
// 005c6042  6874318300           push 0x833174
// 005c6047  50                   push eax
// 005c6048  8d4c2410             lea ecx, [esp + 0x10]
// 005c604c  51                   push ecx
// 005c604d  8bce                 mov ecx, esi
// 005c604f  c744243800000000     mov dword ptr [esp + 0x38], 0
// 005c6057  e8d494fbff           call 0x57f530
// 005c605c  8d4c2408             lea ecx, [esp + 8]
// 005c6060  c644242c02           mov byte ptr [esp + 0x2c], 2
// 005c6065  ff1568248000         call dword ptr [0x802468]
// 005c606b  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005c606f  c706a4908300         mov dword ptr [esi], 0x8390a4
// 005c6075  8bc6                 mov eax, esi
// 005c6077  5e                   pop esi
// 005c6078  64890d00000000       mov dword ptr fs:[0], ecx
// 005c607f  83c42c               add esp, 0x2c
// 005c6082  c20400               ret 4

struct String;

typedef String* (__thiscall *StringConstructor)(String*, const char*);
typedef void (__thiscall *StringDestructor)(String*);

extern StringConstructor stringConstructor;
extern StringDestructor stringDestructor;

struct String {
    char storage[28];
    String(const char*);
    ~String();
};

inline String::String(const char* text) {
    stringConstructor(this, text);
}

inline String::~String() {
    stringDestructor(this);
}

struct Base {
    Base(const String&, void*, const char*);
    virtual ~Base();
};

struct S : Base {
    S(void*);
    virtual ~S();
};

S::S(void* argument)
    : Base(String("AnchorVerb"), argument, "Anchored") {
}
