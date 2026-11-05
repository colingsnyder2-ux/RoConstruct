// from server: 100% by nuck16
// roc 2009-12 0097a080  unit: seg_00970000  size: 57 bytes
//
// 0097a080  56                   push esi
// 0097a081  33f6                 xor esi, esi
// 0097a083  56                   push esi
// 0097a084  6a0f                 push 0xf
// 0097a086  33c9                 xor ecx, ecx
// 0097a088  51                   push ecx
// 0097a089  b8f0377400           mov eax, 0x7437f0
// 0097a08e  50                   push eax
// 0097a08f  56                   push esi
// 0097a090  ba20597100           mov edx, 0x715920
// 0097a095  52                   push edx
// 0097a096  6884b09b00           push 0x9bb084
// 0097a09b  68fcf49d00           push 0x9df4fc
// 0097a0a0  b96c6db900           mov ecx, 0xb96d6c
// 0097a0a5  e8b692dcff           call 0x743360
// 0097a0aa  68708e9800           push 0x988e70
// 0097a0af  e875a8e7ff           call 0x7f4929
// 0097a0b4  83c404               add esp, 4
// 0097a0b7  5e                   pop esi
// 0097a0b8  c3                   ret 

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

static Desc desc("MaxVelocity", "Data", &Owner::m0, &Owner::m1, 15, 0);
