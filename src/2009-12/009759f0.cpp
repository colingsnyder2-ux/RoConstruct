// from server: 100% by nuck16
// roc 2009-12 009759f0  unit: seg_00970000  size: 57 bytes
//
// 009759f0  56                   push esi
// 009759f1  33f6                 xor esi, esi
// 009759f3  56                   push esi
// 009759f4  6a02                 push 2
// 009759f6  33c9                 xor ecx, ecx
// 009759f8  51                   push ecx
// 009759f9  b820b66d00           mov eax, 0x6db620
// 009759fe  50                   push eax
// 009759ff  56                   push esi
// 00975a00  bac0a86d00           mov edx, 0x6da8c0
// 00975a05  52                   push edx
// 00975a06  6884b09b00           push 0x9bb084
// 00975a0b  6824799d00           push 0x9d7924
// 00975a10  b97c32b900           mov ecx, 0xb9327c
// 00975a15  e88652d6ff           call 0x6daca0
// 00975a1a  6850639800           push 0x986350
// 00975a1f  e805efe7ff           call 0x7f4929
// 00975a24  83c404               add esp, 4
// 00975a27  5e                   pop esi
// 00975a28  c3                   ret 

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

static Desc desc("CoordinateFrame", "Data", &Owner::m0, &Owner::m1, 2, 0);
