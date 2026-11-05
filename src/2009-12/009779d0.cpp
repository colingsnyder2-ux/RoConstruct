// from server: 100% by nuck16
// roc 2009-12 009779d0  unit: seg_00970000  size: 57 bytes
//
// 009779d0  56                   push esi
// 009779d1  33f6                 xor esi, esi
// 009779d3  56                   push esi
// 009779d4  6a02                 push 2
// 009779d6  33c9                 xor ecx, ecx
// 009779d8  51                   push ecx
// 009779d9  b8a0476f00           mov eax, 0x6f47a0
// 009779de  50                   push eax
// 009779df  56                   push esi
// 009779e0  ba70476f00           mov edx, 0x6f4770
// 009779e5  52                   push edx
// 009779e6  6884b09b00           push 0x9bb084
// 009779eb  68b4cd9d00           push 0x9dcdb4
// 009779f0  b9d449b900           mov ecx, 0xb949d4
// 009779f5  e80606d8ff           call 0x6f8000
// 009779fa  6840729800           push 0x987240
// 009779ff  e825cfe7ff           call 0x7f4929
// 00977a04  83c404               add esp, 4
// 00977a07  5e                   pop esi
// 00977a08  c3                   ret 

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

static Desc desc("MouseDelta", "Data", &Owner::m0, &Owner::m1, 2, 0);
