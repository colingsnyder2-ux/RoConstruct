// from server: 100% by nuck16
// roc 2009-12 00977950  unit: seg_00970000  size: 57 bytes
//
// 00977950  56                   push esi
// 00977951  33f6                 xor esi, esi
// 00977953  56                   push esi
// 00977954  6a02                 push 2
// 00977956  33c9                 xor ecx, ecx
// 00977958  51                   push ecx
// 00977959  b8d0916f00           mov eax, 0x6f91d0
// 0097795e  50                   push eax
// 0097795f  56                   push esi
// 00977960  ba50476f00           mov edx, 0x6f4750
// 00977965  52                   push edx
// 00977966  6884b09b00           push 0x9bb084
// 0097796b  68a09b9d00           push 0x9d9ba0
// 00977970  b97047b900           mov ecx, 0xb94770
// 00977975  e8d605d8ff           call 0x6f7f50
// 0097797a  6880729800           push 0x987280
// 0097797f  e8a5cfe7ff           call 0x7f4929
// 00977984  83c404               add esp, 4
// 00977987  5e                   pop esi
// 00977988  c3                   ret 

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

static Desc desc("EnableReplication", "Data", &Owner::m0, &Owner::m1, 2, 0);
