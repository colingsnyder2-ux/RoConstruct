// from server: 100% by nuck16
// roc 2009-12 00974650  unit: seg_00970000  size: 57 bytes
//
// 00974650  56                   push esi
// 00974651  33f6                 xor esi, esi
// 00974653  56                   push esi
// 00974654  6a0f                 push 0xf
// 00974656  33c9                 xor ecx, ecx
// 00974658  51                   push ecx
// 00974659  b850bb6b00           mov eax, 0x6bbb50
// 0097465e  50                   push eax
// 0097465f  56                   push esi
// 00974660  ba90294b00           mov edx, 0x4b2990
// 00974665  52                   push edx
// 00974666  68dc1f9d00           push 0x9d1fdc
// 0097466b  68b8699d00           push 0x9d69b8
// 00974670  b9bc20b900           mov ecx, 0xb920bc
// 00974675  e88672d4ff           call 0x6bb900
// 0097467a  6830599800           push 0x985930
// 0097467f  e8a502e8ff           call 0x7f4929
// 00974684  83c404               add esp, 4
// 00974687  5e                   pop esi
// 00974688  c3                   ret 

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

static Desc desc("Specular", "Appearance", &Owner::m0, &Owner::m1, 15, 0);
