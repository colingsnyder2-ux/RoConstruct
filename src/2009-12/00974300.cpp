// from server: 100% by nuck16
// roc 2009-12 00974300  unit: seg_00970000  size: 57 bytes
//
// 00974300  56                   push esi
// 00974301  33f6                 xor esi, esi
// 00974303  56                   push esi
// 00974304  6a0f                 push 0xf
// 00974306  33c9                 xor ecx, ecx
// 00974308  51                   push ecx
// 00974309  b8d0946b00           mov eax, 0x6b94d0
// 0097430e  50                   push eax
// 0097430f  56                   push esi
// 00974310  baf0396b00           mov edx, 0x6b39f0
// 00974315  52                   push edx
// 00974316  6884b09b00           push 0x9bb084
// 0097431b  6848669d00           push 0x9d6648
// 00974320  b9281bb900           mov ecx, 0xb91b28
// 00974325  e81627d4ff           call 0x6b6a40
// 0097432a  6830569800           push 0x985630
// 0097432f  e8f505e8ff           call 0x7f4929
// 00974334  83c404               add esp, 4
// 00974337  5e                   pop esi
// 00974338  c3                   ret 

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

static Desc desc("Pitch", "Data", &Owner::m0, &Owner::m1, 15, 0);
