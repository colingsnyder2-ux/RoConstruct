// from server: 100% by nuck16
// roc 2009-12 00978320  unit: seg_00970000  size: 57 bytes
//
// 00978320  56                   push esi
// 00978321  33f6                 xor esi, esi
// 00978323  56                   push esi
// 00978324  6a0f                 push 0xf
// 00978326  33c9                 xor ecx, ecx
// 00978328  51                   push ecx
// 00978329  b8402c7100           mov eax, 0x712c40
// 0097832e  50                   push eax
// 0097832f  56                   push esi
// 00978330  bab0247100           mov edx, 0x7124b0
// 00978335  52                   push edx
// 00978336  68dc1f9d00           push 0x9d1fdc
// 0097833b  6860e49d00           push 0x9de460
// 00978340  b98c53b900           mov ecx, 0xb9538c
// 00978345  e876a7d9ff           call 0x712ac0
// 0097834a  68c0799800           push 0x9879c0
// 0097834f  e8d5c5e7ff           call 0x7f4929
// 00978354  83c404               add esp, 4
// 00978357  5e                   pop esi
// 00978358  c3                   ret 

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

static Desc desc("Text", "Appearance", &Owner::m0, &Owner::m1, 15, 0);
