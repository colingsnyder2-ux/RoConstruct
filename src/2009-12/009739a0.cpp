// from server: 100% by nuck16
// roc 2009-12 009739a0  unit: seg_00970000  size: 57 bytes
//
// 009739a0  56                   push esi
// 009739a1  33f6                 xor esi, esi
// 009739a3  56                   push esi
// 009739a4  6a09                 push 9
// 009739a6  33c9                 xor ecx, ecx
// 009739a8  51                   push ecx
// 009739a9  b8e0446900           mov eax, 0x6944e0
// 009739ae  50                   push eax
// 009739af  56                   push esi
// 009739b0  baa0246900           mov edx, 0x6924a0
// 009739b5  52                   push edx
// 009739b6  68dc1f9d00           push 0x9d1fdc
// 009739bb  6804209d00           push 0x9d2004
// 009739c0  b90013b900           mov ecx, 0xb91300
// 009739c5  e8a6fed1ff           call 0x693870
// 009739ca  6840519800           push 0x985140
// 009739cf  e8550fe8ff           call 0x7f4929
// 009739d4  83c404               add esp, 4
// 009739d7  5e                   pop esi
// 009739d8  c3                   ret 

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

static Desc desc("GripRight", "Appearance", &Owner::m0, &Owner::m1, 9, 0);
