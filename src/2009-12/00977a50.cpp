// from server: 100% by nuck16
// roc 2009-12 00977a50  unit: seg_00970000  size: 57 bytes
//
// 00977a50  56                   push esi
// 00977a51  33f6                 xor esi, esi
// 00977a53  56                   push esi
// 00977a54  6a02                 push 2
// 00977a56  33c9                 xor ecx, ecx
// 00977a58  51                   push ecx
// 00977a59  b800936f00           mov eax, 0x6f9300
// 00977a5e  50                   push eax
// 00977a5f  56                   push esi
// 00977a60  ba10486f00           mov edx, 0x6f4810
// 00977a65  52                   push edx
// 00977a66  6884b09b00           push 0x9bb084
// 00977a6b  68cccd9d00           push 0x9dcdcc
// 00977a70  b9dc4ab900           mov ecx, 0xb94adc
// 00977a75  e83606d8ff           call 0x6f80b0
// 00977a7a  68c0729800           push 0x9872c0
// 00977a7f  e8a5cee7ff           call 0x7f4929
// 00977a84  83c404               add esp, 4
// 00977a87  5e                   pop esi
// 00977a88  c3                   ret 

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

static Desc desc("MouseHit", "Data", &Owner::m0, &Owner::m1, 2, 0);
