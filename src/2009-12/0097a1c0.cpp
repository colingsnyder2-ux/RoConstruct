// from server: 100% by nuck16
// roc 2009-12 0097a1c0  unit: seg_00970000  size: 57 bytes
//
// 0097a1c0  56                   push esi
// 0097a1c1  33f6                 xor esi, esi
// 0097a1c3  56                   push esi
// 0097a1c4  6a0f                 push 0xf
// 0097a1c6  33c9                 xor ecx, ecx
// 0097a1c8  51                   push ecx
// 0097a1c9  b890377400           mov eax, 0x743790
// 0097a1ce  50                   push eax
// 0097a1cf  56                   push esi
// 0097a1d0  ba101b7400           mov edx, 0x741b10
// 0097a1d5  52                   push edx
// 0097a1d6  6884b09b00           push 0x9bb084
// 0097a1db  68d82d9e00           push 0x9e2dd8
// 0097a1e0  b9f46cb900           mov ecx, 0xb96cf4
// 0097a1e5  e86699dcff           call 0x743b50
// 0097a1ea  68f08d9800           push 0x988df0
// 0097a1ef  e835a7e7ff           call 0x7f4929
// 0097a1f4  83c404               add esp, 4
// 0097a1f7  5e                   pop esi
// 0097a1f8  c3                   ret 

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

static Desc desc("LeftRight", "Data", &Owner::m0, &Owner::m1, 15, 0);
