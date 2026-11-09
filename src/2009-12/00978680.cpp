// from server: 100% by nuck16
// roc 2009-12 00978680  unit: seg_00970000  size: 57 bytes
//
// 00978680  56                   push esi
// 00978681  33f6                 xor esi, esi
// 00978683  56                   push esi
// 00978684  6a0f                 push 0xf
// 00978686  33c9                 xor ecx, ecx
// 00978688  51                   push ecx
// 00978689  b8e06b7100           mov eax, 0x716be0
// 0097868e  50                   push eax
// 0097868f  56                   push esi
// 00978690  ba405f7100           mov edx, 0x715f40
// 00978695  52                   push edx
// 00978696  6884b09b00           push 0x9bb084
// 0097869b  68d0f49d00           push 0x9df4d0
// 009786a0  b99056b900           mov ecx, 0xb95690
// 009786a5  e856ddd9ff           call 0x716400
// 009786aa  68107c9800           push 0x987c10
// 009786af  e875c2e7ff           call 0x7f4929
// 009786b4  83c404               add esp, 4
// 009786b7  5e                   pop esi
// 009786b8  c3                   ret 

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

static Desc desc("Part1", "Data", &Owner::m0, &Owner::m1, 15, 0);
