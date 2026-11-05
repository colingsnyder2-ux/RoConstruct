// from server: 100% by nuck16
// roc 2009-12 0096cfd0  unit: seg_00960000  size: 57 bytes
//
// 0096cfd0  56                   push esi
// 0096cfd1  33f6                 xor esi, esi
// 0096cfd3  56                   push esi
// 0096cfd4  6a0f                 push 0xf
// 0096cfd6  33c9                 xor ecx, ecx
// 0096cfd8  51                   push ecx
// 0096cfd9  b8309e5200           mov eax, 0x529e30
// 0096cfde  50                   push eax
// 0096cfdf  56                   push esi
// 0096cfe0  ba208b5200           mov edx, 0x528b20
// 0096cfe5  52                   push edx
// 0096cfe6  68b8c39b00           push 0x9bc3b8
// 0096cfeb  6850c59b00           push 0x9bc550
// 0096cff0  b978feb700           mov ecx, 0xb7fe78
// 0096cff5  e896c3bbff           call 0x529390
// 0096cffa  68f0029800           push 0x9802f0
// 0096cfff  e82579e8ff           call 0x7f4929
// 0096d004  83c404               add esp, 4
// 0096d007  5e                   pop esi
// 0096d008  c3                   ret 

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

static Desc desc("NextActionMultiplier", "Network", &Owner::m0, &Owner::m1, 15, 0);
