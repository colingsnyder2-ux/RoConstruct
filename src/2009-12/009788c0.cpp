// from server: 100% by nuck16
// roc 2009-12 009788c0  unit: seg_00970000  size: 57 bytes
//
// 009788c0  56                   push esi
// 009788c1  33f6                 xor esi, esi
// 009788c3  56                   push esi
// 009788c4  6a0f                 push 0xf
// 009788c6  33c9                 xor ecx, ecx
// 009788c8  51                   push ecx
// 009788c9  b8a06d7100           mov eax, 0x716da0
// 009788ce  50                   push eax
// 009788cf  56                   push esi
// 009788d0  ba30597100           mov edx, 0x715930
// 009788d5  52                   push edx
// 009788d6  6884b09b00           push 0x9bb084
// 009788db  6808f59d00           push 0x9df508
// 009788e0  b9fc56b900           mov ecx, 0xb956fc
// 009788e5  e846ded9ff           call 0x716730
// 009788ea  68307d9800           push 0x987d30
// 009788ef  e835c0e7ff           call 0x7f4929
// 009788f4  83c404               add esp, 4
// 009788f7  5e                   pop esi
// 009788f8  c3                   ret 

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

static Desc desc("DesiredAngle", "Data", &Owner::m0, &Owner::m1, 15, 0);
