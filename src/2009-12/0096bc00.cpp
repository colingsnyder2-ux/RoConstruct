// from server: 100% by nuck16
// roc 2009-12 0096bc00  unit: seg_00960000  size: 57 bytes
//
// 0096bc00  56                   push esi
// 0096bc01  33f6                 xor esi, esi
// 0096bc03  56                   push esi
// 0096bc04  6a0f                 push 0xf
// 0096bc06  33c9                 xor ecx, ecx
// 0096bc08  51                   push ecx
// 0096bc09  b8b0b05000           mov eax, 0x50b0b0
// 0096bc0e  50                   push eax
// 0096bc0f  56                   push esi
// 0096bc10  baa0524f00           mov edx, 0x4f52a0
// 0096bc15  52                   push edx
// 0096bc16  68d8b09b00           push 0x9bb0d8
// 0096bc1b  68ccb09b00           push 0x9bb0cc
// 0096bc20  b980e5b700           mov ecx, 0xb7e580
// 0096bc25  e89647b9ff           call 0x5003c0
// 0096bc2a  68c0f29700           push 0x97f2c0
// 0096bc2f  e8f58ce8ff           call 0x7f4929
// 0096bc34  83c404               add esp, 4
// 0096bc37  5e                   pop esi
// 0096bc38  c3                   ret 

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

static Desc desc("TeamColor", "Team", &Owner::m0, &Owner::m1, 15, 0);
