// from server: 100% by nuck16
// roc 2009-12 009783d0  unit: seg_00970000  size: 57 bytes
//
// 009783d0  56                   push esi
// 009783d1  33f6                 xor esi, esi
// 009783d3  56                   push esi
// 009783d4  6a0f                 push 0xf
// 009783d6  33c9                 xor ecx, ecx
// 009783d8  51                   push ecx
// 009783d9  b8e04d7100           mov eax, 0x714de0
// 009783de  50                   push eax
// 009783df  56                   push esi
// 009783e0  ba50317100           mov edx, 0x713150
// 009783e5  52                   push edx
// 009783e6  6884b09b00           push 0x9bb084
// 009783eb  681ce79d00           push 0x9de71c
// 009783f0  b91055b900           mov ecx, 0xb95510
// 009783f5  e866c0d9ff           call 0x714460
// 009783fa  68607a9800           push 0x987a60
// 009783ff  e825c5e7ff           call 0x7f4929
// 00978404  83c404               add esp, 4
// 00978407  5e                   pop esi
// 00978408  c3                   ret 

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

static Desc desc("GeographicLatitude", "Data", &Owner::m0, &Owner::m1, 15, 0);
