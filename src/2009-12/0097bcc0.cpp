// from server: 100% by nuck16
// roc 2009-12 0097bcc0  unit: seg_00970000  size: 57 bytes
//
// 0097bcc0  56                   push esi
// 0097bcc1  33f6                 xor esi, esi
// 0097bcc3  56                   push esi
// 0097bcc4  6a0f                 push 0xf
// 0097bcc6  33c9                 xor ecx, ecx
// 0097bcc8  51                   push ecx
// 0097bcc9  b820fe7600           mov eax, 0x76fe20
// 0097bcce  50                   push eax
// 0097bccf  56                   push esi
// 0097bcd0  ba20cf7600           mov edx, 0x76cf20
// 0097bcd5  52                   push edx
// 0097bcd6  6884b09b00           push 0x9bb084
// 0097bcdb  6864899e00           push 0x9e8964
// 0097bce0  b9d086b900           mov ecx, 0xb986d0
// 0097bce5  e8a62bdfff           call 0x76e890
// 0097bcea  6810a09800           push 0x98a010
// 0097bcef  e8358ce7ff           call 0x7f4929
// 0097bcf4  83c404               add esp, 4
// 0097bcf7  5e                   pop esi
// 0097bcf8  c3                   ret 

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

static Desc desc("BorderColor3", "Data", &Owner::m0, &Owner::m1, 15, 0);
