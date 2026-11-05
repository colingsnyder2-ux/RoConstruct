// from server: 100% by nuck16
// roc 2009-12 0096bc40  unit: seg_00960000  size: 57 bytes
//
// 0096bc40  56                   push esi
// 0096bc41  33f6                 xor esi, esi
// 0096bc43  56                   push esi
// 0096bc44  6a0f                 push 0xf
// 0096bc46  33c9                 xor ecx, ecx
// 0096bc48  51                   push ecx
// 0096bc49  b8d0b05000           mov eax, 0x50b0d0
// 0096bc4e  50                   push eax
// 0096bc4f  56                   push esi
// 0096bc50  baa08c7400           mov edx, 0x748ca0
// 0096bc55  52                   push edx
// 0096bc56  68d8b09b00           push 0x9bb0d8
// 0096bc5b  68e0b09b00           push 0x9bb0e0
// 0096bc60  b908e8b700           mov ecx, 0xb7e808
// 0096bc65  e80648b9ff           call 0x500470
// 0096bc6a  68a0f29700           push 0x97f2a0
// 0096bc6f  e8b58ce8ff           call 0x7f4929
// 0096bc74  83c404               add esp, 4
// 0096bc77  5e                   pop esi
// 0096bc78  c3                   ret 

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

static Desc desc("Neutral", "Team", &Owner::m0, &Owner::m1, 15, 0);
