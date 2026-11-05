// from server: 100% by nuck16
// roc 2009-12 009786c0  unit: seg_00970000  size: 57 bytes
//
// 009786c0  56                   push esi
// 009786c1  33f6                 xor esi, esi
// 009786c3  56                   push esi
// 009786c4  6a0f                 push 0xf
// 009786c6  33c9                 xor ecx, ecx
// 009786c8  51                   push ecx
// 009786c9  b8006c7100           mov eax, 0x716c00
// 009786ce  50                   push eax
// 009786cf  56                   push esi
// 009786d0  baa0577100           mov edx, 0x7157a0
// 009786d5  52                   push edx
// 009786d6  6884b09b00           push 0x9bb084
// 009786db  68d8f49d00           push 0x9df4d8
// 009786e0  b9dc56b900           mov ecx, 0xb956dc
// 009786e5  e8c6ddd9ff           call 0x7164b0
// 009786ea  68d07c9800           push 0x987cd0
// 009786ef  e835c2e7ff           call 0x7f4929
// 009786f4  83c404               add esp, 4
// 009786f7  5e                   pop esi
// 009786f8  c3                   ret 

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

static Desc desc("C0", "Data", &Owner::m0, &Owner::m1, 15, 0);
