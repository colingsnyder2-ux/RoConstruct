// from server: 100% by nuck16
// roc 2009-12 0097a180  unit: seg_00970000  size: 57 bytes
//
// 0097a180  56                   push esi
// 0097a181  33f6                 xor esi, esi
// 0097a183  56                   push esi
// 0097a184  6a0f                 push 0xf
// 0097a186  33c9                 xor ecx, ecx
// 0097a188  51                   push ecx
// 0097a189  b860377400           mov eax, 0x743760
// 0097a18e  50                   push eax
// 0097a18f  56                   push esi
// 0097a190  ba50b04400           mov edx, 0x44b050
// 0097a195  52                   push edx
// 0097a196  6884b09b00           push 0x9bb084
// 0097a19b  68cc2d9e00           push 0x9e2dcc
// 0097a1a0  b91c6db900           mov ecx, 0xb96d1c
// 0097a1a5  e8c698dcff           call 0x743a70
// 0097a1aa  68108e9800           push 0x988e10
// 0097a1af  e875a7e7ff           call 0x7f4929
// 0097a1b4  83c404               add esp, 4
// 0097a1b7  5e                   pop esi
// 0097a1b8  c3                   ret 

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

static Desc desc("TopBottom", "Data", &Owner::m0, &Owner::m1, 15, 0);
