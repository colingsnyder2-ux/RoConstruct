// from server: 100% by Yeetserama
// roc 2010-06 00645840  unit: RBX::SpecialShape  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00645840
//
// 00645840  6aff                 push -1
// 00645842  6851d09900           push 0x99d051
// 00645847  64a100000000         mov eax, dword ptr fs:[0]
// 0064584d  50                   push eax
// 0064584e  64892500000000       mov dword ptr fs:[0], esp
// 00645855  83ec20               sub esp, 0x20
// 00645858  56                   push esi
// 00645859  8bf1                 mov esi, ecx
// 0064585b  68c076a300           push 0xa376c0
// 00645860  8d4c240c             lea ecx, [esp + 0xc]
// 00645864  89742408             mov dword ptr [esp + 8], esi
// 00645868  ff1510a49e00         call dword ptr [0x9ea410]
// 0064586e  8b442434             mov eax, dword ptr [esp + 0x34]
// 00645872  681428a300           push 0xa32814
// 00645877  50                   push eax
// 00645878  8d4c2410             lea ecx, [esp + 0x10]
// 0064587c  51                   push ecx
// 0064587d  8bce                 mov ecx, esi
// 0064587f  c744243800000000     mov dword ptr [esp + 0x38], 0
// 00645887  e8a4dff9ff           call 0x5e3830
// 0064588c  8d4c2408             lea ecx, [esp + 8]
// 00645890  c644242c02           mov byte ptr [esp + 0x2c], 2
// 00645895  ff1500a49e00         call dword ptr [0x9ea400]
// 0064589b  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0064589f  c706ac76a300         mov dword ptr [esi], 0xa376ac
// 006458a5  8bc6                 mov eax, esi
// 006458a7  5e                   pop esi
// 006458a8  64890d00000000       mov dword ptr fs:[0], ecx
// 006458af  83c42c               add esp, 0x2c
// 006458b2  c20400               ret 4
// copied from an identical function in another client (function ??0S@ns_ROCX00000e@@QAE@H@Z)

namespace ns_ROCX00000e {
// from server: 100% by king_originala
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
}
