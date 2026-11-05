// from server: 100% by nuck16
// roc 2009-12 0097b510  unit: seg_00970000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b510
//
// 0097b510  33c9                 xor ecx, ecx
// 0097b512  51                   push ecx
// 0097b513  68207b9e00           push 0x9e7b20
// 0097b518  68a0b09b00           push 0x9bb0a0
// 0097b51d  68287b9e00           push 0x9e7b28
// 0097b522  51                   push ecx
// 0097b523  b860707600           mov eax, 0x767060
// 0097b528  50                   push eax
// 0097b529  b9f87cb900           mov ecx, 0xb97cf8
// 0097b52e  e85d7fdeff           call 0x763490
// 0097b533  68b0999800           push 0x9899b0
// 0097b538  e8ec93e7ff           call 0x7f4929
// 0097b53d  59                   pop ecx
// 0097b53e  c3                   ret 

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

static Desc desc(&Owner::m0, "AwardBadge", "userId", "badgeId", 0);
