// from server: 100% by nuck16
// roc 2009-12 00974880  unit: seg_00970000  size: 57 bytes
//
// 00974880  56                   push esi
// 00974881  33f6                 xor esi, esi
// 00974883  56                   push esi
// 00974884  6a0f                 push 0xf
// 00974886  33c9                 xor ecx, ecx
// 00974888  51                   push ecx
// 00974889  b820606c00           mov eax, 0x6c6020
// 0097488e  50                   push eax
// 0097488f  56                   push esi
// 00974890  ba605c6c00           mov edx, 0x6c5c60
// 00974895  52                   push edx
// 00974896  6810719d00           push 0x9d7110
// 0097489b  682c719d00           push 0x9d712c
// 009748a0  b9dc23b900           mov ecx, 0xb923dc
// 009748a5  e8f615d5ff           call 0x6c5ea0
// 009748aa  68e0599800           push 0x9859e0
// 009748af  e87500e8ff           call 0x7f4929
// 009748b4  83c404               add esp, 4
// 009748b7  5e                   pop esi
// 009748b8  c3                   ret 

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

static Desc desc("AreUnalignedPartsShown", "Display", &Owner::m0, &Owner::m1, 15, 0);
