// from server: 100% by nuck16
// roc 2009-12 00976cd0  unit: seg_00970000  size: 57 bytes
//
// 00976cd0  56                   push esi
// 00976cd1  33f6                 xor esi, esi
// 00976cd3  56                   push esi
// 00976cd4  6a0f                 push 0xf
// 00976cd6  33c9                 xor ecx, ecx
// 00976cd8  51                   push ecx
// 00976cd9  b800146f00           mov eax, 0x6f1400
// 00976cde  50                   push eax
// 00976cdf  56                   push esi
// 00976ce0  ba20004c00           mov edx, 0x4c0020
// 00976ce5  52                   push edx
// 00976ce6  6884b09b00           push 0x9bb084
// 00976ceb  68ecb79d00           push 0x9db7ec
// 00976cf0  b9e841b900           mov ecx, 0xb941e8
// 00976cf5  e806a4d7ff           call 0x6f1100
// 00976cfa  68206c9800           push 0x986c20
// 00976cff  e825dce7ff           call 0x7f4929
// 00976d04  83c404               add esp, 4
// 00976d07  5e                   pop esi
// 00976d08  c3                   ret 

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

static Desc desc("SparkleColor", "Data", &Owner::m0, &Owner::m1, 15, 0);
