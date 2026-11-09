// from server: 100% by nuck16
// roc 2009-12 009742c0  unit: seg_00970000  size: 57 bytes
//
// 009742c0  56                   push esi
// 009742c1  33f6                 xor esi, esi
// 009742c3  56                   push esi
// 009742c4  6a0f                 push 0xf
// 009742c6  33c9                 xor ecx, ecx
// 009742c8  51                   push ecx
// 009742c9  b850946b00           mov eax, 0x6b9450
// 009742ce  50                   push eax
// 009742cf  56                   push esi
// 009742d0  bae0396b00           mov edx, 0x6b39e0
// 009742d5  52                   push edx
// 009742d6  6884b09b00           push 0x9bb084
// 009742db  6840669d00           push 0x9d6640
// 009742e0  b9781cb900           mov ecx, 0xb91c78
// 009742e5  e85627d4ff           call 0x6b6a40
// 009742ea  6850569800           push 0x985650
// 009742ef  e83506e8ff           call 0x7f4929
// 009742f4  83c404               add esp, 4
// 009742f7  5e                   pop esi
// 009742f8  c3                   ret 

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

static Desc desc("Volume", "Data", &Owner::m0, &Owner::m1, 15, 0);
