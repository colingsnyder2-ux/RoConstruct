// from server: 100% by nuck16
// roc 2009-12 0096c5c0  unit: seg_00960000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c5c0
//
// 0096c5c0  33c9                 xor ecx, ecx
// 0096c5c2  51                   push ecx
// 0096c5c3  68c0b89b00           push 0x9bb8c0
// 0096c5c8  51                   push ecx
// 0096c5c9  b840734700           mov eax, 0x477340
// 0096c5ce  50                   push eax
// 0096c5cf  b9a8ebb700           mov ecx, 0xb7eba8
// 0096c5d4  e8670cbbff           call 0x51d240
// 0096c5d9  6850fc9700           push 0x97fc50
// 0096c5de  e84683e8ff           call 0x7f4929
// 0096c5e3  59                   pop ecx
// 0096c5e4  c3                   ret 

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

static Desc desc(&Owner::m0, "players", 0);
