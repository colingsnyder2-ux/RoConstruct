// from server: 100% by nuck16
// roc 2009-12 0097a240  unit: seg_00970000  size: 57 bytes
//
// 0097a240  56                   push esi
// 0097a241  33f6                 xor esi, esi
// 0097a243  56                   push esi
// 0097a244  6a0f                 push 0xf
// 0097a246  33c9                 xor ecx, ecx
// 0097a248  51                   push ecx
// 0097a249  b8d0477400           mov eax, 0x7447d0
// 0097a24e  50                   push eax
// 0097a24f  56                   push esi
// 0097a250  bac0417400           mov edx, 0x7441c0
// 0097a255  52                   push edx
// 0097a256  6884b09b00           push 0x9bb084
// 0097a25b  68ccb09b00           push 0x9bb0cc
// 0097a260  b9386eb900           mov ecx, 0xb96e38
// 0097a265  e876a3dcff           call 0x7445e0
// 0097a26a  68908e9800           push 0x988e90
// 0097a26f  e8b5a6e7ff           call 0x7f4929
// 0097a274  83c404               add esp, 4
// 0097a277  5e                   pop esi
// 0097a278  c3                   ret 

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

static Desc desc("TeamColor", "Data", &Owner::m0, &Owner::m1, 15, 0);
