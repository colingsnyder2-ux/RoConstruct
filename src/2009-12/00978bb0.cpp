// from server: 100% by nuck16
// roc 2009-12 00978bb0  unit: seg_00970000  size: 57 bytes
//
// 00978bb0  56                   push esi
// 00978bb1  33f6                 xor esi, esi
// 00978bb3  56                   push esi
// 00978bb4  6a06                 push 6
// 00978bb6  33c9                 xor ecx, ecx
// 00978bb8  51                   push ecx
// 00978bb9  b8c0d07100           mov eax, 0x71d0c0
// 00978bbe  50                   push eax
// 00978bbf  56                   push esi
// 00978bc0  baf0396b00           mov edx, 0x6b39f0
// 00978bc5  52                   push edx
// 00978bc6  6884b09b00           push 0x9bb084
// 00978bcb  6888fa9d00           push 0x9dfa88
// 00978bd0  b9145ab900           mov ecx, 0xb95a14
// 00978bd5  e8a643daff           call 0x71cf80
// 00978bda  68607f9800           push 0x987f60
// 00978bdf  e845bde7ff           call 0x7f4929
// 00978be4  83c404               add esp, 4
// 00978be7  5e                   pop esi
// 00978be8  c3                   ret 

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

static Desc desc("Bevel Roundness", "Data", &Owner::m0, &Owner::m1, 6, 0);
