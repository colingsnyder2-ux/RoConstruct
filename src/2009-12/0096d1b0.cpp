// from server: 100% by nuck16
// roc 2009-12 0096d1b0  unit: seg_00960000  size: 57 bytes
//
// 0096d1b0  56                   push esi
// 0096d1b1  33f6                 xor esi, esi
// 0096d1b3  56                   push esi
// 0096d1b4  6a0f                 push 0xf
// 0096d1b6  33c9                 xor ecx, ecx
// 0096d1b8  51                   push ecx
// 0096d1b9  b8009e5200           mov eax, 0x529e00
// 0096d1be  50                   push eax
// 0096d1bf  56                   push esi
// 0096d1c0  ba10478100           mov edx, 0x814710
// 0096d1c5  52                   push edx
// 0096d1c6  680cc69b00           push 0x9bc60c
// 0096d1cb  6814c69b00           push 0x9bc614
// 0096d1d0  b918ffb700           mov ecx, 0xb7ff18
// 0096d1d5  e8f6d0bbff           call 0x52a2d0
// 0096d1da  6810029800           push 0x980210
// 0096d1df  e84577e8ff           call 0x7f4929
// 0096d1e4  83c404               add esp, 4
// 0096d1e7  5e                   pop esi
// 0096d1e8  c3                   ret 

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

static Desc desc("PhysicsReceive", "Physics", &Owner::m0, &Owner::m1, 15, 0);
