// from server: 100% by nuck16
// roc 2009-12 00974240  unit: seg_00970000  size: 57 bytes
//
// 00974240  56                   push esi
// 00974241  33f6                 xor esi, esi
// 00974243  56                   push esi
// 00974244  6a0f                 push 0xf
// 00974246  33c9                 xor ecx, ecx
// 00974248  51                   push ecx
// 00974249  b850926b00           mov eax, 0x6b9250
// 0097424e  50                   push eax
// 0097424f  56                   push esi
// 00974250  bac0488600           mov edx, 0x8648c0
// 00974255  52                   push edx
// 00974256  6884b09b00           push 0x9bb084
// 0097425b  6828669d00           push 0x9d6628
// 00974260  b9501cb900           mov ecx, 0xb91c50
// 00974265  e84639d4ff           call 0x6b7bb0
// 0097426a  6870569800           push 0x985670
// 0097426f  e8b506e8ff           call 0x7f4929
// 00974274  83c404               add esp, 4
// 00974277  5e                   pop esi
// 00974278  c3                   ret 

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

static Desc desc("AmbientReverb", "Data", &Owner::m0, &Owner::m1, 15, 0);
