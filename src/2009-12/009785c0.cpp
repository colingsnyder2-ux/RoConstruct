// from server: 100% by nuck16
// roc 2009-12 009785c0  unit: seg_00970000  size: 57 bytes
//
// 009785c0  56                   push esi
// 009785c1  33f6                 xor esi, esi
// 009785c3  56                   push esi
// 009785c4  6a0f                 push 0xf
// 009785c6  33c9                 xor ecx, ecx
// 009785c8  51                   push ecx
// 009785c9  b8804f7100           mov eax, 0x714f80
// 009785ce  50                   push eax
// 009785cf  56                   push esi
// 009785d0  baa04d5700           mov edx, 0x574da0
// 009785d5  52                   push edx
// 009785d6  68dc1f9d00           push 0x9d1fdc
// 009785db  68c4e79d00           push 0x9de7c4
// 009785e0  b9b054b900           mov ecx, 0xb954b0
// 009785e5  e826bfd9ff           call 0x714510
// 009785ea  68207a9800           push 0x987a20
// 009785ef  e835c3e7ff           call 0x7f4929
// 009785f4  83c404               add esp, 4
// 009785f7  5e                   pop esi
// 009785f8  c3                   ret 

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

static Desc desc("ColorShift_Bottom", "Appearance", &Owner::m0, &Owner::m1, 15, 0);
