// from server: 100% by nuck16
// roc 2009-12 00978c30  unit: seg_00970000  size: 57 bytes
//
// 00978c30  56                   push esi
// 00978c31  33f6                 xor esi, esi
// 00978c33  56                   push esi
// 00978c34  6a06                 push 6
// 00978c36  33c9                 xor ecx, ecx
// 00978c38  51                   push ecx
// 00978c39  b880e27100           mov eax, 0x71e280
// 00978c3e  50                   push eax
// 00978c3f  56                   push esi
// 00978c40  ba60725700           mov edx, 0x577260
// 00978c45  52                   push edx
// 00978c46  6884b09b00           push 0x9bb084
// 00978c4b  68a0fc9d00           push 0x9dfca0
// 00978c50  b9885ab900           mov ecx, 0xb95a88
// 00978c55  e88656daff           call 0x71e2e0
// 00978c5a  68c07f9800           push 0x987fc0
// 00978c5f  e8c5bce7ff           call 0x7f4929
// 00978c64  83c404               add esp, 4
// 00978c67  5e                   pop esi
// 00978c68  c3                   ret 

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

static Desc desc("LODX", "Data", &Owner::m0, &Owner::m1, 6, 0);
