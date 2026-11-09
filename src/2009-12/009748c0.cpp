// from server: 100% by nuck16
// roc 2009-12 009748c0  unit: seg_00970000  size: 57 bytes
//
// 009748c0  56                   push esi
// 009748c1  33f6                 xor esi, esi
// 009748c3  56                   push esi
// 009748c4  6a0f                 push 0xf
// 009748c6  33c9                 xor ecx, ecx
// 009748c8  51                   push ecx
// 009748c9  b850606c00           mov eax, 0x6c6050
// 009748ce  50                   push eax
// 009748cf  56                   push esi
// 009748d0  ba705c6c00           mov edx, 0x6c5c70
// 009748d5  52                   push edx
// 009748d6  6810719d00           push 0x9d7110
// 009748db  6844719d00           push 0x9d7144
// 009748e0  b97823b900           mov ecx, 0xb92378
// 009748e5  e8b615d5ff           call 0x6c5ea0
// 009748ea  68005a9800           push 0x985a00
// 009748ef  e83500e8ff           call 0x7f4929
// 009748f4  83c404               add esp, 4
// 009748f7  5e                   pop esi
// 009748f8  c3                   ret 

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

static Desc desc("AreModelCoordsShown", "Display", &Owner::m0, &Owner::m1, 15, 0);
