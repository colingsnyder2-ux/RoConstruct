// from server: 100% by nuck16
// roc 2009-12 0096d2a0  unit: seg_00960000  size: 57 bytes
//
// 0096d2a0  56                   push esi
// 0096d2a1  33f6                 xor esi, esi
// 0096d2a3  56                   push esi
// 0096d2a4  6a0f                 push 0xf
// 0096d2a6  33c9                 xor ecx, ecx
// 0096d2a8  51                   push ecx
// 0096d2a9  b8309c5200           mov eax, 0x529c30
// 0096d2ae  50                   push eax
// 0096d2af  56                   push esi
// 0096d2b0  baa08a5200           mov edx, 0x528aa0
// 0096d2b5  52                   push edx
// 0096d2b6  6864c69b00           push 0x9bc664
// 0096d2bb  6870c69b00           push 0x9bc670
// 0096d2c0  b990ffb700           mov ecx, 0xb7ff90
// 0096d2c5  e8f6c2bbff           call 0x5295c0
// 0096d2ca  6830019800           push 0x980130
// 0096d2cf  e85576e8ff           call 0x7f4929
// 0096d2d4  83c404               add esp, 4
// 0096d2d7  5e                   pop esi
// 0096d2d8  c3                   ret 

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

static Desc desc("MtuOverride", "Replication", &Owner::m0, &Owner::m1, 15, 0);
