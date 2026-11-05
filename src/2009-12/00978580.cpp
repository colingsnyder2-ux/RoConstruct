// from server: 100% by nuck16
// roc 2009-12 00978580  unit: seg_00970000  size: 57 bytes
//
// 00978580  56                   push esi
// 00978581  33f6                 xor esi, esi
// 00978583  56                   push esi
// 00978584  6a0f                 push 0xf
// 00978586  33c9                 xor ecx, ecx
// 00978588  51                   push ecx
// 00978589  b8f04e7100           mov eax, 0x714ef0
// 0097858e  50                   push eax
// 0097858f  56                   push esi
// 00978590  ba704d5700           mov edx, 0x574d70
// 00978595  52                   push edx
// 00978596  68dc1f9d00           push 0x9d1fdc
// 0097859b  68b4e79d00           push 0x9de7b4
// 009785a0  b90854b900           mov ecx, 0xb95408
// 009785a5  e866bfd9ff           call 0x714510
// 009785aa  68007a9800           push 0x987a00
// 009785af  e875c3e7ff           call 0x7f4929
// 009785b4  83c404               add esp, 4
// 009785b7  5e                   pop esi
// 009785b8  c3                   ret 

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

static Desc desc("ColorShift_Top", "Appearance", &Owner::m0, &Owner::m1, 15, 0);
