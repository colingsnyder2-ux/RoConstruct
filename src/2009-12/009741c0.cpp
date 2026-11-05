// from server: 100% by nuck16
// roc 2009-12 009741c0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009741c0
//
// 009741c0  33c9                 xor ecx, ecx
// 009741c2  51                   push ecx
// 009741c3  6a0f                 push 0xf
// 009741c5  51                   push ecx
// 009741c6  b8b0996b00           mov eax, 0x6b99b0
// 009741cb  50                   push eax
// 009741cc  68c4000000           push 0xc4
// 009741d1  6884b09b00           push 0x9bb084
// 009741d6  6808669d00           push 0x9d6608
// 009741db  b9a81bb900           mov ecx, 0xb91ba8
// 009741e0  e8bb22d4ff           call 0x6b64a0
// 009741e5  68b0569800           push 0x9856b0
// 009741ea  e83a07e8ff           call 0x7f4929
// 009741ef  59                   pop ecx
// 009741f0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

struct Desc
{
    Desc(const char *, const char *, int, void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("DistanceFactor", "Data", 196, &Owner::m0, 15, 0);
