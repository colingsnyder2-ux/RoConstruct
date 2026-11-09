// from server: 100% by nuck16
// roc 2009-12 00977bd0  unit: seg_00970000  size: 57 bytes
//
// 00977bd0  56                   push esi
// 00977bd1  33f6                 xor esi, esi
// 00977bd3  56                   push esi
// 00977bd4  6a0f                 push 0xf
// 00977bd6  33c9                 xor ecx, ecx
// 00977bd8  51                   push ecx
// 00977bd9  b860ca6f00           mov eax, 0x6fca60
// 00977bde  50                   push eax
// 00977bdf  56                   push esi
// 00977be0  ba40bf6f00           mov edx, 0x6fbf40
// 00977be5  52                   push edx
// 00977be6  6884b09b00           push 0x9bb084
// 00977beb  68c0d09d00           push 0x9dd0c0
// 00977bf0  b9c04bb900           mov ecx, 0xb94bc0
// 00977bf5  e8a64ad8ff           call 0x6fc6a0
// 00977bfa  68a0759800           push 0x9875a0
// 00977bff  e825cde7ff           call 0x7f4929
// 00977c04  83c404               add esp, 4
// 00977c07  5e                   pop esi
// 00977c08  c3                   ret 

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

static Desc desc("ShowDevelopmentGui", "Data", &Owner::m0, &Owner::m1, 15, 0);
