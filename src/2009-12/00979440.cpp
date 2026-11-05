// from server: 100% by nuck16
// roc 2009-12 00979440  unit: seg_00970000  size: 57 bytes
//
// 00979440  56                   push esi
// 00979441  33f6                 xor esi, esi
// 00979443  56                   push esi
// 00979444  6a0f                 push 0xf
// 00979446  33c9                 xor ecx, ecx
// 00979448  51                   push ecx
// 00979449  b8e0a17300           mov eax, 0x73a1e0
// 0097944e  50                   push eax
// 0097944f  56                   push esi
// 00979450  bae0f38200           mov edx, 0x82f3e0
// 00979455  52                   push edx
// 00979456  68141c9e00           push 0x9e1c14
// 0097945b  680c1c9e00           push 0x9e1c0c
// 00979460  b9fc66b900           mov ecx, 0xb966fc
// 00979465  e856efdbff           call 0x7383c0
// 0097946a  6870859800           push 0x988570
// 0097946f  e8b5b4e7ff           call 0x7f4929
// 00979474  83c404               add esp, 4
// 00979477  5e                   pop esi
// 00979478  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
    void m1();
};


struct Desc
{
    Desc(const char *, const char *, void (Owner::*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("Target", "Goals", &Owner::m0, &Owner::m1, 15, 0);
