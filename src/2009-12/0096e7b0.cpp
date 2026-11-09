// from server: 100% by nuck16
// roc 2009-12 0096e7b0  unit: seg_00960000  size: 57 bytes
//
// 0096e7b0  56                   push esi
// 0096e7b1  33f6                 xor esi, esi
// 0096e7b3  56                   push esi
// 0096e7b4  6a0f                 push 0xf
// 0096e7b6  33c9                 xor ecx, ecx
// 0096e7b8  51                   push ecx
// 0096e7b9  b840166300           mov eax, 0x631640
// 0096e7be  50                   push eax
// 0096e7bf  56                   push esi
// 0096e7c0  ba70bd6200           mov edx, 0x62bd70
// 0096e7c5  52                   push edx
// 0096e7c6  6820a79b00           push 0x9ba720
// 0096e7cb  68e8b39c00           push 0x9cb3e8
// 0096e7d0  b9884eb800           mov ecx, 0xb84e88
// 0096e7d5  e8f633ccff           call 0x631bd0
// 0096e7da  6880149800           push 0x981480
// 0096e7df  e84561e8ff           call 0x7f4929
// 0096e7e4  83c404               add esp, 4
// 0096e7e7  5e                   pop esi
// 0096e7e8  c3                   ret 

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

static Desc desc("SleepAdjustMethod", "Configuration", &Owner::m0, &Owner::m1, 15, 0);
