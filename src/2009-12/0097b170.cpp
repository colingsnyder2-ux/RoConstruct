// from server: 100% by nuck16
// roc 2009-12 0097b170  unit: seg_00970000  size: 57 bytes
//
// 0097b170  56                   push esi
// 0097b171  33f6                 xor esi, esi
// 0097b173  56                   push esi
// 0097b174  6a0f                 push 0xf
// 0097b176  33c9                 xor ecx, ecx
// 0097b178  51                   push ecx
// 0097b179  b820cc7500           mov eax, 0x75cc20
// 0097b17e  50                   push eax
// 0097b17f  56                   push esi
// 0097b180  ba50bf7500           mov edx, 0x75bf50
// 0097b185  52                   push edx
// 0097b186  6884b09b00           push 0x9bb084
// 0097b18b  6898b29d00           push 0x9db298
// 0097b190  b95878b900           mov ecx, 0xb97858
// 0097b195  e87616deff           call 0x75c810
// 0097b19a  6880979800           push 0x989780
// 0097b19f  e88597e7ff           call 0x7f4929
// 0097b1a4  83c404               add esp, 4
// 0097b1a7  5e                   pop esi
// 0097b1a8  c3                   ret 

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

static Desc desc("Humanoid", "Data", &Owner::m0, &Owner::m1, 15, 0);
