// from server: 100% by nuck16
// roc 2009-12 00978390  unit: seg_00970000  size: 57 bytes
//
// 00978390  56                   push esi
// 00978391  33f6                 xor esi, esi
// 00978393  56                   push esi
// 00978394  6a0f                 push 0xf
// 00978396  33c9                 xor ecx, ecx
// 00978398  51                   push ecx
// 00978399  b890517100           mov eax, 0x715190
// 0097839e  50                   push eax
// 0097839f  56                   push esi
// 009783a0  ba803c7100           mov edx, 0x713c80
// 009783a5  52                   push edx
// 009783a6  6884b09b00           push 0x9bb084
// 009783ab  6810e79d00           push 0x9de710
// 009783b0  b92854b900           mov ecx, 0xb95428
// 009783b5  e8f6bfd9ff           call 0x7143b0
// 009783ba  68807a9800           push 0x987a80
// 009783bf  e865c5e7ff           call 0x7f4929
// 009783c4  83c404               add esp, 4
// 009783c7  5e                   pop esi
// 009783c8  c3                   ret 

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

static Desc desc("TimeOfDay", "Data", &Owner::m0, &Owner::m1, 15, 0);
