// from server: 100% by nuck16
// roc 2009-12 00977b50  unit: seg_00970000  size: 57 bytes
//
// 00977b50  56                   push esi
// 00977b51  33f6                 xor esi, esi
// 00977b53  56                   push esi
// 00977b54  6a02                 push 2
// 00977b56  33c9                 xor ecx, ecx
// 00977b58  51                   push ecx
// 00977b59  b800966f00           mov eax, 0x6f9600
// 00977b5e  50                   push eax
// 00977b5f  56                   push esi
// 00977b60  ba70486f00           mov edx, 0x6f4870
// 00977b65  52                   push edx
// 00977b66  6884b09b00           push 0x9bb084
// 00977b6b  6800ce9d00           push 0x9dce00
// 00977b70  b9784bb900           mov ecx, 0xb94b78
// 00977b75  e8c61ed8ff           call 0x6f9a40
// 00977b7a  68e0719800           push 0x9871e0
// 00977b7f  e8a5cde7ff           call 0x7f4929
// 00977b84  83c404               add esp, 4
// 00977b87  5e                   pop esi
// 00977b88  c3                   ret 

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

static Desc desc("MouseTargetSurface", "Data", &Owner::m0, &Owner::m1, 2, 0);
