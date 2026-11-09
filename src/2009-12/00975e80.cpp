// from server: 100% by nuck16
// roc 2009-12 00975e80  unit: seg_00970000  size: 57 bytes
//
// 00975e80  56                   push esi
// 00975e81  33f6                 xor esi, esi
// 00975e83  56                   push esi
// 00975e84  6a0f                 push 0xf
// 00975e86  33c9                 xor ecx, ecx
// 00975e88  51                   push ecx
// 00975e89  b8702e6e00           mov eax, 0x6e2e70
// 00975e8e  50                   push eax
// 00975e8f  56                   push esi
// 00975e90  ba20004c00           mov edx, 0x4c0020
// 00975e95  52                   push edx
// 00975e96  6884b09b00           push 0x9bb084
// 00975e9b  68b8409a00           push 0x9a40b8
// 00975ea0  b91435b900           mov ecx, 0xb93514
// 00975ea5  e856cdd6ff           call 0x6e2c00
// 00975eaa  6830659800           push 0x986530
// 00975eaf  e875eae7ff           call 0x7f4929
// 00975eb4  83c404               add esp, 4
// 00975eb7  5e                   pop esi
// 00975eb8  c3                   ret 

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

static Desc desc("Color", "Data", &Owner::m0, &Owner::m1, 15, 0);
