// from server: 100% by nuck16
// roc 2009-12 0097b3c0  unit: seg_00970000  size: 57 bytes
//
// 0097b3c0  56                   push esi
// 0097b3c1  33f6                 xor esi, esi
// 0097b3c3  56                   push esi
// 0097b3c4  6a0f                 push 0xf
// 0097b3c6  33c9                 xor ecx, ecx
// 0097b3c8  51                   push ecx
// 0097b3c9  b890fd7500           mov eax, 0x75fd90
// 0097b3ce  50                   push eax
// 0097b3cf  56                   push esi
// 0097b3d0  ba50bf7500           mov edx, 0x75bf50
// 0097b3d5  52                   push edx
// 0097b3d6  6884b09b00           push 0x9bb084
// 0097b3db  6890229e00           push 0x9e2290
// 0097b3e0  b98c7ab900           mov ecx, 0xb97a8c
// 0097b3e5  e82647deff           call 0x75fb10
// 0097b3ea  68c0989800           push 0x9898c0
// 0097b3ef  e83595e7ff           call 0x7f4929
// 0097b3f4  83c404               add esp, 4
// 0097b3f7  5e                   pop esi
// 0097b3f8  c3                   ret 

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

static Desc desc("Adornee", "Data", &Owner::m0, &Owner::m1, 15, 0);
