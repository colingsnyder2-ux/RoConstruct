// from server: 100% by nuck16
// roc 2009-12 009739e0  unit: seg_00970000  size: 57 bytes
//
// 009739e0  56                   push esi
// 009739e1  33f6                 xor esi, esi
// 009739e3  56                   push esi
// 009739e4  6a02                 push 2
// 009739e6  33c9                 xor ecx, ecx
// 009739e8  51                   push ecx
// 009739e9  b8204d6900           mov eax, 0x694d20
// 009739ee  50                   push eax
// 009739ef  56                   push esi
// 009739f0  bac0216900           mov edx, 0x6921c0
// 009739f5  52                   push edx
// 009739f6  68dc1f9d00           push 0x9d1fdc
// 009739fb  68d81b9d00           push 0x9d1bd8
// 00973a00  b9b813b900           mov ecx, 0xb913b8
// 00973a05  e816ffd1ff           call 0x693920
// 00973a0a  68e0519800           push 0x9851e0
// 00973a0f  e8150fe8ff           call 0x7f4929
// 00973a14  83c404               add esp, 4
// 00973a17  5e                   pop esi
// 00973a18  c3                   ret 

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

static Desc desc("BackendToolState", "Appearance", &Owner::m0, &Owner::m1, 2, 0);
