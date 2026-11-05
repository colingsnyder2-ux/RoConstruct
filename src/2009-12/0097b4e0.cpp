// from server: 100% by nuck16
// roc 2009-12 0097b4e0  unit: seg_00970000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b4e0
//
// 0097b4e0  33c9                 xor ecx, ecx
// 0097b4e2  51                   push ecx
// 0097b4e3  68207b9e00           push 0x9e7b20
// 0097b4e8  68a0b09b00           push 0x9bb0a0
// 0097b4ed  68107b9e00           push 0x9e7b10
// 0097b4f2  51                   push ecx
// 0097b4f3  b8e0607600           mov eax, 0x7660e0
// 0097b4f8  50                   push eax
// 0097b4f9  b9607cb900           mov ecx, 0xb97c60
// 0097b4fe  e88d7fdeff           call 0x763490
// 0097b503  68e0999800           push 0x9899e0
// 0097b508  e81c94e7ff           call 0x7f4929
// 0097b50d  59                   pop ecx
// 0097b50e  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

struct Desc
{
    Desc(void (Owner::*)(), const char *, const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "UserHasBadge", "userId", "badgeId", 0);
