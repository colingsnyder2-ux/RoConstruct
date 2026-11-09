// from server: 100% by nuck16
// roc 2009-12 00977b10  unit: seg_00970000  size: 57 bytes
//
// 00977b10  56                   push esi
// 00977b11  33f6                 xor esi, esi
// 00977b13  56                   push esi
// 00977b14  6a02                 push 2
// 00977b16  33c9                 xor ecx, ecx
// 00977b18  51                   push ecx
// 00977b19  b800956f00           mov eax, 0x6f9500
// 00977b1e  50                   push eax
// 00977b1f  56                   push esi
// 00977b20  ba30526f00           mov edx, 0x6f5230
// 00977b25  52                   push edx
// 00977b26  6884b09b00           push 0x9bb084
// 00977b2b  68f4cd9d00           push 0x9dcdf4
// 00977b30  b9a848b900           mov ecx, 0xb948a8
// 00977b35  e8d606d8ff           call 0x6f8210
// 00977b3a  6800729800           push 0x987200
// 00977b3f  e8e5cde7ff           call 0x7f4929
// 00977b44  83c404               add esp, 4
// 00977b47  5e                   pop esi
// 00977b48  c3                   ret 

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

static Desc desc("MouseTarget", "Data", &Owner::m0, &Owner::m1, 2, 0);
