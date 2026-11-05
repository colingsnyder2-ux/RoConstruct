// from server: 100% by Yeetserama
// roc 2010-06 00646650  unit: RBX::SpecialShape  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00646650
//
// 00646650  6aff                 push -1
// 00646652  6851d09900           push 0x99d051
// 00646657  64a100000000         mov eax, dword ptr fs:[0]
// 0064665d  50                   push eax
// 0064665e  64892500000000       mov dword ptr fs:[0], esp
// 00646665  83ec20               sub esp, 0x20
// 00646668  56                   push esi
// 00646669  8bf1                 mov esi, ecx
// 0064666b  68f077a300           push 0xa377f0
// 00646670  8d4c240c             lea ecx, [esp + 0xc]
// 00646674  89742408             mov dword ptr [esp + 8], esi
// 00646678  ff1510a49e00         call dword ptr [0x9ea410]
// 0064667e  8b442434             mov eax, dword ptr [esp + 0x34]
// 00646682  68486ca300           push 0xa36c48
// 00646687  50                   push eax
// 00646688  8d4c2410             lea ecx, [esp + 0x10]
// 0064668c  51                   push ecx
// 0064668d  8bce                 mov ecx, esi
// 0064668f  c744243800000000     mov dword ptr [esp + 0x38], 0
// 00646697  e894d1f9ff           call 0x5e3830
// 0064669c  8d4c2408             lea ecx, [esp + 8]
// 006466a0  c644242c02           mov byte ptr [esp + 0x2c], 2
// 006466a5  ff1500a49e00         call dword ptr [0x9ea400]
// 006466ab  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006466af  c706dc77a300         mov dword ptr [esi], 0xa377dc
// 006466b5  8bc6                 mov eax, esi
// 006466b7  5e                   pop esi
// 006466b8  64890d00000000       mov dword ptr fs:[0], ecx
// 006466bf  83c42c               add esp, 0x2c
// 006466c2  c20400               ret 4
// copied from an identical function in another client (function ??0S@ns_ROCX000010@@QAE@PAX@Z)

namespace ns_ROCX000010 {
// from server: 100% by king_originala
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
}
