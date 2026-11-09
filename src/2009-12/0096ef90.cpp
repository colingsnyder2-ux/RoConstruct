// from server: 100% by nuck16
// roc 2009-12 0096ef90  unit: seg_00960000  size: 57 bytes
//
// 0096ef90  56                   push esi
// 0096ef91  33f6                 xor esi, esi
// 0096ef93  56                   push esi
// 0096ef94  6a0f                 push 0xf
// 0096ef96  33c9                 xor ecx, ecx
// 0096ef98  51                   push ecx
// 0096ef99  b820d96300           mov eax, 0x63d920
// 0096ef9e  50                   push eax
// 0096ef9f  56                   push esi
// 0096efa0  ba80d26300           mov edx, 0x63d280
// 0096efa5  52                   push edx
// 0096efa6  6884b09b00           push 0x9bb084
// 0096efab  68c8c59c00           push 0x9cc5c8
// 0096efb0  b9ec5ab800           mov ecx, 0xb85aec
// 0096efb5  e866e5ccff           call 0x63d520
// 0096efba  68201d9800           push 0x981d20
// 0096efbf  e86559e8ff           call 0x7f4929
// 0096efc4  83c404               add esp, 4
// 0096efc7  5e                   pop esi
// 0096efc8  c3                   ret 

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

static Desc desc("Score", "Data", &Owner::m0, &Owner::m1, 15, 0);
