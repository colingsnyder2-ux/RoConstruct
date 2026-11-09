// from server: 100% by nuck16
// roc 2009-12 00975e00  unit: seg_00970000  size: 57 bytes
//
// 00975e00  56                   push esi
// 00975e01  33f6                 xor esi, esi
// 00975e03  56                   push esi
// 00975e04  6a0f                 push 0xf
// 00975e06  33c9                 xor ecx, ecx
// 00975e08  51                   push ecx
// 00975e09  b8d02d6e00           mov eax, 0x6e2dd0
// 00975e0e  50                   push eax
// 00975e0f  56                   push esi
// 00975e10  ba00004c00           mov edx, 0x4c0000
// 00975e15  52                   push edx
// 00975e16  6884b09b00           push 0x9bb084
// 00975e1b  68c4aa9d00           push 0x9daac4
// 00975e20  b95c35b900           mov ecx, 0xb9355c
// 00975e25  e826cdd6ff           call 0x6e2b50
// 00975e2a  68b0649800           push 0x9864b0
// 00975e2f  e8f5eae7ff           call 0x7f4929
// 00975e34  83c404               add esp, 4
// 00975e37  5e                   pop esi
// 00975e38  c3                   ret 

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

static Desc desc("Opacity", "Data", &Owner::m0, &Owner::m1, 15, 0);
