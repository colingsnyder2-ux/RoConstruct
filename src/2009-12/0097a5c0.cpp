// from server: 100% by nuck16
// roc 2009-12 0097a5c0  unit: seg_00970000  size: 57 bytes
//
// 0097a5c0  56                   push esi
// 0097a5c1  33f6                 xor esi, esi
// 0097a5c3  56                   push esi
// 0097a5c4  6a0f                 push 0xf
// 0097a5c6  33c9                 xor ecx, ecx
// 0097a5c8  51                   push ecx
// 0097a5c9  b830cc7400           mov eax, 0x74cc30
// 0097a5ce  50                   push eax
// 0097a5cf  56                   push esi
// 0097a5d0  bac0417400           mov edx, 0x7441c0
// 0097a5d5  52                   push edx
// 0097a5d6  6884b09b00           push 0x9bb084
// 0097a5db  6830ca9c00           push 0x9cca30
// 0097a5e0  b95c72b900           mov ecx, 0xb9725c
// 0097a5e5  e8b626ddff           call 0x74cca0
// 0097a5ea  68b0919800           push 0x9891b0
// 0097a5ef  e835a3e7ff           call 0x7f4929
// 0097a5f4  83c404               add esp, 4
// 0097a5f7  5e                   pop esi
// 0097a5f8  c3                   ret 

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

static Desc desc("Axes", "Data", &Owner::m0, &Owner::m1, 15, 0);
