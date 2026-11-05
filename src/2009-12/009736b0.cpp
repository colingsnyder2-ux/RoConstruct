// from server: 100% by nuck16
// roc 2009-12 009736b0  unit: seg_00970000  size: 57 bytes
//
// 009736b0  56                   push esi
// 009736b1  33f6                 xor esi, esi
// 009736b3  56                   push esi
// 009736b4  6a0f                 push 0xf
// 009736b6  33c9                 xor ecx, ecx
// 009736b8  51                   push ecx
// 009736b9  b8a0166900           mov eax, 0x6916a0
// 009736be  50                   push eax
// 009736bf  56                   push esi
// 009736c0  ba30e16800           mov edx, 0x68e130
// 009736c5  52                   push edx
// 009736c6  6884b09b00           push 0x9bb084
// 009736cb  6844179d00           push 0x9d1744
// 009736d0  b99811b900           mov ecx, 0xb91198
// 009736d5  e816d4d1ff           call 0x690af0
// 009736da  68804f9800           push 0x984f80
// 009736df  e84512e8ff           call 0x7f4929
// 009736e4  83c404               add esp, 4
// 009736e7  5e                   pop esi
// 009736e8  c3                   ret 

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

static Desc desc("BinType", "Data", &Owner::m0, &Owner::m1, 15, 0);
