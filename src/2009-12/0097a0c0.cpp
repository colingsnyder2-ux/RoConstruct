// from server: 100% by nuck16
// roc 2009-12 0097a0c0  unit: seg_00970000  size: 57 bytes
//
// 0097a0c0  56                   push esi
// 0097a0c1  33f6                 xor esi, esi
// 0097a0c3  56                   push esi
// 0097a0c4  6a0f                 push 0xf
// 0097a0c6  33c9                 xor ecx, ecx
// 0097a0c8  51                   push ecx
// 0097a0c9  b830387400           mov eax, 0x743830
// 0097a0ce  50                   push eax
// 0097a0cf  56                   push esi
// 0097a0d0  ba30597100           mov edx, 0x715930
// 0097a0d5  52                   push edx
// 0097a0d6  6884b09b00           push 0x9bb084
// 0097a0db  6808f59d00           push 0x9df508
// 0097a0e0  b9006eb900           mov ecx, 0xb96e00
// 0097a0e5  e87692dcff           call 0x743360
// 0097a0ea  68508e9800           push 0x988e50
// 0097a0ef  e835a8e7ff           call 0x7f4929
// 0097a0f4  83c404               add esp, 4
// 0097a0f7  5e                   pop esi
// 0097a0f8  c3                   ret 

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

static Desc desc("DesiredAngle", "Data", &Owner::m0, &Owner::m1, 15, 0);
