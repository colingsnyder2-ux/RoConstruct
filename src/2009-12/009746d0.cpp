// from server: 100% by nuck16
// roc 2009-12 009746d0  unit: seg_00970000  size: 57 bytes
//
// 009746d0  56                   push esi
// 009746d1  33f6                 xor esi, esi
// 009746d3  56                   push esi
// 009746d4  6a0f                 push 0xf
// 009746d6  33c9                 xor ecx, ecx
// 009746d8  51                   push ecx
// 009746d9  b8d0bb6b00           mov eax, 0x6bbbd0
// 009746de  50                   push eax
// 009746df  56                   push esi
// 009746e0  ba00b06b00           mov edx, 0x6bb000
// 009746e5  52                   push edx
// 009746e6  68dc1f9d00           push 0x9d1fdc
// 009746eb  68cc699d00           push 0x9d69cc
// 009746f0  b94021b900           mov ecx, 0xb92140
// 009746f5  e8b672d4ff           call 0x6bb9b0
// 009746fa  68f0589800           push 0x9858f0
// 009746ff  e82502e8ff           call 0x7f4929
// 00974704  83c404               add esp, 4
// 00974707  5e                   pop esi
// 00974708  c3                   ret 

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

static Desc desc("StudsPerTileU", "Appearance", &Owner::m0, &Owner::m1, 15, 0);
