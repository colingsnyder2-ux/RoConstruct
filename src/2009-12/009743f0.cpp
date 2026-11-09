// from server: 100% by nuck16
// roc 2009-12 009743f0  unit: seg_00970000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009743f0
//
// 009743f0  33c9                 xor ecx, ecx
// 009743f2  51                   push ecx
// 009743f3  6a09                 push 9
// 009743f5  51                   push ecx
// 009743f6  51                   push ecx
// 009743f7  b850396b00           mov eax, 0x6b3950
// 009743fc  50                   push eax
// 009743fd  6884b09b00           push 0x9bb084
// 00974402  6870669d00           push 0x9d6670
// 00974407  b9c81ab900           mov ecx, 0xb91ac8
// 0097440c  e83f28d4ff           call 0x6b6c50
// 00974411  6810579800           push 0x985710
// 00974416  e80e05e8ff           call 0x7f4929
// 0097441b  59                   pop ecx
// 0097441c  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

struct Desc
{
    Desc(const char *, const char *, void (Owner::*)(), int, int, int);
    ~Desc();
};

static Desc desc("IsPaused", "Data", &Owner::m0, 0, 9, 0);
