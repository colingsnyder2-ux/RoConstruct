// from server: 100% by nuck16
// roc 2009-12 0097a310  unit: seg_00970000  size: 57 bytes
//
// 0097a310  56                   push esi
// 0097a311  33f6                 xor esi, esi
// 0097a313  56                   push esi
// 0097a314  6a0f                 push 0xf
// 0097a316  33c9                 xor ecx, ecx
// 0097a318  51                   push ecx
// 0097a319  b8108d7400           mov eax, 0x748d10
// 0097a31e  50                   push eax
// 0097a31f  56                   push esi
// 0097a320  ba80747400           mov edx, 0x747480
// 0097a325  52                   push edx
// 0097a326  68dc1f9d00           push 0x9d1fdc
// 0097a32b  6844a29d00           push 0x9da244
// 0097a330  b93c6fb900           mov ecx, 0xb96f3c
// 0097a335  e856eadcff           call 0x748d90
// 0097a33a  68108f9800           push 0x988f10
// 0097a33f  e8e5a5e7ff           call 0x7f4929
// 0097a344  83c404               add esp, 4
// 0097a347  5e                   pop esi
// 0097a348  c3                   ret 

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

static Desc desc("Style", "Appearance", &Owner::m0, &Owner::m1, 15, 0);
