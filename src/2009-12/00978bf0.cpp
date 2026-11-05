// from server: 100% by nuck16
// roc 2009-12 00978bf0  unit: seg_00970000  size: 57 bytes
//
// 00978bf0  56                   push esi
// 00978bf1  33f6                 xor esi, esi
// 00978bf3  56                   push esi
// 00978bf4  6a06                 push 6
// 00978bf6  33c9                 xor ecx, ecx
// 00978bf8  51                   push ecx
// 00978bf9  b8e0d07100           mov eax, 0x71d0e0
// 00978bfe  50                   push eax
// 00978bff  56                   push esi
// 00978c00  ba90294b00           mov edx, 0x4b2990
// 00978c05  52                   push edx
// 00978c06  6884b09b00           push 0x9bb084
// 00978c0b  6898fa9d00           push 0x9dfa98
// 00978c10  b9f459b900           mov ecx, 0xb959f4
// 00978c15  e86643daff           call 0x71cf80
// 00978c1a  68407f9800           push 0x987f40
// 00978c1f  e805bde7ff           call 0x7f4929
// 00978c24  83c404               add esp, 4
// 00978c27  5e                   pop esi
// 00978c28  c3                   ret 

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

static Desc desc("Bulge", "Data", &Owner::m0, &Owner::m1, 6, 0);
