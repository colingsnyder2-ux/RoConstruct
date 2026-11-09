// from server: 100% by nuck16
// roc 2009-12 0096c5f0  unit: seg_00960000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c5f0
//
// 0096c5f0  33c9                 xor ecx, ecx
// 0096c5f2  51                   push ecx
// 0096c5f3  68c8b89b00           push 0x9bb8c8
// 0096c5f8  51                   push ecx
// 0096c5f9  b840734700           mov eax, 0x477340
// 0096c5fe  50                   push eax
// 0096c5ff  b958edb700           mov ecx, 0xb7ed58
// 0096c604  e8370cbbff           call 0x51d240
// 0096c609  6890fb9700           push 0x97fb90
// 0096c60e  e81683e8ff           call 0x7f4929
// 0096c613  59                   pop ecx
// 0096c614  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "GetPlayers", 0);
