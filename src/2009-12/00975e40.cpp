// from server: 100% by nuck16
// roc 2009-12 00975e40  unit: seg_00970000  size: 57 bytes
//
// 00975e40  56                   push esi
// 00975e41  33f6                 xor esi, esi
// 00975e43  56                   push esi
// 00975e44  6a0f                 push 0xf
// 00975e46  33c9                 xor ecx, ecx
// 00975e48  51                   push ecx
// 00975e49  b8202e6e00           mov eax, 0x6e2e20
// 00975e4e  50                   push eax
// 00975e4f  56                   push esi
// 00975e50  ba10004c00           mov edx, 0x4c0010
// 00975e55  52                   push edx
// 00975e56  6884b09b00           push 0x9bb084
// 00975e5b  68ccaa9d00           push 0x9daacc
// 00975e60  b98035b900           mov ecx, 0xb93580
// 00975e65  e8e6ccd6ff           call 0x6e2b50
// 00975e6a  68d0649800           push 0x9864d0
// 00975e6f  e8b5eae7ff           call 0x7f4929
// 00975e74  83c404               add esp, 4
// 00975e77  5e                   pop esi
// 00975e78  c3                   ret 

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

static Desc desc("RiseVelocity", "Data", &Owner::m0, &Owner::m1, 15, 0);
