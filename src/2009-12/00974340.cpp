// from server: 100% by nuck16
// roc 2009-12 00974340  unit: seg_00970000  size: 57 bytes
//
// 00974340  56                   push esi
// 00974341  33f6                 xor esi, esi
// 00974343  56                   push esi
// 00974344  6a06                 push 6
// 00974346  33c9                 xor ecx, ecx
// 00974348  51                   push ecx
// 00974349  b8b0af6b00           mov eax, 0x6bafb0
// 0097434e  50                   push eax
// 0097434f  56                   push esi
// 00974350  bab0356b00           mov edx, 0x6b35b0
// 00974355  52                   push edx
// 00974356  6884b09b00           push 0x9bb084
// 0097435b  6850669d00           push 0x9d6650
// 00974360  b9881ab900           mov ecx, 0xb91a88
// 00974365  e88627d4ff           call 0x6b6af0
// 0097436a  6870579800           push 0x985770
// 0097436f  e8b505e8ff           call 0x7f4929
// 00974374  83c404               add esp, 4
// 00974377  5e                   pop esi
// 00974378  c3                   ret 

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

static Desc desc("PlayCount", "Data", &Owner::m0, &Owner::m1, 6, 0);
