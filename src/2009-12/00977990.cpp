// from server: 100% by nuck16
// roc 2009-12 00977990  unit: seg_00970000  size: 57 bytes
//
// 00977990  56                   push esi
// 00977991  33f6                 xor esi, esi
// 00977993  56                   push esi
// 00977994  6a02                 push 2
// 00977996  33c9                 xor ecx, ecx
// 00977998  51                   push ecx
// 00977999  b880476f00           mov eax, 0x6f4780
// 0097799e  50                   push eax
// 0097799f  56                   push esi
// 009779a0  ba60476f00           mov edx, 0x6f4760
// 009779a5  52                   push edx
// 009779a6  6884b09b00           push 0x9bb084
// 009779ab  68a4cd9d00           push 0x9dcda4
// 009779b0  b9b047b900           mov ecx, 0xb947b0
// 009779b5  e84606d8ff           call 0x6f8000
// 009779ba  6860729800           push 0x987260
// 009779bf  e865cfe7ff           call 0x7f4929
// 009779c4  83c404               add esp, 4
// 009779c7  5e                   pop esi
// 009779c8  c3                   ret 

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

static Desc desc("MousePosition", "Data", &Owner::m0, &Owner::m1, 2, 0);
