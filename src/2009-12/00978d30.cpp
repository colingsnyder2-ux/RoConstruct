// from server: 100% by nuck16
// roc 2009-12 00978d30  unit: seg_00970000  size: 57 bytes
//
// 00978d30  56                   push esi
// 00978d31  33f6                 xor esi, esi
// 00978d33  56                   push esi
// 00978d34  6a0f                 push 0xf
// 00978d36  33c9                 xor ecx, ecx
// 00978d38  51                   push ecx
// 00978d39  b810e27100           mov eax, 0x71e210
// 00978d3e  50                   push eax
// 00978d3f  56                   push esi
// 00978d40  ba90725700           mov edx, 0x577290
// 00978d45  52                   push edx
// 00978d46  6884b09b00           push 0x9bb084
// 00978d4b  684c869a00           push 0x9a864c
// 00978d50  b9b05ab900           mov ecx, 0xb95ab0
// 00978d55  e84650daff           call 0x71dda0
// 00978d5a  68e07f9800           push 0x987fe0
// 00978d5f  e8c5bbe7ff           call 0x7f4929
// 00978d64  83c404               add esp, 4
// 00978d67  5e                   pop esi
// 00978d68  c3                   ret 

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

static Desc desc("Offset", "Data", &Owner::m0, &Owner::m1, 15, 0);
