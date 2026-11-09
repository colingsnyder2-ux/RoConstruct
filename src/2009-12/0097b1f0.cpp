// from server: 100% by nuck16
// roc 2009-12 0097b1f0  unit: seg_00970000  size: 57 bytes
//
// 0097b1f0  56                   push esi
// 0097b1f1  33f6                 xor esi, esi
// 0097b1f3  56                   push esi
// 0097b1f4  6a0f                 push 0xf
// 0097b1f6  33c9                 xor ecx, ecx
// 0097b1f8  51                   push ecx
// 0097b1f9  b820ce7500           mov eax, 0x75ce20
// 0097b1fe  50                   push eax
// 0097b1ff  56                   push esi
// 0097b200  ba00bd7500           mov edx, 0x75bd00
// 0097b205  52                   push edx
// 0097b206  6884b09b00           push 0x9bb084
// 0097b20b  68146d9e00           push 0x9e6d14
// 0097b210  b90c78b900           mov ecx, 0xb9780c
// 0097b215  e8d618deff           call 0x75caf0
// 0097b21a  68c0979800           push 0x9897c0
// 0097b21f  e80597e7ff           call 0x7f4929
// 0097b224  83c404               add esp, 4
// 0097b227  5e                   pop esi
// 0097b228  c3                   ret 

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

static Desc desc("Point", "Data", &Owner::m0, &Owner::m1, 15, 0);
