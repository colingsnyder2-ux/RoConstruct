// from server: 100% by nuck16
// roc 2009-12 00974710  unit: seg_00970000  size: 57 bytes
//
// 00974710  56                   push esi
// 00974711  33f6                 xor esi, esi
// 00974713  56                   push esi
// 00974714  6a0f                 push 0xf
// 00974716  33c9                 xor ecx, ecx
// 00974718  51                   push ecx
// 00974719  b810bc6b00           mov eax, 0x6bbc10
// 0097471e  50                   push eax
// 0097471f  56                   push esi
// 00974720  ba10b06b00           mov edx, 0x6bb010
// 00974725  52                   push edx
// 00974726  68dc1f9d00           push 0x9d1fdc
// 0097472b  68dc699d00           push 0x9d69dc
// 00974730  b91c21b900           mov ecx, 0xb9211c
// 00974735  e87672d4ff           call 0x6bb9b0
// 0097473a  68d0589800           push 0x9858d0
// 0097473f  e8e501e8ff           call 0x7f4929
// 00974744  83c404               add esp, 4
// 00974747  5e                   pop esi
// 00974748  c3                   ret 

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

static Desc desc("StudsPerTileV", "Appearance", &Owner::m0, &Owner::m1, 15, 0);
