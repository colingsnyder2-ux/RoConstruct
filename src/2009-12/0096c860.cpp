// from server: 100% by nuck16
// roc 2009-12 0096c860  unit: seg_00960000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c860
//
// 0096c860  33c9                 xor ecx, ecx
// 0096c862  51                   push ecx
// 0096c863  6a0f                 push 0xf
// 0096c865  51                   push ecx
// 0096c866  51                   push ecx
// 0096c867  b8f0225100           mov eax, 0x5122f0
// 0096c86c  50                   push eax
// 0096c86d  6884b09b00           push 0x9bb084
// 0096c872  68bcb99b00           push 0x9bb9bc
// 0096c877  b968ebb700           mov ecx, 0xb7eb68
// 0096c87c  e84fdebaff           call 0x51a6d0
// 0096c881  6830fb9700           push 0x97fb30
// 0096c886  e89e80e8ff           call 0x7f4929
// 0096c88b  59                   pop ecx
// 0096c88c  c3                   ret 

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
    Desc(const char *, const char *, void (Owner::*)(), int, int, int);
    ~Desc();
};

static Desc desc("BubbleChat", "Data", &Owner::m0, 0, 15, 0);
