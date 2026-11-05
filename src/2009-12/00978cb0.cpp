// from server: 100% by nuck16
// roc 2009-12 00978cb0  unit: seg_00970000  size: 57 bytes
//
// 00978cb0  56                   push esi
// 00978cb1  33f6                 xor esi, esi
// 00978cb3  56                   push esi
// 00978cb4  6a0f                 push 0xf
// 00978cb6  33c9                 xor ecx, ecx
// 00978cb8  51                   push ecx
// 00978cb9  b830e17100           mov eax, 0x71e130
// 00978cbe  50                   push eax
// 00978cbf  56                   push esi
// 00978cc0  ba80725700           mov edx, 0x577280
// 00978cc5  52                   push edx
// 00978cc6  6884b09b00           push 0x9bb084
// 00978ccb  6844869a00           push 0x9a8644
// 00978cd0  b9005bb900           mov ecx, 0xb95b00
// 00978cd5  e8c650daff           call 0x71dda0
// 00978cda  6820809800           push 0x988020
// 00978cdf  e845bce7ff           call 0x7f4929
// 00978ce4  83c404               add esp, 4
// 00978ce7  5e                   pop esi
// 00978ce8  c3                   ret 

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

static Desc desc("Scale", "Data", &Owner::m0, &Owner::m1, 15, 0);
