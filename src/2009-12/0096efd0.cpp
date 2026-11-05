// from server: 100% by nuck16
// roc 2009-12 0096efd0  unit: seg_00960000  size: 57 bytes
//
// 0096efd0  56                   push esi
// 0096efd1  33f6                 xor esi, esi
// 0096efd3  56                   push esi
// 0096efd4  6a0f                 push 0xf
// 0096efd6  33c9                 xor ecx, ecx
// 0096efd8  51                   push ecx
// 0096efd9  b850d96300           mov eax, 0x63d950
// 0096efde  50                   push eax
// 0096efdf  56                   push esi
// 0096efe0  ba90d26300           mov edx, 0x63d290
// 0096efe5  52                   push edx
// 0096efe6  6884b09b00           push 0x9bb084
// 0096efeb  68ccb09b00           push 0x9bb0cc
// 0096eff0  b9385bb800           mov ecx, 0xb85b38
// 0096eff5  e8d6e5ccff           call 0x63d5d0
// 0096effa  68001d9800           push 0x981d00
// 0096efff  e82559e8ff           call 0x7f4929
// 0096f004  83c404               add esp, 4
// 0096f007  5e                   pop esi
// 0096f008  c3                   ret 

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

static Desc desc("TeamColor", "Data", &Owner::m0, &Owner::m1, 15, 0);
