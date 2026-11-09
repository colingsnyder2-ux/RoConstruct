// from server: 100% by nuck16
// roc 2009-12 00973670  unit: seg_00970000  size: 57 bytes
//
// 00973670  56                   push esi
// 00973671  33f6                 xor esi, esi
// 00973673  56                   push esi
// 00973674  6a0f                 push 0xf
// 00973676  33c9                 xor ecx, ecx
// 00973678  51                   push ecx
// 00973679  b870076900           mov eax, 0x690770
// 0097367e  50                   push eax
// 0097367f  56                   push esi
// 00973680  baa0e16800           mov edx, 0x68e1a0
// 00973685  52                   push edx
// 00973686  6884b09b00           push 0x9bb084
// 0097368b  68141b9d00           push 0x9d1b14
// 00973690  b95411b900           mov ecx, 0xb91154
// 00973695  e886c0d1ff           call 0x68f720
// 0097369a  68e04f9800           push 0x984fe0
// 0097369f  e88512e8ff           call 0x7f4929
// 009736a4  83c404               add esp, 4
// 009736a7  5e                   pop esi
// 009736a8  c3                   ret 

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

static Desc desc("TextureId", "Data", &Owner::m0, &Owner::m1, 15, 0);
