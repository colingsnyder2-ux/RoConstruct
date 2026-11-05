// from server: 100% by nuck16
// roc 2009-12 00974840  unit: seg_00970000  size: 57 bytes
//
// 00974840  56                   push esi
// 00974841  33f6                 xor esi, esi
// 00974843  56                   push esi
// 00974844  6a0f                 push 0xf
// 00974846  33c9                 xor ecx, ecx
// 00974848  51                   push ecx
// 00974849  b8f05f6c00           mov eax, 0x6c5ff0
// 0097484e  50                   push eax
// 0097484f  56                   push esi
// 00974850  ba505c6c00           mov edx, 0x6c5c50
// 00974855  52                   push edx
// 00974856  6810719d00           push 0x9d7110
// 0097485b  6818719d00           push 0x9d7118
// 00974860  b93c24b900           mov ecx, 0xb9243c
// 00974865  e83616d5ff           call 0x6c5ea0
// 0097486a  68405b9800           push 0x985b40
// 0097486f  e8b500e8ff           call 0x7f4929
// 00974874  83c404               add esp, 4
// 00974877  5e                   pop esi
// 00974878  c3                   ret 

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

static Desc desc("ArePartCoordsShown", "Display", &Owner::m0, &Owner::m1, 15, 0);
