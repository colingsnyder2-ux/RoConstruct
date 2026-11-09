// from server: 100% by nuck16
// roc 2009-12 009749c0  unit: seg_00970000  size: 57 bytes
//
// 009749c0  56                   push esi
// 009749c1  33f6                 xor esi, esi
// 009749c3  56                   push esi
// 009749c4  6a0f                 push 0xf
// 009749c6  33c9                 xor ecx, ecx
// 009749c8  51                   push ecx
// 009749c9  b810616c00           mov eax, 0x6c6110
// 009749ce  50                   push eax
// 009749cf  56                   push esi
// 009749d0  bab05c6c00           mov edx, 0x6c5cb0
// 009749d5  52                   push edx
// 009749d6  6810719d00           push 0x9d7110
// 009749db  688c719d00           push 0x9d718c
// 009749e0  b9e822b900           mov ecx, 0xb922e8
// 009749e5  e8b614d5ff           call 0x6c5ea0
// 009749ea  68805a9800           push 0x985a80
// 009749ef  e835ffe7ff           call 0x7f4929
// 009749f4  83c404               add esp, 4
// 009749f7  5e                   pop esi
// 009749f8  c3                   ret 

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

static Desc desc("AreAwakePartsHighlighted", "Display", &Owner::m0, &Owner::m1, 15, 0);
