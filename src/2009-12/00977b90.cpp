// from server: 100% by nuck16
// roc 2009-12 00977b90  unit: seg_00970000  size: 57 bytes
//
// 00977b90  56                   push esi
// 00977b91  33f6                 xor esi, esi
// 00977b93  56                   push esi
// 00977b94  6a02                 push 2
// 00977b96  33c9                 xor ecx, ecx
// 00977b98  51                   push ecx
// 00977b99  b8b0926f00           mov eax, 0x6f92b0
// 00977b9e  50                   push eax
// 00977b9f  56                   push esi
// 00977ba0  bae0476f00           mov edx, 0x6f47e0
// 00977ba5  52                   push edx
// 00977ba6  6884b09b00           push 0x9bb084
// 00977bab  6814ce9d00           push 0x9dce14
// 00977bb0  b95c49b900           mov ecx, 0xb9495c
// 00977bb5  e80607d8ff           call 0x6f82c0
// 00977bba  68e0729800           push 0x9872e0
// 00977bbf  e865cde7ff           call 0x7f4929
// 00977bc4  83c404               add esp, 4
// 00977bc7  5e                   pop esi
// 00977bc8  c3                   ret 

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

static Desc desc("Icon", "Data", &Owner::m0, &Owner::m1, 2, 0);
