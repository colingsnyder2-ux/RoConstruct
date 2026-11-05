// from server: 100% by nuck16
// roc 2009-12 00975dc0  unit: seg_00970000  size: 57 bytes
//
// 00975dc0  56                   push esi
// 00975dc1  33f6                 xor esi, esi
// 00975dc3  56                   push esi
// 00975dc4  6a0f                 push 0xf
// 00975dc6  33c9                 xor ecx, ecx
// 00975dc8  51                   push ecx
// 00975dc9  b8802d6e00           mov eax, 0x6e2d80
// 00975dce  50                   push eax
// 00975dcf  56                   push esi
// 00975dd0  baf0ff4b00           mov edx, 0x4bfff0
// 00975dd5  52                   push edx
// 00975dd6  6884b09b00           push 0x9bb084
// 00975ddb  6840e09b00           push 0x9be040
// 00975de0  b93435b900           mov ecx, 0xb93534
// 00975de5  e866cdd6ff           call 0x6e2b50
// 00975dea  68f0649800           push 0x9864f0
// 00975def  e835ebe7ff           call 0x7f4929
// 00975df4  83c404               add esp, 4
// 00975df7  5e                   pop esi
// 00975df8  c3                   ret 

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

static Desc desc("Size", "Data", &Owner::m0, &Owner::m1, 15, 0);
