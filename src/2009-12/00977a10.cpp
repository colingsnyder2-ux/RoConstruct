// from server: 100% by nuck16
// roc 2009-12 00977a10  unit: seg_00970000  size: 57 bytes
//
// 00977a10  56                   push esi
// 00977a11  33f6                 xor esi, esi
// 00977a13  56                   push esi
// 00977a14  6a02                 push 2
// 00977a16  33c9                 xor ecx, ecx
// 00977a18  51                   push ecx
// 00977a19  b8c0476f00           mov eax, 0x6f47c0
// 00977a1e  50                   push eax
// 00977a1f  56                   push esi
// 00977a20  ba70f17500           mov edx, 0x75f170
// 00977a25  52                   push edx
// 00977a26  6884b09b00           push 0x9bb084
// 00977a2b  68c0cd9d00           push 0x9dcdc0
// 00977a30  b9584bb900           mov ecx, 0xb94b58
// 00977a35  e8c605d8ff           call 0x6f8000
// 00977a3a  68c0719800           push 0x9871c0
// 00977a3f  e8e5cee7ff           call 0x7f4929
// 00977a44  83c404               add esp, 4
// 00977a47  5e                   pop esi
// 00977a48  c3                   ret 

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

static Desc desc("WindowSize", "Data", &Owner::m0, &Owner::m1, 2, 0);
