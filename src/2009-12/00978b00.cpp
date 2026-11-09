// from server: 100% by nuck16
// roc 2009-12 00978b00  unit: seg_00970000  size: 57 bytes
//
// 00978b00  56                   push esi
// 00978b01  33f6                 xor esi, esi
// 00978b03  56                   push esi
// 00978b04  6a0f                 push 0xf
// 00978b06  33c9                 xor ecx, ecx
// 00978b08  51                   push ecx
// 00978b09  b8d0c87100           mov eax, 0x71c8d0
// 00978b0e  50                   push eax
// 00978b0f  56                   push esi
// 00978b10  ba104e5700           mov edx, 0x574e10
// 00978b15  52                   push edx
// 00978b16  68dc1f9d00           push 0x9d1fdc
// 00978b1b  6810f99d00           push 0x9df910
// 00978b20  b92059b900           mov ecx, 0xb95920
// 00978b25  e8c636daff           call 0x71c1f0
// 00978b2a  68207f9800           push 0x987f20
// 00978b2f  e8f5bde7ff           call 0x7f4929
// 00978b34  83c404               add esp, 4
// 00978b37  5e                   pop esi
// 00978b38  c3                   ret 

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

static Desc desc("StarCount", "Appearance", &Owner::m0, &Owner::m1, 15, 0);
