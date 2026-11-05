// from server: 100% by nuck16
// roc 2009-12 0096cf90  unit: seg_00960000  size: 57 bytes
//
// 0096cf90  56                   push esi
// 0096cf91  33f6                 xor esi, esi
// 0096cf93  56                   push esi
// 0096cf94  6a0f                 push 0xf
// 0096cf96  33c9                 xor ecx, ecx
// 0096cf98  51                   push ecx
// 0096cf99  b8609d5200           mov eax, 0x529d60
// 0096cf9e  50                   push eax
// 0096cf9f  56                   push esi
// 0096cfa0  bad08a5200           mov edx, 0x528ad0
// 0096cfa5  52                   push edx
// 0096cfa6  68b8c39b00           push 0x9bc3b8
// 0096cfab  6844c59b00           push 0x9bc544
// 0096cfb0  b9f8feb700           mov ecx, 0xb7fef8
// 0096cfb5  e8d6c3bbff           call 0x529390
// 0096cfba  6810039800           push 0x980310
// 0096cfbf  e86579e8ff           call 0x7f4929
// 0096cfc4  83c404               add esp, 4
// 0096cfc7  5e                   pop esi
// 0096cfc8  c3                   ret 

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

static Desc desc("ReceiveRate", "Network", &Owner::m0, &Owner::m1, 15, 0);
