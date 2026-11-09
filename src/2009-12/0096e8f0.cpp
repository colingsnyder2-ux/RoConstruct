// from server: 100% by nuck16
// roc 2009-12 0096e8f0  unit: seg_00960000  size: 57 bytes
//
// 0096e8f0  56                   push esi
// 0096e8f1  33f6                 xor esi, esi
// 0096e8f3  56                   push esi
// 0096e8f4  6a0f                 push 0xf
// 0096e8f6  33c9                 xor ecx, ecx
// 0096e8f8  51                   push ecx
// 0096e8f9  b8d0bc6200           mov eax, 0x62bcd0
// 0096e8fe  50                   push eax
// 0096e8ff  56                   push esi
// 0096e900  bac0bc6200           mov edx, 0x62bcc0
// 0096e905  52                   push edx
// 0096e906  6818bc9c00           push 0x9cbc18
// 0096e90b  6828bc9c00           push 0x9cbc28
// 0096e910  b9144cb800           mov ecx, 0xb84c14
// 0096e915  e89633ccff           call 0x631cb0
// 0096e91a  6800149800           push 0x981400
// 0096e91f  e80560e8ff           call 0x7f4929
// 0096e924  83c404               add esp, 4
// 0096e927  5e                   pop esi
// 0096e928  c3                   ret 

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

static Desc desc("TickCountPreciseOverride", "Benchmarking", &Owner::m0, &Owner::m1, 15, 0);
