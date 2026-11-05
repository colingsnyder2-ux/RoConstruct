// from server: 100% by nuck16
// roc 2009-12 00978c70  unit: seg_00970000  size: 57 bytes
//
// 00978c70  56                   push esi
// 00978c71  33f6                 xor esi, esi
// 00978c73  56                   push esi
// 00978c74  6a06                 push 6
// 00978c76  33c9                 xor ecx, ecx
// 00978c78  51                   push ecx
// 00978c79  b8b0e27100           mov eax, 0x71e2b0
// 00978c7e  50                   push eax
// 00978c7f  56                   push esi
// 00978c80  ba70725700           mov edx, 0x577270
// 00978c85  52                   push edx
// 00978c86  6884b09b00           push 0x9bb084
// 00978c8b  68a8fc9d00           push 0x9dfca8
// 00978c90  b9d85ab900           mov ecx, 0xb95ad8
// 00978c95  e84656daff           call 0x71e2e0
// 00978c9a  68a07f9800           push 0x987fa0
// 00978c9f  e885bce7ff           call 0x7f4929
// 00978ca4  83c404               add esp, 4
// 00978ca7  5e                   pop esi
// 00978ca8  c3                   ret 

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

static Desc desc("LODY", "Data", &Owner::m0, &Owner::m1, 6, 0);
