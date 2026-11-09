// from server: 100% by nuck16
// roc 2009-12 00977a90  unit: seg_00970000  size: 57 bytes
//
// 00977a90  56                   push esi
// 00977a91  33f6                 xor esi, esi
// 00977a93  56                   push esi
// 00977a94  6a02                 push 2
// 00977a96  33c9                 xor ecx, ecx
// 00977a98  51                   push ecx
// 00977a99  b8a0936f00           mov eax, 0x6f93a0
// 00977a9e  50                   push eax
// 00977a9f  56                   push esi
// 00977aa0  ba40486f00           mov edx, 0x6f4840
// 00977aa5  52                   push edx
// 00977aa6  6884b09b00           push 0x9bb084
// 00977aab  68d8cd9d00           push 0x9dcdd8
// 00977ab0  b9a04bb900           mov ecx, 0xb94ba0
// 00977ab5  e8f605d8ff           call 0x6f80b0
// 00977aba  68a0729800           push 0x9872a0
// 00977abf  e865cee7ff           call 0x7f4929
// 00977ac4  83c404               add esp, 4
// 00977ac7  5e                   pop esi
// 00977ac8  c3                   ret 

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

static Desc desc("MouseOrigin", "Data", &Owner::m0, &Owner::m1, 2, 0);
